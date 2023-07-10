// #
// # Editor     : Lauren from DFRobot
// # Date       : 26.09.2012
// # E-Mail : Lauren.pan@dfrobot.com

// # Product name: Crash sensor
// # Product SKU : SEN0138
// # Version     : 0.1

int inputPin2 = 4;               // Connect sensor to input pin 3
int inputPin1 = 3;

void setup() {
  Serial.begin(9600);           // Init the serial port

  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);     // declare Micro switch as input
}

void loop(){
  int val1 = digitalRead(inputPin1);
  int val2 = digitalRead(inputPin2);  // read input value
  if (val1 == HIGH) {                // check if the input is HIGH
  } else {
    Serial.println("Switch Pressed!");
  }
  delay(50);
  if (val2 == HIGH) {                // check if the input is HIGH
  } else {
    Serial.println("Switch Pressed!");
  }
  delay(50);
}