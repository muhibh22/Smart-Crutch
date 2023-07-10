int inputPin = 3;

void setup() {
  Serial.begin(9600);   //Set the baud rate of the comunication
  pinMode(inputPin,INPUT);    //Define the pin as input
}

void loop() {
int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) { 
    Serial.print("n");
    delay(400) ;              // check if the input is HIGH
  } else {
    Serial.print("d");
    delay(10000);
  }
  delay(50);  
}