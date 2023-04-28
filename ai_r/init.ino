void InitialSpeed() {
  LeftBaseSpeed = BaseSpeed - 5;
  RightBaseSpeed = BaseSpeed - 0;
  BackLeftBaseSpeed = BaseSpeed - 5;
  BackRightBaseSpeed = BaseSpeed - 0;
  TurnSpeed = BaseSpeed - 0;
  MaxSpeed = Speed;
}

void calMotor(char T, int SPD, int DEL ){
  switch(T){
    case 'F' : fd(SPD); delay(DEL); ao(); delay(100); break;
    case 'B' : bk(SPD); delay(DEL); ao(); delay(100); break;
    default : break;
  }
}
