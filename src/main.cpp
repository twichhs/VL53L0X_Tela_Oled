#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <VL53L0X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI 23
#define OLED_CLK 18
#define OLED_DC 2
#define OLED_CS 5
#define OLED_RESET 4

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    OLED_MOSI,
    OLED_CLK,
    OLED_DC,
    OLED_RESET,
    OLED_CS
);

VL53L0X sensor;

void setup()
{
    Serial.begin(115200);

    Wire.begin(21, 22);

    if (!display.begin(SSD1306_SWITCHCAPVCC))
    {
        Serial.println("Falha OLED");
        while (true);
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    if (!sensor.init())
    {
        display.clearDisplay();
        display.setCursor(0, 20);
        display.println("VL53L0X");
        display.println("NAO ENCONTRADO");
        display.display();

        Serial.println("Sensor nao encontrado");
        while (true);
    }

    sensor.setTimeout(500);

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println("READY");
    display.display();

    delay(1500);
}

void loop()
{
    uint16_t distancia = sensor.readRangeSingleMillimeters();

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" mm");

    int barra = map(
        constrain(distancia, 50, 1000),
        1000,
        50,
        0,
        120
    );

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("CYBER SCAN");

    display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

    display.setTextSize(2);
    display.setCursor(10, 18);
    display.print(distancia);
    display.print("mm");

    display.drawRect(4, 52, 120, 8, SSD1306_WHITE);
    display.fillRect(4, 52, barra, 8, SSD1306_WHITE);

    if (distancia < 300)
    {
        display.setTextSize(1);
        display.setCursor(40, 40);
        display.print("TARGET LOCK");
    }

    display.display();

    delay(100);
}