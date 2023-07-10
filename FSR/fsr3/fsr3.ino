const byte redPin = 9;
const byte bluePin = 10;
const byte yellowPin = 11;
const byte sensorPin = A0;


void setup()
{
   Serial.begin(115200);
   pinMode(redPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(yellowPin, OUTPUT);
}

void loop()
{
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