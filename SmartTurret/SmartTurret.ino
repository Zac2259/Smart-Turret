byte lastButtonState;
byte ledState = LOW;
unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 100;
// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// Traffic Lights - LED Outputs
#define ledRed A0
#define ledYellow A1
#define ledGreen A2

// DC Motor & Motor Module - L298N
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);

// Servo
#include <Servo.h>
Servo myservo;

//Potentiometer
#define pot A3

// Piezo Buzzer
#define piezoPin 8

// Sonar - HC-SR04
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A4 //attach pin D3 Arduino to pin Trig of HC-SR04

// Line Sensor
#define lineSensorPin 3

// Crash Sensor / Button
#define crashSensor 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");

  // Traffic Lights - LED Outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // DC Motor & Motor Module - L298N
  motor.setSpeed(70);

  // Servo
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  //Potentiometer
  pinMode(pot, INPUT);

  // Piezo Buzzer
  pinMode(piezoPin, OUTPUT);

  // Sonar - HC-SR04
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  // Line Sensor
  pinMode(lineSensorPin, INPUT);

  // Crash Sensor / Button
  pinMode(crashSensor, INPUT);

}


void logEvent(String dataToLog) {
  /*
     Log entries to a file on an SD card.
  */
  // Get the updated/current time
  DateTime rightNow = rtc.now();

  // Open the log file
  File logFile = SD.open("events.csv", FILE_WRITE);
  if (!logFile) {
    Serial.print("Couldn't create log file");
    abort();
  }

  // Log the event with the date, time and data
  logFile.print(rightNow.year(), DEC);
  logFile.print(",");
  logFile.print(rightNow.month(), DEC);
  logFile.print(",");
  logFile.print(rightNow.day(), DEC);
  logFile.print(",");
  logFile.print(rightNow.hour(), DEC);
  logFile.print(",");
  logFile.print(rightNow.minute(), DEC);
  logFile.print(",");
  logFile.print(rightNow.second(), DEC);
  logFile.print(",");
  logFile.print(dataToLog);

  // End the line with a return character.
  logFile.println();
  logFile.close();
  Serial.print("Event Logged: ");
  Serial.print(rightNow.year(), DEC);
  Serial.print(",");
  Serial.print(rightNow.month(), DEC);
  Serial.print(",");
  Serial.print(rightNow.day(), DEC);
  Serial.print(",");
  Serial.print(rightNow.hour(), DEC);
  Serial.print(",");
  Serial.print(rightNow.minute(), DEC);
  Serial.print(",");
  Serial.print(rightNow.second(), DEC);
  Serial.print(",");
  Serial.println(dataToLog);
}



void loop() {
  // put your main code here, to run repeatedly:
  turretRemote(); // Button and potiometer
  trackingSensor(); // Line Sensor and PIR
  turretWeapons(); // Distance Sensor and Traffic LED
}
/*
   button activates turret and line sensor the potienometer adjusts the vertical angle of the turret
*/

void turretRemote() {
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
    byte buttonState = digitalRead(crashSensor);
    if (buttonState != last ButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttomState;
      if (buttonState == LOW) {
        if (ledState = HIGH) {
          ledState = LOW;
        }
        else {
          ledState = HIGH
        }
        digitalWrite(ledYellow, ledState);
      }
    }
  }
}
int val = analogRead(pot);            // reads the value of the potentiometer (value between 0 and 1023)
val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
myservo.write(val);
Serial.println(val);
}

/*
   when the line sensor is triggered it will activate the PIR which will track any moving targets the turret will then phsyiclly move to track said target vai the DC Motor
*/

void trackingSensor() {

}

/*
   The distance sensor will track the distance of the moving target to the turret if it reaches the threshold the traffic LED will turn red
*/

void turretWeapons() {

}
