#include <Arduino.h>

const int CDS = 35;     // CdSセル接続ピン
const int LED = 12;     // LED接続ピン
const int PWM_CH = 0;   // PWMチャンネル
 
void setup() {
  pinMode(CDS, INPUT);
  pinMode(LED, OUTPUT);
  ledcSetup(PWM_CH, 1000, 12);
  ledcAttachPin(LED, 0);
   
  Serial.begin(115200);
}
 
void loop() {
  int value = analogRead(CDS);
  Serial.println(value);
 
  unsigned int ledPow = 0x0FFF - value;
 
  if(ledPow < 0x00FF){
    ledPow = 0;
  }
   
  ledcWrite(PWM_CH, ledPow);
  Serial.print("ledPow:");
  Serial.println(ledPow);
   
  delay(500);
}