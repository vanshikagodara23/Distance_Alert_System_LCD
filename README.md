# Distance Alert System with LCD

Distance alert system using an HC-SR04 ultrasonic sensor and an RGB LED, with the status and distance shown on a 16x2 I2C LCD.

## How it works

| Distance | LED colour | LCD message |
|---|---|---|
| More than 30 cm | Green | No Obstacle |
| 10 – 30 cm | Yellow | Obstacle Ahead |
| Less than 10 cm | Red | STOP! |

The second line of the LCD shows the distance in cm. The distance is also printed on the Serial Monitor (9600 baud).

## Components

- Arduino Uno (or compatible)
- HC-SR04 ultrasonic sensor
- RGB LED (common cathode) + 3 resistors (220 Ω)
- 16x2 LCD with I2C module
- Jumper wires, breadboard

## Wiring

| Part | Pin | Arduino pin |
|---|---|---|
| HC-SR04 | TRIG | 9 |
| HC-SR04 | ECHO | 10 |
| RGB LED | Red | 6 |
| RGB LED | Green | 3 |
| RGB LED | Blue | 5 |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |
| HC-SR04 / LCD | VCC / GND | 5V / GND |

## Libraries

- LiquidCrystal_I2C

## How to run

1. Install the **LiquidCrystal_I2C** library from the Library Manager.
2. Open `Distance_Alert_System_LCD.ino` in the Arduino IDE.
3. If the LCD stays blank, change the address `0x27` in the code to `0x3F`.
4. Upload to the board.
