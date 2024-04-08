/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 41
  LCD_128X32_DOT模块
  http://www.keyes-robot.com
*/
#include <lcd.h>  //添加库文件
lcd Lcd;  //定义Lcd类实例

void setup() {
  Lcd.Init(); //初始化
  Lcd.Clear();  //清屏
}

void loop() {
  Lcd.Cursor(0, 7); //设置第一行，第八列开始显示，下同
  Lcd.Display("KEYES"); //显示“KEYES”，下同
  Lcd.Cursor(1, 0);
  Lcd.Display("ABCDEFGHIJKLMNOPQR");
  Lcd.Cursor(2, 0);
  Lcd.Display("123456789+-*/<>=$@");
  Lcd.Cursor(3, 0);
  Lcd.Display("%^&(){}:;'|?,.~\\[]");

}
