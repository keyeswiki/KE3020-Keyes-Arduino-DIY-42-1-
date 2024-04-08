/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 46
  紫外线报警
  http://www.keyes-robot.com
*/
int item = 0;
void setup() {
  pinMode(3, OUTPUT); //蜂鸣器接数字口3并设置为输出模式
}

void loop() {
  item = analogRead(A3);//读取紫外线传感器输出的模拟值
  if (item >= 20) {//强度高于20
    digitalWrite(3, HIGH);//蜂鸣器响起
  } else {//否则
    digitalWrite(3, LOW);//蜂鸣器关闭
  }
  delay(100);//延时100ms

}
