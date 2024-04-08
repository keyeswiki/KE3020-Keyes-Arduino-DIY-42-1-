/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 44
  按键控制LED灯
  http://www.keyes-robot.com
*/
int button = 0;
void setup() {
  pinMode(8, INPUT);  //按键的管脚接数字口8并设置为输入模式
  pinMode(3, OUTPUT);  //LED的管脚接数字口3并设置为输出模式
}

void loop() {
  button = digitalRead(8);//读取按键值
  if (button == 0) {  //按下按键
    digitalWrite(3, HIGH); //点亮LED
  } else {  //松开按键
    digitalWrite(3, LOW); //熄灭LED
  }

}
