// C++ code
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);
int counter = 0; //variable that will store the count
int currentState = 0;
int previousState = 0;
void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);

}

void loop()
{
 digitalWrite(7,LOW);
 delayMicroseconds(2);
 digitalWrite(7,HIGH);
 delayMicroseconds(10);
 digitalWrite(7,LOW);
 long duration=pulseIn(6,HIGH);
 int distance=0.034*duration/2;
 Serial.print(distance);
 Serial.println("cm");
 
 if (distance >= 30 && distance <= 330){
 lcd.setCursor(0,0);
 currentState = 1;
 }
 else {
    currentState = 0;
 }
 if(currentState != previousState){
if(currentState == 1){
counter = counter + 1;
lcd.setCursor(0,0);
lcd.print("person count:");
lcd.print(counter);
}
}
previousState = currentState;
 //Delay 50ms before next reading.
 delay(200);
 
}