#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup(){
  lcd.begin(16, 2);
}
 
void loop(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Bom dia");
  lcd.setCursor(3, 1);
  lcd.print("Amigos");
  delay(1000);
   
  //Rolagem para a esquerda
  for (int pos = 0; pos < 3; pos++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
