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

 if (sensorValue >0 && sensorValue < 512)
 {
  digitalWrite(ledPinBlue, LOW);     // Turn LEDBLUE off

  //We'll map() a part of 0-1023 range to the LEDRED’s range of 
  //0 to 255 degrees. The potentiometers
  // we use are usually in the 0-1023 range:
  sensorValue = map(sensorValue, 0, 512, 0, 255);
  
  // Now we'll command the LEDRED to shine as we require:
  analogWrite(ledPinRed, sensorValue);
  }
  
  else if (sensorValue >512 && sensorValue < 1024)
  {
    digitalWrite(ledPinRed, LOW);     // Turn LEDRED off
    sensorValue = map(sensorValue, 512, 1024, 0, 255);
    analogWrite(ledPinBlue, sensorValue);
    }
    
 //Serial.println(sensorValue);
 delay(1);                            
}
