/* Electronoobs Bluetooth data receive with
 * Android and Arduino. Small example.
 * Remember to disconnect the Rx and Tx pins of the HC-06 when
 * uploading the code
 * 
 * Subscribe: http://www.youtube.com/c/ELECTRONOOBS
 * Tutorial: http://www.electronoobs.com/eng_arduino_tut20_2.php
 */
const int trigPin = 12; const int echoPin = 13; long duration, cm;

void setup() {
  // initialize serial communication with HC-06:
  Serial.begin(9600);  pinMode(trigPin, OUTPUT);  pinMode(echoPin, INPUT);
}

void loop()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds. // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose  // duration is the time (in microseconds) from the sending  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);
  // convert the time into a distance
  cm = (duration/2)/29.1;
  if(cm < 20)
  {
    Serial.print("d"); delay(400);
  }
  else
  {
    Serial.print("n"); delay(400);
  }  
}