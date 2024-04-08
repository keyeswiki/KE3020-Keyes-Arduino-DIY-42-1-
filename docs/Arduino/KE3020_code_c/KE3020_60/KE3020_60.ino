/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 60
  温度散热装置
  http://www.keyes-robot.com
*/
#include "KETM1650.h"//导入TM1650库文件
#include <OneWire.h>
#include <DallasTemperature.h>//DS18B20库

int val = 0;
KETM1650 tm_4display(A5, A4);//四位数码引脚CLK接A5,DIO接A4
OneWire oneWire_8(8);
DallasTemperature sensors(&oneWire_8);
DeviceAddress insideThermometer;
float ds18b20_8_getTemp(int w) {
  sensors.requestTemperatures();
  if (w == 0) {
    return sensors.getTempC(insideThermometer);
  }
  else {
    return sensors.getTempF(insideThermometer);
  }
}

void setup() {
  tm_4display.init();//数码管初始化
  sensors.getAddress(insideThermometer, 0);
  sensors.setResolution(insideThermometer, 9);
  //电机接A0A1
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  val = ds18b20_8_getTemp(0);//读取摄氏温度
  tm_4display.displayString(val);//数码管显示温度
  if (val > 30) {//超过30摄氏度，开启风扇
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
  } else {//否则 关闭风扇
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
  }
  delay(100);

}
