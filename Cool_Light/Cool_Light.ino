#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <TimerOne.h>
#include "Seeed_QTouch.h"
#include "Seeed_ws2812.h"

#define SIG_PIN 12 //LED strip signal pin
#define LED_NUM 5  //LED strip led number

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
WS2812 strip = WS2812(LED_NUM, SIG_PIN);

uint8_t color[LED_NUM];

void setup() {
  strip.begin();
  nfc.begin();
  Serial.begin(115200); 
  color_domain_init(LED_NUM);
  Timer1.initialize(150000);         // initialize timer1
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
void callback()
{
  int tn = QTouch.touchNum();    
  if( tn == 0 | tn == 1 | tn == 2 ) {    
    colorChangeFromNumber(tn);    
  }
}
void loop() {                 
    colorChangeFromString(getStringFromNFC());
    delay(500);
}

//input color number, 0:blue   1:green   2:red
void colorChangeFromNumber(uint8_t n)
{
  if( n == 0 | n == 1 | n == 2 ) {          
      Serial.print("Touch_Num: ");
      Serial.println(n);
      strip.pureColor(n);  
      strip.WS2812Send();      
      strip.WS2812Send(); 
      strip.WS2812Send();
      strip.WS2812Send();
    }
}

//NFC get and return message 
String getStringFromNFC(void)
{
  delay(500);
  String payloadAsString = "";
  Serial.println("\nScan a NFC tag\n");
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    if (tag.hasNdefMessage()) // every tag won't have a message
    {
      NdefMessage message = tag.getNdefMessage();
      // cycle through the records, printing some info from each
      int recordCount = message.getRecordCount();
      Serial.println(recordCount);
      for (int i = 0; i < recordCount; i++)
      {        
        NdefRecord record = message.getRecord(i);
        int payloadLength = record.getPayloadLength();
        byte payload[payloadLength];
        record.getPayload(payload);
        
        for (int c = 0; c < payloadLength; c++) {
          payloadAsString += (char)payload[c];
        }
        //Serial.println(payloadAsString);       
      } 
      return payloadAsString;              
    } 
  }
}

//input a String, extract color number come after colon
//1:blue  2:green  3:red
void colorChangeFromString(String stringGet)
{
  int colonPosition = stringGet.indexOf(':');        
  int tn = stringGet.substring(colonPosition+1, colonPosition+2).toInt();
  if( tn == 1 | tn == 2 | tn == 3 ) {          
    Serial.print("NFC receive number: ");
    Serial.print(tn-1);
    if( tn - 1 == 0 ) Serial.println("  Color blue..");
    else if( tn - 1 == 1 ) Serial.println("  ColorRGBCycle..");
    else if( tn - 1 == 2 ) Serial.println("  colorRainBow");
    if(tn == 1) {
      static uint8_t i;
      i++;
      if(i > 2) i=0;
      
      strip.pureColor(i);  // 0...blue, 1...green, 2...red
      strip.WS2812Send(); 
      strip.WS2812Send(); 
      strip.WS2812Send(); 
      strip.WS2812Send();    
    }
    else if(tn == 2) {
      for(int i=0; i<2;i++){
        flowColor();        
      }
      for(int i=0; i<2;i++){
        strip.RGBCycle(1000);
      }
      
      strip.WS2812Clear();      
    }    
    else if(tn == 3) {
      strip.rainbowCycle(20);
      strip.WS2812Clear();
    }
  }
}
void flowColor(){
  for(int i=0; i<LED_NUM; i++){
    strip.colorWheel(color[i], i);
    strip.WS2812Send();    
    delay(200);
  }
  strip.WS2812Clear();
  for(int i=LED_NUM; i>=0; i--){
    strip.colorWheel(color[i], i);   
    strip.WS2812Send();   
    delay(200);
  }
  strip.WS2812Clear();
}

//according to how many leds are, calculate colors division  
uint16_t color_domain_init(uint8_t n) {  
  for( int color_step=0; color_step<n; color_step++){
    color[color_step] = color_step*(170/(n-1));    
    printf("color:", color[color_step],"");    
  }         
}
