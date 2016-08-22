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
 
 if(sensorValue > 700)
{
  digitalWrite(ledPinRed, HIGH);   // Turn LEDRED on
  digitalWrite(ledPinBlue, LOW);   // Turn LEDBLUE off
} 
else 
{
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);
}
 Serial.println(sensorValue); 
  delay(1);                            
}
