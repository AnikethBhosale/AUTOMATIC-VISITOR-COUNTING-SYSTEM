#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,7,6,5,4);

#define in 8
#define out 9
#define led 10
int in1=12;
int in2=13;
int en_A=11;
int count=0;

void setup()
{
  
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(led, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
   pinMode(12,OUTPUT);
   pinMode(13,OUTPUT);
   pinMode(11,OUTPUT);
}

void loop()
{ 

  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  
  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
 
  
  if(count==0)
  {
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light is Off");
    delay(100);
  }
  
  else
  {
    digitalWrite(led, HIGH);
  }
  {
 digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   analogWrite(en_A,34);
   delay(210); 
  }

}
