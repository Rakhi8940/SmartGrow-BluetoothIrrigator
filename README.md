<p align="center">
  <img src="https://github.com/user-attachments/assets/8d1b1a2b-ff4d-456a-985f-1c6b947a4851" width="900" alt="SmartGrow-BluetoothIrrigator Banner" style="margin: 12px 0; border-radius: 18px; background: #fff; box-shadow: 0 4px 16px rgba(0,0,0,0.12); padding: 0;">
</p>

# 🌱 SmartGrow-BluetoothIrrigator

A Bluetooth-enabled, automated plant watering system!  
**SmartGrow-BluetoothIrrigator** uses an Arduino Uno, DHT11, soil moisture sensor, relay, DC pump, and a Bluetooth module to keep your plants healthy and hydrated — all controllable from your smartphone.

---

## 🎯 Objective

- Automatically water plants based on real-time soil moisture readings.
- Enable manual or scheduled watering via Bluetooth commands from your mobile.
- Monitor temperature and humidity for optimal plant care.
- Use low-cost, easily available components for DIY and learning.

---

## 📦 Hardware Required

| Component                  | Quantity |
|----------------------------|----------|
| Arduino Uno                | 1        |
| DHT11 Sensor               | 1        |
| Soil Moisture Sensor       | 1        |
| Bluetooth Module (HC-05/06)| 1        |
| 5V Relay Module            | 1        |
| DC Water Pump              | 1        |
| 5V Battery/Power Supply    | 1        |
| Jumper Wires               | as needed|
| Small Plant                | 1        |
| Water Container            | 1        |
| Breadboard (optional)      | 1        |

---

## 🗂️ Flowchart

<p align="center">
  <img src="https://github.com/user-attachments/assets/542b11f8-988a-446e-aa9c-f912edf9f5c0" width="600" alt="Flowchart" style="background: #fff; border-radius: 12px; box-shadow: 0 2px 8px rgba(0,0,0,0.10); padding: 16px;">
</p>

---

## 🛠️ Circuit Diagram

<p align="center">
  <img src="https://github.com/user-attachments/assets/2aedeaa6-f9f7-4847-b115-1faf4e3cd011" width="600" alt="Circuit Diagram" style="background: #fff; border-radius: 12px; box-shadow: 0 2px 8px rgba(0,0,0,0.10); padding: 16px;">
</p>

---

## 🌐 System Overview

- **Sensors:** DHT11 for temperature/humidity, soil moisture for soil wetness.
- **Controller:** Arduino automates pump/relay and receives user commands via Bluetooth.
- **Actuator:** Relay switches DC pump to water the plant.
- **Mobile App:** Use any Bluetooth terminal app to control and monitor.

---

## 🚦 How It Works

1. Continuously checks soil moisture.
2. If soil is dry, relay activates the pump to water the plant.
3. Reads temperature and humidity for complete plant health monitoring.
4. Use a Bluetooth app to:
    - Start/stop watering manually
    - Request sensor data
    - Set watering thresholds (if implemented)

---

## 📱 Bluetooth Commands

| Command | Function                        |
|---------|---------------------------------|
| `ON`    | Start watering (pump ON)        |
| `OFF`   | Stop watering (pump OFF)        |
| `DATA`  | Return temp/humidity/moisture   |

*Use any Bluetooth serial terminal app (e.g., Serial Bluetooth Terminal for Android).*

---

## 🖼️ Hardware Setup

<p align="center">
  <img src="https://github.com/user-attachments/assets/29cb7758-e52d-4b14-948f-6f6ff84dd76f" width="420" alt="Bluetooth Data Output" style="background: #fff; border-radius: 12px; box-shadow: 0 2px 8px rgba(0,0,0,0.10); padding: 16px;">
  <img src="https://github.com/user-attachments/assets/61491506-d780-4a77-8ded-c4f0ab4a8f49" width="420" alt="System in Action" style="background: #fff; border-radius: 12px; box-shadow: 0 2px 8px rgba(0,0,0,0.10); padding: 16px;">
</p>

---

## 📁 Project Structure

```
SmartGrow-BluetoothIrrigator/
├── assets/
│   ├── smartgrow_bluetoothirrigator_banner.png
│   ├── smartgrow_bluetoothirrigator_circuit.png
│   ├── smartgrow_data_output.png
│   ├── smartgrow_watering_action.jpg
├── SmartGrow_BluetoothIrrigator.ino
├── README.md
└── ...
```

---

## 📝 Arduino Code

- Open `SmartGrow_BluetoothIrrigator.ino` in Arduino IDE.
- Install libraries:
    - `DHT sensor library` (by Adafruit)
    - `Adafruit Unified Sensor`
- Connect components as per the diagram.
- Upload code to Arduino Uno.

---

## 🧠 Customization Ideas

- Schedule regular watering.
- Display data on LCD/OLED.
- Add water level sensor for the tank.
- Build a dedicated mobile app for one-touch control.
- Add notification features when soil gets too dry.

---

## 📚 Resources

- [Arduino Uno Docs](https://docs.arduino.cc/hardware/uno-rev3)
- [DHT11 Sensor Guide](https://learn.adafruit.com/dht)
- [Bluetooth Module HC-05](https://howtomechatronics.com/tutorials/arduino/arduino-bluetooth-basic-tutorial/)
- [Soil Moisture Sensor Tutorial](https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/)
- [Relay Module with Arduino](https://www.electronicwings.com/nodemcu/relay-module-interfacing-with-nodemcu)

---

## 📝 License

MIT License

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss your ideas.

---

## 👩‍💻 Author

Made with ❤️ by **Rakhi Yadav**

---

*Keep your plants happy and hydrated with SmartGrow-BluetoothIrrigator!*
