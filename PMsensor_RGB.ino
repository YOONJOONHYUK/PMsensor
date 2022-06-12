#include <PMsensor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

PMsensor PM;
 int redPin = 3;      int greenPin = 5;       int bluePin = 6;
void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);          pinMode(greenPin, OUTPUT);
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

  if (PM.read(0.1) <= 30) { setColor(0, 255, 0); delay(1000); }

  else { 
    if (30 < PM.read(0.1) < 80) { setColor(0,0,255); delay(1000); }
    else { setColor(255, 0, 0); delay(1000);}
  }

   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Filter : ");
  lcd.print(filter_Data);
  
}

  delay(1000);
}

void setColor(int red, int green, int blue)
     {
       analogWrite(redPin, red);
       analogWrite(greenPin, green);
       analogWrite(bluePin, blue); 
     }
