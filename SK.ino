#include <stdlib.h>
#include <LiquidCrystal.h>



#define X_MIN_PIN           3
#ifndef X_MAX_PIN
#define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
#define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
#define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
#define Z_CS_PIN         40
#endif
int i = 0;
bool czymamodp = 0;
bool kierunek = 0;
bool xKrancowka;
bool yKrancowka;
bool zKrancowka;
String bufor;
int k1=0, k2=0, k3=0,licznikruchuk1=0,licznikruchuk2=0,licznikruchuk3=0;
int kier1=0, kier2=0, kier3=0;
LiquidCrystal lcd(16,17,23,25,27,29);
#define a -6.078e-07
#define b 7e-04
#define c 
#define d
double x,y;

void setup() {
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_STEP_PIN, OUTPUT);

  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

  // put your setup code here, to run once:

}
void loop() {

 
lcd.setCursor(0,0);  
temp=analogRead(13);
x=(double)temp;
y=a*x*x*x+b*x*x+c*x+d;
lcd.print(y);
lcd.print("Aktualna temperatura: ");
lcd.println("*C");
 
  delay(400);
  //
  // Serial.println(digitalRead(X_MAX_PIN));
  xKrancowka = digitalRead(X_MAX_PIN);
  yKrancowka = digitalRead(Y_MAX_PIN);
  zKrancowka = digitalRead(Z_MAX_PIN);
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  delayMicroseconds(1000);
  

 
 
  if ((xKrancowka == 0) && k1>0)
  {
    digitalWrite(X_STEP_PIN, LOW);
    k1--;
  }
  if ((yKrancowka == 0) && k2>0)
  {
    digitalWrite(Y_STEP_PIN, LOW);
    k2--;
  }
  if ((zKrancowka == 0) && k3>0)
  {
    digitalWrite(Z_STEP_PIN, LOW);
    k3--;
  }
  delayMicroseconds(250);
  i++;
//  if (i == 250)
// {
//    kierunek = !kierunek;
 //   digitalWrite(X_DIR_PIN, kierunek);
 //   digitalWrite(Y_DIR_PIN, kierunek);
  //  digitalWrite(Z_DIR_PIN, kierunek);
   // i = 0;
 // }
  while (Serial.available() > 0)
  {
    bufor = Serial.readStringUntil('\n');
    sscanf(bufor.c_str(),"%d;%d;%d",&k1,&k2,&k3);
    czymamodp = 1;
kier1=k1<0;
k1=abs(k1);
digitalWrite(X_DIR_PIN,kier1);
kier2=k2<0;
k2=abs(k2);
digitalWrite(Y_DIR_PIN,kier2);
kier3=k3<0;
k3=abs(k3);
digitalWrite(Z_DIR_PIN,kier3);
 
  
  }

 if (k1 == 0 && k2 ==0 && k3==0 && czymamodp ==1)
{  Serial.println("ok");
czymamodp=0;
 
 }
 
}


