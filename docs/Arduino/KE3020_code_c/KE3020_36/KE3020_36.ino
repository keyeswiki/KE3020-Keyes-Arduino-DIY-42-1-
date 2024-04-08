/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 36
  DHT11温湿度传感器
  http://www.keyes-robot.com
*/
#include <dht11.h>  //include the library code:
dht11 DHT;
#define DHT11_PIN 3 //定义DHT11为数子口3

void setup() {
  Serial.begin(9600);
}
void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM: //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT: //超时错误返回
      break;
    default:
      break;
  }
  // DISPLAT DATA
  Serial.print("humidity:");
  Serial.print(DHT.humidity);
  Serial.print("   temperature:");
  Serial.println(DHT.temperature);
  delay(200);
}
