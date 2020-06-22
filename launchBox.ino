//Pin Mappings

const int redLED = 4;
const int launchLED = 5;
const int SW1 = 6;
const int SW2 = 7;
const int SW3 = 8;
const int buzzer = 9;
const int relay = 10;
const int greenLED = 14;
const int blueLED = 15;
const int goButton = 16;





void setup() {
  //inputs (be lazy bois)
  int i = 0;
  for (i = 6; i >= 10; i++) {
    pinMode(i, INPUT);
  }
  pinMode(goButton, INPUT);
  //outputs
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(launchLED, OUTPUT);


  //no mode led (for now)
  modeOff();
}

void loop() {
  if (goButton = LOW) {
    modeBlue();
  }
  if (goButton = HIGH) {
    modeRed();
  }

}

void modeBlue() {
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);
}
void modeRed() {
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
}
void modeGreen() {
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}
void modeOff() {
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);
}
