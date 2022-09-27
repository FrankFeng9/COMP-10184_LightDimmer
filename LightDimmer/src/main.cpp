#include <Arduino.h>

//I Yizhe Feng, 000798153 certify that this material is my original work. No other person's work has been used without due acknowledgement. 
//I have not made my work available to anyone else.

bool iState = false;

void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int iVal;
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  
  int iButton;
  // read the push button input... 
  iButton = digitalRead(D5);

  // ON/OFF SWITCH
  if(iButton == LOW && iState == true)
  {
    iState = false;
  } 
  else if(iButton == LOW && iState == false)
  {
    iState = true;
  }

  // ON state: change brightness by rotating the resistor. OFF State: keep LED off
  if(iState == true)
  {
    //change the LED brightness
    analogWrite(D4, iVal);
  } 
  else if(iState == false)
  {
    //LED power off
    digitalWrite(D4, HIGH);
  }
  
  delay(1);
}