/**********************************************************
  - (button press) Acquire Incident Intensity (separate bkgnd here?)
  - (button press) Acquire Background Intensity
  - (button press) Acquire Absorptive Intensity, calculate SRM
**********************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

float bright;
float dark;
float transmit;
float absorbance;
int sig;
int SRM;
int stage = 0; // incident, background, absorptive
int LCDstage = 0;
int wait = 500; // ensure user releases button
bool button = digitalRead(D0);
String preamble = "     SRM: ";
String statement;

void setup() {
  // 430 nm LED on
  lcd.begin();
  pinMode(D0, OUTPUT);
  lcd.backlight();
  lcd.print("  Insert water");
  lcd.setCursor(0,1); // row, column
  lcd.print("   and record");
}

void loop() {
  button = digitalRead(D0);
  if (stage == 0 && button == HIGH) {
    if (LCDstage == stage){
      lcd.clear(); // only clear on new stage
      LCDstage += 1;
    }
    delay(wait);
    sig = analogRead(A0);
    bright = lum(sig);
    // 430 nm LED off
    lcd.print("  Insert beer,");
    lcd.setCursor(0,1);
    lcd.print("record baseline"); // record background
    stage += 1;
  }
  else if (stage == 1 && button == HIGH) {
    if (LCDstage == stage){
      lcd.clear();
      LCDstage += 1;
    }
    delay(wait);
    sig = analogRead(A0);
    dark = lum(sig);
    // 430 nm LED on
    lcd.print("  Insert beer,");
    lcd.setCursor(0,1);
    lcd.print("record absorbance");
    stage += 1;
  }
  else if (stage == 2 && button == HIGH) {
    if (LCDstage == stage){
      lcd.clear();
      LCDstage += 1;
    }
    delay(wait);
    sig = analogRead(A0);
    transmit = lum(sig);
    absorbance = log((transmit-dark)/(bright-dark));
    SRM = 12.7*absorbance;
    statement = preamble + SRM;
    lcd.print(statement);
    stage -= 1; // kick back to new recording
    LCDstage -=2;
  }
}

/*******************************************************
 luminescence expression below from data taken off datasheet
 correlating resistance to leminescence; voltage expression
 left for potential future use
*******************************************************/

float lum(float sig){
//float voltage;
  float resistance;
  float precision = 1024; // 10 bit on chip analog pin
  float Rstatic = 10000; // 10 kohm in series with photoresistor
  float luminescence;

//voltage = 3.3*log(sig)/log(2)/10;
  resistance = (Rstatic*(sig/precision))/(1-(sig/precision));
  luminescence = 1980515.624*pow(resistance, -1.291976701);
  return luminescence;
}
