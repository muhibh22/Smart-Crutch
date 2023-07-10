// defines pins numbers
const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 6;
const byte redPin = 9;
const byte bluePin = 10;
const byte yellowPin = 11;
const byte sensorPin = A0;
int inputPin1 = 3;
int inputPin2 = 4;



// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
  //Serial.begin(115200);
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   pinMode(buzzer, OUTPUT); 
   pinMode(redPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(yellowPin, OUTPUT);
   pinMode(inputPin1, INPUT);
   pinMode(inputPin2, INPUT);
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
if (safetyDistance <= 20){
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);

//fsr part
int sensorValue = analogRead(sensorPin); // read sensor
   if (sensorValue >= 0 && sensorValue <= 599) // all off
   {
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 600 && sensorValue <= 799)  // red on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 800 && sensorValue <= 899) // blue on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(yellowPin, LOW);
   }
   else if (sensorValue >= 900 && sensorValue <= 1023) // yellow on
   {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(yellowPin, HIGH);
   }
   //crash part
   int val1 = digitalRead(inputPin1);
  int val2 = digitalRead(inputPin2);  // read input value
  if (val1 == HIGH) {  
    Serial.print("n");
    delay(400) ;              // check if the input is HIGH
  } else {
    Serial.print("d");
    delay(10000);
  }
  delay(50);
if (val2 == HIGH) {                // check if the input is HIGH
  } else {
    Serial.print("d");
    delay(10000);
  }
  delay(50);     

}
