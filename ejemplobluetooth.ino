#include <SoftwareSerial.h>

SoftwareSerial miBT(10,11);
//BLUETOOTH
char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;
byte serialA;
int SENSORVALUE;
int ANALOGVALUE;
int PINALARMA = 4;
int i=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  miBT.begin(38400);
  pinMode(LEDROJO,OUTPUT);
  pinMode(LEDVERDE,OUTPUT);
  pinMode(PINALARMA,OUTPUT);
}

void loop() 
{
 
  serialA=miBT.read(); 
  if (serialA == 49){
    SENSORVALUE = analogRead(A0);
    ANALOGVALUE = map(SENSORVALUE,0,1023,0,255); 
    miBT.write(ANALOGVALUE);
    Serial.print(i);
    Serial.print(",");
    Serial.print(ANALOGVALUE);
    Serial.println(";");
    i = i + 1;
    
    serialA=0; 
  }
  else{
    if(serialA == 'r')
    {
      digitalWrite(LEDROJO,!digitalRead(LEDROJO));         
     
    }
    if(serialA == 'v')
    { 
      digitalWrite(LEDVERDE,!digitalRead(LEDVERDE));  
     
    }
    /*if(serialA == 'a')
    {
      tone(PINALARMA,173);
      Serial.print("a");
      delay(50);
      noTone(PINALARMA);
      
    }*/
    
  }
  
  /*if(miBT.available()){  
   
    if(serialA == 'r')
    {
      
      digitalWrite(LEDROJO,!digitalRead(LEDROJO));     
      delay(150); 
    }
    if(serialA == 'v')
    {
      
      digitalWrite(LEDVERDE,!digitalRead(LEDVERDE));  
      delay(150);
    }
  }*/
  //delay(500);
}
