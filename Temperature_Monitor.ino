// Library Installation //
#include <LiquidCrystal.h>
// LDC Pin Variables //
int D4 = 2;
int D5 = 3;
int D6 = 4;
int D7 = 5;
int E = 6;
int RS = 7;

//Enabling LiquidCrystal//
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

// Hardware / Pin Variables Setting //
int lmPin = A0; 
int redRGB = 11; 
int greenRGB = 10; 
int blueRGB = 9; 
int Brightness = 255; 
int readValue; 
float voltValue; 
float miliVolt; 
float Temperature; 

void setup() {
  Serial.begin(9600);
  pinMode(lmPin, INPUT);
  pinMode(redRGB, OUTPUT);
  pinMode(greenRGB, OUTPUT);
  pinMode(blueRGB, OUTPUT);
  lcd.begin(16, 2);

}

void loop() {
  // ADC - Voltage - Temperature (°C) Conversion //
  readValue = analogRead(lmPin);
  voltValue = (5./1023.) * readValue;
  miliVolt = voltValue * 1000.;
  Temperature = miliVolt / 10.;

  // Serial Monitor Manipulation // 
  Serial.println("");
  Serial.println("ADC Converter (Analog Value - MiliVolts): ");
  Serial.print(readValue);
  Serial.print(" - ");
  Serial.print(miliVolt);
  Serial.print(" mV");
  Serial.println("");
  Serial.println("Temperature: ");
  Serial.print(Temperature);
  Serial.println("°C");

// Temperature Conditionals //
  if(Temperature < 20.){
    analogWrite(blueRGB, Brightness);
    analogWrite(redRGB, 0);
    analogWrite(greenRGB, 0);
    Serial.print("COOL");
    Serial.println("");
    lcd.setCursor(0, 0);
    lcd.print(Temperature, 1);
    lcd.print(" C     ");
    lcd.setCursor(0, 1);
    lcd.print("COOL :)");

  }

  else if(Temperature >= 20. && Temperature <= 25.){
    analogWrite(greenRGB, Brightness);
    analogWrite(redRGB, 0);
    analogWrite(blueRGB, 0);
    Serial.print("WARM");
    Serial.println("");
    lcd.setCursor(0, 0);
    lcd.print(Temperature, 1);
    lcd.print(" C     ");
    lcd.setCursor(0, 1);
    lcd.print("WARM :|");
  }

  else {
    analogWrite(redRGB, Brightness);
    analogWrite(greenRGB, 0);
    analogWrite(blueRGB, 0);
    Serial.print("HOT");
    Serial.println("");
    lcd.setCursor(0, 0);
    lcd.print(Temperature, 1);
    lcd.print(" C     ");
    lcd.setCursor(0, 1);
    lcd.print("HOT >:(");
  }

  delay(1000);

}
