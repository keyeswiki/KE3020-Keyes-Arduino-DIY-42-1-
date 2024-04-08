/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 54
  火焰报警
  http://www.keyes-robot.com
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);//火焰传感器数字管脚接A0
  pinMode(3, OUTPUT);//蜂鸣器管脚接D3
}

void loop() {
  item = digitalRead(A0);//读取火焰传感器输出的数字电平
  Serial.println(item);//换行打印电平信号
  if (item == 0) {//检测到火焰
    digitalWrite(3, HIGH);//打开蜂鸣器
  } else {//否则，关闭蜂鸣器
    digitalWrite(3, LOW);
  }
  delay(100);//延时100ms

}
