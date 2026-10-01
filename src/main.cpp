#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHT31.h>

#define SDA_PIN 4
#define SCL_PIN 5

Adafruit_SHT31 shtx = Adafruit_SHT31();

void setup()
{
    Serial.begin(9200);

    Wire.begin(SDA_PIN, SCL_PIN);

    if (!shtx.begin(0x44))
    {
        Serial.println("SHT3x sensor not found!");
        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("SHT3x sensor initialized.");
}

void loop()
{
    float temperature = shtx.readTemperature();
    float humidity = shtx.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read SHT3x sensor.");
    }
    else
    {
        Serial.printf(
            "Temperature: %.2f °C | Humidity: %.2f %%\n",
            temperature,
            humidity
        );
    }

    delay(5000);
}