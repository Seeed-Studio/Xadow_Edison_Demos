// demo of Qtouch - getTouchNumber
// this demo will use touchNum function
// this function can return the touched state of the device
// when there's no touched, return -1
// or return the touch number

#include <Wire.h>
#include "Seeed_QTouch.h"


void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int tn = QTouch.touchNum();
    
    if(tn>=0)
    {
        Serial.print("KEY");
        Serial.print(tn);
        Serial.println(" touched");
    }
    
    delay(10);
}