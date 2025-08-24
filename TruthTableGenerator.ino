#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledA = 8;
int ledB = 9;
int outA = 13;  
int outB = 3;   
int buttonPin = 7;

int state = 0;     
bool lastButton = HIGH;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(outA, OUTPUT);   
  pinMode(outB, OUTPUT);   
  pinMode(buttonPin, INPUT_PULLUP); 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Truth Table Gen");
  delay(2000);
  lcd.clear();
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  
  if (lastButton == HIGH && buttonState == LOW) {
    state = (state + 1) % 4; 
    showOutput(state);
    delay(200); 
  }
  lastButton = buttonState;
}


void showOutput(int s) {
  int a = (s >> 1) & 1; 
  int b = s & 1;        

  digitalWrite(ledA, a);
  digitalWrite(ledB, b);
  digitalWrite(outA, a);  
  digitalWrite(outB, b);  

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A = ");
  lcd.print(a);
  lcd.setCursor(0, 1);
  lcd.print("B = ");
  lcd.print(b);
}
