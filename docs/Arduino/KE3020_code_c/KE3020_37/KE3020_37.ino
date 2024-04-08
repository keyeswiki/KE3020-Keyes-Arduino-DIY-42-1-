/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 37
  DS1307时钟模块
  http://www.keyes-robot.com
*/
#include <Wire.h>
#include "RtcDS1307.h"  //DS1307时钟模块的库

RtcDS1307<TwoWire> Rtc(Wire);//i2c接口

void setup(){
  Rtc.Begin();
  Rtc.SetIsRunning(true);

  Rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));

  Serial.begin(9600);//设置波特率为9600
}

void loop(){
  //打印年/月/日/时/分/秒/星期
  Serial.print(Rtc.GetDateTime().Year());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Month());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Day());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Hour());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Minute());
  Serial.print("    ");
  Serial.print(Rtc.GetDateTime().Second());
  Serial.print("    ");
  Serial.println(Rtc.GetDateTime().DayOfWeek());
  delay(1000);//延时1秒

}
