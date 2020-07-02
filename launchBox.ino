#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//define display size
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Pin declerations
int redLED = 4;
int launchLED = 5;
int SW1 = 6;
int SW2 = 7;
int SW3 = 8;
int buzzer = 9;
int relay = 10;
int greenLED = 14;
int blueLED = 15;
int goButton = 16;
int ARM = A0;
int SW4 = A1;

//variables
unsigned long lastClick = 0; //For button debouncing
String armed = "Disarmed";
String modeName = "No delay";
int modeState = 0;
int delayTime = 5; 

void setup() {
  //Dont go baby
  digitalWrite(relay, LOW);

  //no lights
  noLED();
  
  //initialize serial port
  Serial.begin(9600);

  //inputs
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(goButton, INPUT);
  pinMode(SW4, INPUT);
  pinMode(ARM, INPUT);

  //outputs
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(launchLED, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);


  //go button interrupt
  attachInterrupt(digitalPinToInterrupt(goButton), confirmGO, RISING);

  //Check on our display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 display failed"));
    failBeep();
  }

  //display bootup message
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.print(F("Lazerlabs LaunchBox"));
  display.display();

  //everything looks good, beep!
  singleBeep();
  delay(1000);
}


void loop() {
  getMode();
  delayTime = getTime();
  standby();
}

void standby() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print(modeName);
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.print(delayTime);
  display.print("s Delay");
  display.setTextSize(1);
  display.setCursor(0, 25);
  display.print(armed);
  display.display();
}


void countdown(int countDelay) {
  //display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  int counter = countDelay;
  for (int i = 0; i < countDelay; i++) {
    display.clearDisplay();
    display.print((counter--));
    display.display();
    singleBeep();
    delay(1000);
  }
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print(F("Ignition!"));
  display.display();
  goBabyGo();
  singleBeep();
}


void goBabyGo() {
  digitalWrite(relay, HIGH);
  delay(500);
  digitalWrite(relay, LOW);
}


//Interrupt Serivce Routine (ISR)
//Are we really going!?
void confirmGO() {
  //Debounce
  if (millis() - lastClick < 200) {
    return;
  }
  lastClick = millis();
  delayTime = getTime();
  countdown(delayTime);

  /*
    mode ++; //we are here, so button was pushed. Go to next mode.
    if(mode >= 5){mode = 0;} //we only have 4 modes
  */
}
