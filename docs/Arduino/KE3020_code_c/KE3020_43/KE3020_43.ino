/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 43
  呼吸灯
  http://www.keyes-robot.com
*/
int LED = 3; //LED管脚接数字口3

void setup() {
  pinMode(LED, OUTPUT);  //设置LED引脚为输出模式
}

void loop() {
  for (int i = 0; i <= 255; i++) {  //从0到255，每次加1
    analogWrite(LED, i);
    delay(10);//延时10ms
  }
  for (int i = 255; i >= 0; i--) {  //从255到0，每次减1
    analogWrite(LED, i);
    delay(10);//延时10ms
  }
}
