#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);
#else

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

//change the number after colon like "1" or "2" or "3".
#define WRITE_TAG_MESSAGE "color:1" 

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
#endif

void setup() {
      Serial.begin(115200);
      Serial.println("NDEF Writer");
      nfc.begin();
}

void loop() {
    Serial.println("\nPlace a formatted Mifare Classic NFC tag on the reader.");
    Serial.print("Writing message: <");
    Serial.print(WRITE_TAG_MESSAGE);
    Serial.println("> to you NFC tag");
    if (nfc.tagPresent()) {
        NdefMessage message = NdefMessage();
        message.addTextRecord(WRITE_TAG_MESSAGE);

        bool success = nfc.write(message);
        if (success) {
          Serial.println("Success. Try reading this tag with your phone.");        
        } else {
          Serial.println("Write failed.");
        }
    }
    delay(5000);
}
