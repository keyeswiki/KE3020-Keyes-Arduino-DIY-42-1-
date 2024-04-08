/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 49
  灭火机器人
  http://www.keyes-robot.com
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  item = analogRead(A5);//火焰传感器接A5，读取火焰传感器的模拟值赋给item
  Serial.println(item);//串口显示模拟值
  if (item < 200) {//低于200
    digitalWrite(A0, LOW);//打开风扇
    digitalWrite(A1, HIGH);
  } else {//否则关闭风扇
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
  }
  delay(100);
}
