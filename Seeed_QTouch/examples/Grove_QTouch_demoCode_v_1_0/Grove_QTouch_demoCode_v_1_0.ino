#include <Wire.h>
#include <Seeed_QTouch.h>

#define led  3
#define key0 0
int lastKeySignal = 0;
char nthr = 0;

void setup()
{
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  Wire.begin();
  Serial.begin(9600);
  
 //the value determines how long any key can be in touch before it recalibrates itself.160ms * 62 = 9.92s.
  QTouch.setMaxDuration(62);
  
 //set the threshold value for key0 to register a detection.If the hit pan is bigger, you should increase this Value.This Value should not be less than 20.
  QTouch.setNTHRForKey(60,key0);
}

void loop()
{

  if(QTouch.isTouch(0)) {
    digitalWrite(led, HIGH);
  } 
  else {    digitalWrite(led,LOW);
  }
}



