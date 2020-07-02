



void getMode(){
if(analogRead(SW4) < 10){
  modeName = "Estes Igniter";
  modeState = 2;
  blue();
}else{
  modeName = "Wire Match";
  modeState = 0;
  green();
}
if(analogRead(ARM) >100){
  armed = "Armed!";
  red();
}else{
  armed = "Disarmed";
}
}

int getTime(){
  //read the switches in binary
  int value = (digitalRead(SW3) *4 ) + (digitalRead(SW2) *2) + (digitalRead(SW1));
  return value;
}
