//#include <SoftwareSerial.h>
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#include <stdlib.h>
#include <dht.h>
#define dht_dpin A0 
int mq135;
int mq7;
int mq5;
int i, j;
dht DHT;

// this runs once
void setup() {                
  // initialize the digital pin as an output.
   lcd.begin(20, 4);
lcd.setCursor(0, 0);
 lcd.print("IOT Sensors");
 delay(2000);
 lcd.clear();

 lcd.setCursor(0, 0);
 lcd.print("Vikrat Gupta");
 delay(3000);
 lcd.clear();
analogReference(DEFAULT);
  // enable debug serial
  Serial.begin(9600);
 
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); //buzzer
    pinMode(3, OUTPUT);
  digitalWrite(3, LOW); //led
}


// the loop
void loop() {
   DHT.read11(dht_dpin);
      

 i=DHT.humidity;
      j =DHT.temperature;

mq7 = analogRead(A1); //mq7
mq135 = analogRead(A2); //mq135
mq5 = analogRead(A3); //mq5
if(i>=80 || j>=40 || mq7>=700 || mq135>=700 || mq5>=700)
{
   digitalWrite(3, HIGH); //led
    digitalWrite(4, HIGH); //buzzer
    delay(1000);
     digitalWrite(3, LOW); //led
      digitalWrite(4, LOW); //buzzer
}

    lcd.setCursor(0, 0);
    lcd.print("MQ7: ");
 lcd.print(mq7);
 lcd.setCursor(0, 1);
    lcd.print("MQ5: ");
 lcd.print(mq5);
 delay(2000);
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MQ135: ");
 lcd.print(mq135);
  lcd.setCursor(0, 1);
    lcd.print("H:");
 lcd.print(i);
 lcd.print(" ");
  lcd.setCursor(9, 1);
  lcd.print("T:");
 lcd.print(j);
  lcd.print(" ");
 delay(2000);
 lcd.clear();
}
