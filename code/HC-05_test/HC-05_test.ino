#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);    //define pin10 as RX, pin11 as TX; HC-05 TXD->10, HC-05 RXD->11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  Serial.println("hd");
  BT.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    BT.write(Serial.read());
  }
  if (BT.available()){
    Serial.write(BT.read());
  }
}
