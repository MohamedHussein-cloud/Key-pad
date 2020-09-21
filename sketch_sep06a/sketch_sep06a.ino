#include<Keypad.h>
#define r1 13
#define r2 12
#define r3 11
#define r4 10
#define c1 9
#define c2 8
#define c3 7
#include <LiquidCrystal.h>
#define LCD1 6
#define LCD2 5
#define LCD3 4
#define LCD4 3
#define LCD5 2
#define LCD6 1
int i = 0;
LiquidCrystal lcd(LCD1,LCD2,LCD3,LCD4,LCD5,LCD6);
char rowpins[4] = {r1,r2,r3,r4};
char colpins[3]={c1,c2,c3};
char sympols[4][3]={{'m','o','h'},
                    {'a','e','d'},
                    {'7','8','9'},
                    {2,'0',3}};
Keypad phone = Keypad(makeKeymap(sympols),rowpins,colpins,4,3);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); 
}
void loop() {
  // put your main code here, to run repeatedly:
char m = phone.getKey();
lcd.setCursor(i,0);
if (m){
  lcd.clear();
}
char key = phone.getKey();
if (key == 2){
i--;
lcd.print(" ");
}
else if (key != NO_KEY){
lcd.print(key);
i++;
}
else if (key == 3){
lcd.clear();
lcd.setCursor(0,0);
}
}
