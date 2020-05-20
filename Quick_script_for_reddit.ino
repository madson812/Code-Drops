/***************************************************************
 * 
 *                      @madson812
 *                         2020
 * 
 * ************************************************************/

#include <LiquidCrystal.h>

//Hook the buttons up to 11 and 12 respectively.
//Make sure to use a resistor, otherwise it will
//be a short circuit which is bad for the arduino.
//Resistance doesn't matter too much, but 500 ohm is a good one.
#define yes 11
#define no 12

//hook up the LCD the same as in this example from the arduino website
//https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay
//lines 20 and 21 were copied from that website directly.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//I don't have an LCD to test with, I usually buy OLEDs which work through a different library.
//If this doesn't work, message me and I'll walk you through it. 
void setup() {
  pinMode(yes, INPUT);
  pinMode(no, INPUT);
  
  lcd.begin(16, 2);
}

void loop() {

  //This is the startup routine. This will display at the beginning of every loop.
  //Also, the setting of the cursor may be unnecessary. I don't know because I didn't test this code.
  //I'd recommend playing around with it a bit to see if it still works.
  lcd.setCursor(2,0);
  lcd.print("Hello!");
  delay(1000);
  lcd.setCursor(2,0);
  lcd.print("Are you feeling");
  lcd.setCursor(2,1);
  lcd.print("depressed?");
  
  //Make sure that the buttons are set up to normally not pass current through
  while(digitalRead(yes) == LOW && digitalRead(no) == LOW){ 
    //This while loop acts as a pause button. While neither of the buttons are pressed,
    //the script just waits.
    //There is a chance that you could let go of the button fast enough that the
    //arduino gets past this and then doesn't read anything. You'd have to be pretty fast
    //for that to happen though.
   }

  //This runs if you press the yes button
  if(digitalRead(yes) == HIGH){
    lcd.setCursor(2,0);
    lcd.print("Just try being");
    lcd.setCursor(2,1);
    lcd.print("happy instead.");
    delay(1000);
    lcd.setCursor(2,0);
    lcd.print("And get back");
    lcd.setCursor(2,1);
    lcd.print("to work");
    delay(1000);
  //This runs if you press the no button
  }else if(digitalRead(no) == HIGH){
    lcd.setCursor(2,0);
    lcd.print("...");
    delay(500);
    lcd.setCursor(2,0);
    lcd.print("Great!");
    delay(500);
    lcd.print("Now get");
    lcd.setCursor(2,1);
    lcd.print("back to work.");
    delay(1000);
  }

}
