/*
  Keyes Arduino DIY电子积木 42合1 传感器套装
  课程 34
  红外接收
  http://www.keyes-robot.com
*/
#include <IRremote.h>
int RECV_PIN = 10;//定义数字口10
IRrecv irrecv(RECV_PIN);
decode_results results;//声明一个IRremote库函数独有的变量类型(decode_resultc)

void setup() {
  Serial.begin(9600);//设置波特率
  irrecv.enableIRIn();// 使能红外接收
}

void loop() {
  if (irrecv.decode(&results)) { //是否接收到红外遥控信号
    Serial.println(results.value, HEX); //显示数据
    irrecv.resume();  //接收下个数据
  }
}
