#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHT31.h>

#define SDA_PIN 4
#define SCL_PIN 5

Adafruit_SHT31 shtx = Adafruit_SHT31();

void setup()
{
    Serial.begin(9600);

    Wire.begin(SDA_PIN, SCL_PIN);

    if (!shtx.begin(0x44))
    {
        Serial.println("SHT3x sensor not found!");
        while (true)
        {
            delay(1000);
        }
    }

    shtx.reset();

    Serial.println("SHT3x sensor initialized.");
}

void loop()
{
    float temperature = shtx.readTemperature();
    float humidity = shtx.readHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(5000);
}