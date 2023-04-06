//By HomeMade Electronics
//Subscribe to my channel https://www.youtube.com/channel/UC8isJR_71x1wIfw6jB106pg
//for more tutorial videos
//like, share and leave a comment if you need help

#include <LiquidCrystal.h>

#define echo 9
#define trigger 10
#define waterValve 11
#define gasValve 12
#define gasSensor 8
long duration;
int distance;
int gasleak;
int percentageDistance;

LiquidCrystal lcd(7,6,5,4,3,2);

void setup () {
lcd.begin(20,4);
pinMode(echo,INPUT);
pinMode(trigger,OUTPUT);
pinMode(gasValve, OUTPUT);
pinMode(waterValve ,OUTPUT);


digitalWrite(trigger,LOW);
digitalWrite(gasValve,LOW);
digitalWrite(waterValve,LOW);


lcd.setCursor(0,0);
lcd.print("HOMEMADE ELECTRONICS");
lcd.setCursor(0,2);
lcd.print("    GAS AND WATER");
lcd.setCursor(0,3);
lcd.print("  MONITORING SYSTEM");
delay(2000);
lcd.clear();

}

void loop() {
// ultrasonic reading
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
duration=pulseIn(echo,HIGH);
distance=duration*0.017;
percentageDistance=map(distance,0,1024,0,100);
// gas leakage reading
gasleak=digitalRead(gasSensor);

//call functions
cond1();
cond2();
cond3();
cond4();
cond5();
cond9();
cond10();
cond11();
cond12();
cond13();
cond14();

water();
gas();
delay(500);
}

void water(){
if (percentageDistance<50){
digitalWrite(waterValve,HIGH);
}
else
{digitalWrite(waterValve,LOW);
}
}

void gas(){
if (gasleak==HIGH){
digitalWrite(gasValve,LOW);
}
else
{digitalWrite(gasValve,HIGH);
}
}




void cond1(){
if (percentageDistance>50&& gasleak==HIGH)
displayAlloff();
}

void cond2()
{
if(percentageDistance<50&& gasleak==LOW)
displayAllon();
}

void cond3(){
if (percentageDistance<50&& gasleak==HIGH)
displayWon();
}

void cond4(){
if (percentageDistance>50&& gasleak==HIGH)
displayPon();
}

void cond5(){
if (percentageDistance>50&& gasleak==LOW)
displayGon();
}

//OFFS

void cond6(){
if (percentageDistance>50&& gasleak==HIGH)
displayGoff();
}

void cond7(){
if (percentageDistance>50&& gasleak==LOW)
displayPoff();
}
void cond8(){ 
if (percentageDistance>50&& gasleak==HIGH)
displayWoff();
}



void cond9(){
if (percentageDistance<50&& gasleak==LOW)
displayGandWon();
}
void cond10(){ 
if (percentageDistance<50&& gasleak==HIGH)
displayPandWon();
}
void cond11(){
if (percentageDistance>50&& gasleak==LOW)
displayGandPon();
} 
void cond12(){ 
if (percentageDistance>50&& gasleak==HIGH)
displayGandWoff();
}
void cond13(){
if (percentageDistance<50&& gasleak==HIGH)
displayGandPoff();
}
void cond14(){ 
if (percentageDistance>50&& gasleak==LOW)
displayPandWoff();
}

void displayAlloff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}

void displayPon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}
void displayWon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}
void displayGon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}
void displayAllon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}





void displayGandWon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}


void displayPandWon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}
void displayGandPon(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}

void displayGandWoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}




void displayPandWoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}

void displayGandPoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}


void displayGoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  OFF");
}
void displayPoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  ON");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}

void displayWoff(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water= ");
lcd.print( percentageDistance);
lcd.print("%");
lcd.setCursor(11,0);
lcd.print("Gas Lk= ");
lcd.print( gasleak);

lcd.setCursor(0,2);
lcd.print("W-VALVE STATUS");
lcd.print ("  OFF");
lcd.setCursor(0,3);
lcd.print("G-VALVE STATUS ");
lcd.print ("  ON");
}
