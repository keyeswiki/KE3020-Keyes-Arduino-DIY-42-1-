/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 61
  智能门禁系统
  http://www.keyes-robot.com
*/
#include <Servo.h>
#include <Wire.h>
#include <MFRC522_I2C.h>
MFRC522 mfrc522(0x28);
Servo myservo;
String rfid_str = "";

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mfrc522.PCD_Init();
  myservo.attach(10);//舵机接数字口10
  myservo.write(0);//初始角度0度
  delay(500);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  rfid_str = "";//字符串清空
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {// 转储 UID
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //转为字符串
    //        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //        Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.print(rfid_str);
  if (rfid_str == "93e64720" || rfid_str == "633da54") {
    myservo.write(180);
    delay(500);
    Serial.println("  open the door!");
  }

}
