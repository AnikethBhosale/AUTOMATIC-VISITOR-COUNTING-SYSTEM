#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

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
  lcd.print("COUNT");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(led, OUTPUT);
  lcd.clear();
  lcd.print("visitor deteced:");
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
    lcd.print("visitor detected:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(900);
  }
  
  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.print("visitor detected:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(900);
  }
  
  if(count==0)
  {
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.print("room empty");
    lcd.setCursor(0,1);
    lcd.print("Lights turned Off");
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
