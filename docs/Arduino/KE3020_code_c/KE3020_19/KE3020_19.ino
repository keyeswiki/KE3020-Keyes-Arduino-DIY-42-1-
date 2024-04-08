/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 19
  水滴水蒸气传感器
  http://www.keyes-robot.com
*/
int val = 0;
int Water = A0; //水蒸气传感器的PIN为A0
void setup() {
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  val = analogRead(A0);  //读取水蒸气传感器的值
  Serial.print("Water:");
  Serial.println(val);
  delay(100);

}
