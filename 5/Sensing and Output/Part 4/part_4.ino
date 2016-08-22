int sensorPin = A0;    // select the input pin for the potentiometer
int ledPinRed = 13;      // select the pin for the LEDRED
int ledPinBlue = 12;    // select the pin for the LEDBLUE
   
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPinRed and LedPinBlue as OUTPUT:
  pinMode(ledPinRed, OUTPUT); 
  pinMode(ledPinBlue, OUTPUT); 
  Serial.begin(115200);
}

void loop() { 
  // read the value from the sensor:
 sensorValue = analogRead(sensorPin);
 
 if (sensorValue >600 && sensorValue < 700)
 {
  digitalWrite(ledPinBlue, LOW);    // Turn LEDBLUE off
  
  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() a part of that range
  // to the LEDRED’s range of 0 to 255 degrees. The flex sensors
  // we use are usually in the 600-900 range:
  sensorValue = map(sensorValue, 600, 700, 0, 255);
 
 // Now we'll command the LEDRED to shine as we require:
  analogWrite(ledPinRed, sensorValue);
  }
  
 else if (sensorValue >800 && sensorValue < 900)
  {
    digitalWrite(ledPinRed, LOW);  // Turn LEDRED off
  
  //We'll map() a part of that 0-1023 range
  // to the LEDBLUE’s range of 0 to 255 degrees.
    sensorValue = map(sensorValue, 800, 900, 0, 255);
    analogWrite(ledPinBlue, sensorValue);
    }
  
  //We would like to turn off both LEDRED and LEDBLUE when we 
  // flex the flex sensor to some degree.
 else if (sensorValue >700 && sensorValue < 800)
   {
    digitalWrite(ledPinBlue, LOW);
    digitalWrite(ledPinRed, LOW);
    }
 Serial.println(sensorValue);
 delay(1);                            
}
