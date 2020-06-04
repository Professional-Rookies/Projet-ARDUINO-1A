#include <LiquidCrystal.h>
LiquidCrystal LCD (12,11, 5, 4, 3, 2);
int buttonU=7;
int buttonR=10;
int buttonL=9;
int LED_ON=13;
int LED_OFF=8;
int IR=6;
int IRETAT;

void setup() 
{   

pinMode(LED_ON,OUTPUT);
pinMode(IR,INPUT);
pinMode(LED_OFF,OUTPUT);
pinMode(buttonR,INPUT);
pinMode(buttonU,INPUT); 
pinMode(buttonL,INPUT);
digitalWrite(buttonR,HIGH);
digitalWrite(buttonL,HIGH);
digitalWrite(buttonU,HIGH);

Serial.begin(9600);        
LCD.begin(16,2);// init lcd
LCD.setCursor (0,0); //deplacer cursor
LCD.print("Vie Hero     Score \n");
LCD.setCursor (0,1);
LCD.print("003 Safouene 025");
}

void loop() 
{
   static int up;
  static int droite;
  static int gauche;
  droite=digitalRead(buttonR);
  gauche=digitalRead(buttonL);
    up=digitalRead(buttonU);
  IRETAT=digitalRead(6);
if(IRETAT==0)
 {
   digitalWrite(LED_ON,HIGH);
   digitalWrite(LED_OFF,LOW);
 }
else
  {
 while (IRETAT!=0)
    {
      IRETAT=digitalRead(6);
    digitalWrite(LED_ON,LOW);
    digitalWrite(LED_OFF,HIGH);
       
    Serial.write(1);
    Serial.println("!!NO CARD!!/_______/Please Enter The Card");
    delay(500);
  
    }
  }



  
if (gauche==LOW && up==LOW )
{
    Serial.write(1);
    Serial.println("attack movement");
    delay(500);
     }
   else if (gauche==LOW)
   {
    Serial.write(2);
    Serial.println("Left movement");
    delay(500);
   }
    else if (droite==LOW)
   {
     Serial.write(1);
    Serial.println("Right movement");
    delay(500);
    
   }
    else if (up==LOW)
   {
     Serial.write(2);
    Serial.println("jump movement");
    delay(500);
    
   }
   else
   {
    Serial.write(0);
    Serial.println("No movement");
    delay(500);
   }


} 


  
  
