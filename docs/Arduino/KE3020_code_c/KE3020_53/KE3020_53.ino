/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 53
  模拟户外灯
  http://www.keyes-robot.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, OUTPUT);//LED管脚接D3
}

void loop() {
  val = analogRead(A1);//光敏电阻接A1
  Serial.println(val);//串口监视器打印光敏模拟值
  if (val < 150) {//模拟值低于150
    digitalWrite(3, HIGH);//点亮LED
  }
  else {//否则模拟值高于150
    digitalWrite(3, LOW);//熄灭LED
  }
  delay(100);//延时100ms

}
