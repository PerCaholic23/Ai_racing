#include <HUSKYLENS.h>
#include <POP32.h>
int Speed, BaseSpeed, LeftBaseSpeed, RightBaseSpeed, TurnSpeed, MaxSpeed, BackLeftBaseSpeed, BackRightBaseSpeed;
int Error, PreError, SumError, Kp, Kd, Ki;
HUSKYLENS huskylens;
void printResult(HUSKYLENSResult result);

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  while (!huskylens.begin(Serial1)) {Serial.println("Check your wiring. Green => TX, Red => RX"); delay(250);}
  Speed = 50;
  BaseSpeed = Speed;
  /////////////////////////
  Kp = 3;
  Kd = 8;
  Ki = 0;
  //////////////////////////
  InitialSpeed();
  oled.mode(3);
  oled.textSize(1);
  oled.text(7, 0, "ecstsy");
  oled.text(8, 0, "04/18/23");
  oled.show();
  beep(10);
  sw_ok_press();
}
void loop() {
  CalError();
  TracPID();
}
