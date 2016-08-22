#include <LiquidCrystal.h>
#include <Servo.h>  // servo library
  
int hours = 0; // start hours
int minutes = 0; //start min
int seconds = 10; //start seconds
int value;
Servo servo1;  // servo control object
int sensorValue = 0;
int potpin = A1;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); ////Pin Code for Arduino LCD 

 
void setup() {
  pinMode(6, OUTPUT);
  pinMode(13, INPUT);
  digitalWrite(13, HIGH);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
  servo1.attach(9);
  Serial.begin(9600);
}
 
void loop() {

int position;

Serial.println(sensorValue);
val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
servo1.write(val);                  // sets the servo position according to the scaled value
delay(15);                           // waits for the servo to get there
if(digitalRead(7) == LOW){
  value = 1;} 
 while (hours > 0 || minutes > 0 || seconds >= 0 && value == 1) {
 lcd.begin(16, 2);
 lcd.print("Count Down Timer ");
 
 // lcd.scrollDisplayLeft();
 // wait a bit:
 delay(150);

lcd.setCursor(6, 2);
(minutes < 10) ? lcd.print("0") : NULL;
 lcd.print(minutes);
 lcd.print(":");
 (seconds < 10) ? lcd.print("0") : NULL;
 lcd.print(seconds);
 lcd.display();
 
 delay(1000);


if (digitalRead(13) == LOW)
    {
     minutes++;
    } 
else if (digitalRead(10) == LOW)
    {
     seconds++;
    }
else if (digitalRead(7) == LOW)
    {
    minutes = 0;
    seconds = 1;  
    }

if(seconds > 59)
     {
      minutes++;
      seconds = 0;
     } 
if(minutes > 59)
     {
      minutes = 0; 
     }
     
 
if(digitalRead(8) == LOW)
    {
    value = 2;
    
while (hours > 0 || minutes > 0 || seconds >= 0 && value == 2){
  lcd.setCursor(6, 2);
 (minutes < 10) ? lcd.print("0") : NULL;
 lcd.print(minutes);
 lcd.print(":");
 (seconds < 10) ? lcd.print("0") : NULL;
 lcd.print(seconds);
 lcd.display();
 stepDown();
 delay(1000);
  }
}
 }
}
 
void stepDown() {
 if (seconds > 0) {
 seconds -= 1;
 } else if (minutes > 0){
  
 seconds = 59;
 minutes -= 1;
 } 
else if (seconds == 0 && minutes == 0)
{
  trigger();
 }
}
 
void trigger() {
 lcd.clear(); // clears the screen and buffer
 lcd.setCursor(5, 1); // set timer position on lcd for end.
 tone(6, 1000, 200);
  delay(200);
  noTone(6);
  delay(200);
 lcd.println("END ");
 delay(1000);
 
 lcd.display();
}

