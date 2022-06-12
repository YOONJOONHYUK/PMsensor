#include <PMsensor.h>

PMsensor PM;

void setup() {
  Serial.begin(9600);
 
  /////(infrared LED pin, sensor pin)  /////
  PM.init(2, A0);  //2는 적외선 핀, a0는 센서핀


}

void loop() {
  Serial.println("=================================");
  Serial.println("Read PM2.5");

  float filter_Data = PM.read(0.1);  //float 실수, 소수둘째까지 읽겠다
  float noFilter_Data = PM.read();

  Serial.print("Filter : ");   //filter값이 우리가 원하는 값 (안정화된 값?)
  Serial.println(filter_Data);
  Serial.print("noFilter : ");  //바로 들어온 값 (nofilter 값의 0.9와 원래 nofilter값의 0.1을 곱해서 더한 값이 filter값?
  Serial.println(noFilter_Data);

  delay(1000);
}
