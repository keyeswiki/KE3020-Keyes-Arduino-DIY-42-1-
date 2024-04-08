/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 2
  交通灯模块
  http://www.keyes-robot.com
*/
int greenPin = 4;   //绿色LED接数字口D4
int yellowPin = 3; //黄色LED接数字口D3
int redPin = 2;   //红色LED接数字口D2
void setup() {
  //LED接口都设置为输出模式
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  digitalWrite(greenPin, HIGH); //点亮绿色LED
  delay(5000);  //延时5秒
  digitalWrite(greenPin, LOW); //关闭绿色LED
  for (int i = 1; i <= 3; i = i + 1) {  //运行三次
    digitalWrite(yellowPin, HIGH); //点亮黄色LED
    delay(500); //延时0.5秒
    digitalWrite(yellowPin, LOW); //关闭黄色LED
    delay(500); //延时0.5秒
  }
  digitalWrite(redPin, HIGH); //点亮红色LED
  delay(5000);  //延时5s
  digitalWrite(redPin, LOW); //关闭红色LED

}
