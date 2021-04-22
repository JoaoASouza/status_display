#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define CPU_USAGE 0
#define CPU_TEMP 1
#define MEM_USAGE 2

byte data[3];
char output[17];

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 9);
    lcd.setCursor(0, 0);
    lcd.print(" CPU  TEMP  MEM ");
}

void loop() {
    if (Serial.available() > 0) {
        Serial.readBytes(data, 3);

        sprintf(output, "%3d%%  %3dC %3d%%", data[CPU_USAGE], data[CPU_TEMP], data[MEM_USAGE]);

        lcd.setCursor(0, 1);
        lcd.print(output);
    }
}