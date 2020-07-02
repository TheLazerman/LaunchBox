void blue(){
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);
}

void red(){
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
}

void green(){
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void purple(){
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
}

void orange(){
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}

void noLED(){
  digitalWrite(blueLED, HIGH);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, HIGH);
}
