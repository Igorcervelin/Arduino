#include <Ultrasonic.h>
#include <LiquidCrystal.h>
  
#define pino_trigger 10
#define pino_echo 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup(){
  Serial.begin(9600);
  Serial.println("Reading");
  lcd.begin(16, 2);
}
 
void loop(){
  
  float cm, pol;
  long microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  pol = ultrasonic.convert(microsec, Ultrasonic::IN);

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(cm);
  lcd.print("cm");
  lcd.setCursor(3, 1);
  lcd.print(pol);
  lcd.print("pol");
  delay(350);
}
