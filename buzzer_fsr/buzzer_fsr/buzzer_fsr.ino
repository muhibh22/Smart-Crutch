// defines pins numbers
const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 6;
const byte redPin = 9;
const byte bluePin = 10;
const byte yellowPin = 11;
const byte sensorPin = A0;



// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   pinMode(buzzer, OUTPUT); 
   pinMode(redPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(yellowPin, OUTPUT);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

//fsr part
int sensorValue = analogRead(sensorPin); // read sensor
   if (sensorValue >= 0 && sensorValue <= 199) // all off
   {
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 400 && sensorValue <= 599)  // red on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 600 && sensorValue <= 799) // blue on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 800 && sensorValue <= 1023) // yellow on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(yellowPin, HIGH);
   }

}
