#include <LiquidCrystal_I2C.h>

const int smokePin = A0;
const int tempPin = A1;
const int speedPin = A2;
const int fan1Pin = 9;
const int fan2pin = 10
const int buzzerPin = 11;
const int smokeThreshold = 300;
const float tempThreshold = 30.0; 
// Define variables for measuring speed
unsigned long start_time = 0;
unsigned long end_time = 0;
int steps = 0;
float steps_old = 0;
float temp = 0;
float rps = 0;

// I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  pinMode(fan1Pin, OUTPUT);
  pinMode(fan2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(smokePin, INPUT);
  pinMode(tempPin, INPUT);
  pinMode(speedPin, INPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

}

void loop() {

  int smoke = analogRead(smokePin);
  float temperature = (analogRead(tempPin) * 5.0 / 1023.0) * 100.0; 

  // Display sensor values on LCD
  

  // Smoke control
  if (smokeValue > smokeThreshold) {
    digitalWrite(fan1Pin, HIGH); // Turn on exhaust fan1
    lcd.setCursor(0, 0);
    lcd.print("Smoke:");
    lcd.print(smoke);
  } else {
    digitalWrite(fan1Pin, LOW); // Turn off exhaust fan1
  }

  // Temperature control
  if (temperature > tempThreshold) {
    digitalWrite(fan2Pin, HIGH); // Turn on cooling fan
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(temperature);
  } else {
    digitalWrite(fan2Pin, LOW); // Turn off cooling fan
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
  }

  // Motor speed control
  // Calculate motor speed based on IR sensor value
  start_time = millis();
  end_time = start_time + 1000;

  // measure steps taken within 1 second
  while (millis() < end_time) {
    if (digitalRead(apeedPin)) {
      steps = steps + 1;
      while (digitalRead(speedPin))
        ;
    }
  }
  temp = steps - steps_old;
  steps_old = steps;
  speed = (temp / 20);

  lcd.setCursor(8, 0);
  lcd.print("Speed:");
  lcd.print(speed);

  delay(100); // Adjust delay as needed
}
