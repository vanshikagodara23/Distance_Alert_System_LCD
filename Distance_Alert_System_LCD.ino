// Aim: Distance Alert System using HC-SR04 & RGB light integrated with LCD Display

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// RGB LED
const int redPin = 6;
const int greenPin = 3;
const int bluePin = 5;

long duration;
int distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Obstacle Alert");
  lcd.setCursor(0,1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.clear();

  if(distance > 30)
  {
    // Green
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0,0);
    lcd.print("No Obstacle");

    lcd.setCursor(0,1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print(" cm");
  }

  else if(distance > 10)
  {
    // Yellow
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0,0);
    lcd.print("Obstacle Ahead");

    lcd.setCursor(0,1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print(" cm");
  }

  else
  {
    // Red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    lcd.setCursor(0,0);
    lcd.print("STOP!");

    lcd.setCursor(0,1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print(" cm");
  }

  delay(300);
}
