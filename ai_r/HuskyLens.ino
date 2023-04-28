void printResult(HUSKYLENSResult result) {
  Serial.println(String() + F("X= ") + result.xTarget);
}
void CalError()
{
  if (!huskylens.request());
  else if (!huskylens.isLearned());
  else if (!huskylens.available());
  else
  {
    while (huskylens.available())
    {
      HUSKYLENSResult result = huskylens.read();
      Error = map(result.xTarget, 32, 280, -6, 6);
    }
  }
}
