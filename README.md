# 🌡️ Hardware Test — SHT3x

A simple hardware test project for **SHT3x temperature and humidity sensors** using an **ESP32** and the **I2C** communication protocol.

<p align="center">
  <img width="500" height="211" alt="sen-10-048-new" src="https://github.com/user-attachments/assets/551c2d2d-ab0c-4704-ad66-cf5a4677244f" />
</p>

This project is part of the **TechOnIt Hardware Test** collection and is intended to validate SHT3x sensor modules independently before integrating them into the TechOnIt Node firmware.

## Supported Sensors

This project is designed for the **Sensirion SHT3x family**, including:

* SHT30
* SHT31
* SHT35

The exact supported features may vary depending on the specific sensor/module.

## Hardware

* ESP32 / NodeMCU
* SHT3x Temperature & Humidity Sensor
* USB cable

## Wiring

| SHT3x | ESP32  |
| ----- | ------ |
| VCC   | 3.3V   |
| GND   | GND    |
| SDA   | GPIO 4 |
| SCL   | GPIO 5 |

### I2C Address

The default I2C address used by most SHT3x modules is:

```text
0x44
```

Some modules may use:

```text
0x45
```

depending on the address configuration.

## Project Structure

```text
hw-test-shtx/
├── platformio.ini
├── src/
│   └── main.cpp
└── README.md
```

## Dependencies

This project uses:

* PlatformIO
* Arduino Framework
* ESP32
* Wire / I2C
* Adafruit SHT31 Library

The required library is defined in `platformio.ini` and will be installed automatically by PlatformIO.

## How It Works

The ESP32 communicates with the SHT3x sensor through the I2C interface.

Every **5 seconds**, the firmware:

1. Reads the temperature.
2. Reads the relative humidity.
3. Prints both values to the Serial Monitor.

```text
ESP32
  │
  │ I2C
  ▼
SHT3x
  ├── Temperature
  └── Humidity
```

## Example Output

```text
SHT3x initialized.
Temperature: 25.31 °C | Humidity: 42.87 %
Temperature: 25.28 °C | Humidity: 43.02 %
Temperature: 25.30 °C | Humidity: 42.95 %
```

## Serial Monitor

Use the following baud rate:

```text
115200
```

## Purpose

This repository is a **standalone hardware validation project**.

It is intentionally kept separate from the production Node firmware so that individual hardware modules can be tested independently before integration.

The sensor implementation can later be integrated into the **TechOnIt Node** firmware as a sensor driver.

## Related Projects

* `agent-node` — TechOnIt Node firmware
* `agent-controller` — TechOnIt Controller software
* `agent-sdk` — TechOnIt SDK

## License

This project is part of the TechOnIt open-source IoT ecosystem.

