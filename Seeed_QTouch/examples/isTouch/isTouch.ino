// demo of Qtouch - isTouch
// this demo will use isTouch function
// this function can the state of certain key
// such as you can get state of KEY0 with this function:
// isTouch(0), if return 1 meas KEY0 got touched while
// return 0 no touch.
// besides, this demo also print the touch time

#include <Wire.h>
#include "Seeed_QTouch.h"

void setup()
{   
    Serial.begin(9600);
}

void loop()
{
    if(QTouch.isTouch(0))
    {
        long time1 = millis();                          // get origin time
        Serial.print("key 0 touched: ");
        while(QTouch.isTouch(0));                       // unless key released
        Serial.print(millis() - time1);                 
        Serial.println(" ms");
    }
    delay(10);
}