#include <SoftwareSerial.h>
#include <DHT.h>

// ----- Pin Definitions -----
#define DHTPIN 2              // DHT11 data pin connected to digital pin 2
#define DHTTYPE DHT11         // DHT11 sensor type
#define SOIL_MOISTURE_PIN A0  // Soil moisture sensor analog pin
#define RELAY_PIN 8           // Relay module connected to digital pin 8
#define BT_RX 10              // Bluetooth module TX -> Arduino RX (pin 10)
#define BT_TX 11              // Bluetooth module RX -> Arduino TX (pin 11)

// ----- Thresholds -----
#define SOIL_DRY_THRESHOLD 500 // You may need to calibrate this value

// ----- Global Variables -----
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial bluetooth(BT_RX, BT_TX); // RX, TX

bool pumpOn = false;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump OFF initially

  Serial.println("SmartGrow-BluetoothIrrigator Started!");
  bluetooth.println("SmartGrow-BluetoothIrrigator Ready.");
}

void loop() {
  // 1. Automatic watering based on soil moisture
  int soilValue = analogRead(SOIL_MOISTURE_PIN);
  bool soilDry = (soilValue > SOIL_DRY_THRESHOLD);

  // If soil is dry, and pump is not on (manual override), turn pump on
  if (soilDry && !pumpOn) {
    digitalWrite(RELAY_PIN, HIGH);
    pumpOn = true;
    Serial.println("Soil dry. Pump ON.");
    bluetooth.println("Soil dry. Pump ON.");
  }
  // If soil is wet, and pump is on due to auto, turn pump off
  if (!soilDry && pumpOn) {
    digitalWrite(RELAY_PIN, LOW);
    pumpOn = false;
    Serial.println("Soil wet. Pump OFF.");
    bluetooth.println("Soil wet. Pump OFF.");
  }

  // 2. Check for Bluetooth commands
  if (bluetooth.available()) {
    String cmd = bluetooth.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    if (cmd == "ON") {
      digitalWrite(RELAY_PIN, HIGH);
      pumpOn = true;
      bluetooth.println("Pump turned ON (Manual).");
      Serial.println("Pump turned ON (Manual).");
    } else if (cmd == "OFF") {
      digitalWrite(RELAY_PIN, LOW);
      pumpOn = false;
      bluetooth.println("Pump turned OFF (Manual).");
      Serial.println("Pump turned OFF (Manual).");
    } else if (cmd == "DATA") {
      float temp = dht.readTemperature();
      float hum = dht.readHumidity();
      int soil = analogRead(SOIL_MOISTURE_PIN);
      bluetooth.print("Temp: ");
      bluetooth.print(temp);
      bluetooth.print(" C, Humidity: ");
      bluetooth.print(hum);
      bluetooth.print(" %, Soil: ");
      bluetooth.print(soil);
      bluetooth.println();
      Serial.print("DATA sent: T=");
      Serial.print(temp);
      Serial.print("C, H=");
      Serial.print(hum);
      Serial.print("%, Soil=");
      Serial.println(soil);
    } else {
      bluetooth.println("Unknown command. Try ON, OFF, DATA.");
    }
  }

  delay(1500); // Reasonable polling delay
}
