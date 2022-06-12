#include <PMsensor.h>    //미세먼지센서 헤더파일
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>     //lcd 헤더파일

LiquidCrystal_I2C lcd(0x3F,16,2);     //lcd의 주소와 규격

PMsensor PM;
 int redPin = 3;      int greenPin = 5;       int bluePin = 6;
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);   pinMode(greenPin, OUTPUT);  pinMode(bluePin, OUTPUT);
  /////(infrared LED pin, sensor pin)  /////
  PM.init(2, A0);     //2는 적외선 핀, a0는 센서핀


}

void loop() {
  Serial.println("=================================");
  Serial.println("Read PM2.5");

  float filter_Data = PM.read(0.1);  //float 실수, 0.1은 10%만 읽겠다
  float noFilter_Data = PM.read(); //PM.read는 

  Serial.print("Filter : ");   //filter값이 우리가 원하는 값 (안정화된 값?)
  Serial.println(filter_Data);
  Serial.print("noFilter : ");  //지금 들어온 값 (filter 값의 0.1와 원래 nofilter값의 0.9를 곱해서 더한 값이 filter값?
  Serial.println(noFilter_Data);

   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Filter : ");
  lcd.print(filter_Data);


  if (0< filter_Data <= 30) 
  { setColor(0, 255, 0); delay(100); }

  if (filter_Data <= 80 && filter_Data>30 )  { setColor(0,0,255);
        delay(100);}
        
   if ( filter_Data > 80)
   { 
    setColor(255, 0, 0); 
   delay(100);
      }



  delay(100);
}

  void setColor(int red, int green, int blue)   //일일이 사용하지 않고 간단하게 색을 사용할 수 있도록 하는 명령어
     {
       analogWrite(redPin, red);
       analogWrite(greenPin, green);
       analogWrite(bluePin, blue); 
     }
