/*!
 * @file UI_tableview.ino
 * @brief Create a tableview control on the screen, and the control parameters can be defined by users.
 * @n Users can choose different pages to display different contents
 * @n The demo supports Mega2560, FireBeetle-ESP32, FireBeetle-ESP8266, FireBeetle-M0
 *
 * @copyright Copyright (c) 2010 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [fengli] (li.feng@dfrobot.com)
 * @version V1.0
 * @date 2019-12-6
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_GDL/src/DFRpbot_UI
*/
#include "DFRobot_UI.h"
#include "Arduino.h"
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"
#include <Servo.h>
#include <uRTCLib.h>

uRTCLib rtc(0x68);

/*M0*/
#if defined ARDUINO_SAM_ZERO
#define TFT_DC  7
#define TFT_CS  5
#define TFT_RST 6
/*ESP32 and ESP8266*/
#elif defined(ESP32) || defined(ESP8266)
#define TFT_DC  D2
#define TFT_CS  D6
#define TFT_RST D3
/* AVR series mainboard */
#else
#define TFT_DC  2
#define TFT_CS  3
#define TFT_RST 4
#define red_LED 24
#define yellow_LED 23
#define green_LED 22
#define red 30
#define blue 35
#define green 28
#define servoPin 10
#endif
unsigned int servoPos;

/**
   @brief Constructor  When the touch uses the gt series chip, you can call this constructor
*/
DFRobot_Touch_GT911 touch;

/**
   @brief Constructor When the screen uses hardware SPI communication, the driver IC is st7789, and the screen resolution is 240x320, this constructor can be called
   @param dc Command/data line pin for SPI communication
   @param cs Chip select pin for SPI communication
   @param rst Reset pin of the screen
*/
DFRobot_ILI9488_320x480_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
/* M0 mainboard DMA transfer */
//DFRobot_ILI9488_320x480_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);


/**
   @brief Constructor
   @param gdl Screen object
   @param touch Touch object
*/
DFRobot_UI ui(&screen, &touch);
void btnCallback(DFRobot_UI::sButton_t &btn) {
   String text((char *)btn.text);
   if(text == "RED"){
    digitalWrite(red_LED,HIGH);
    }
   else if(text == "YELLOW"){
    digitalWrite(yellow_LED,HIGH);
    }
   else if(text=="GREEN"){
     digitalWrite(green_LED,HIGH);      
      }
   else if(text=="R OFF"){
     digitalWrite(red_LED,LOW);    
    }
   else if(text == "Y OFF"){
    digitalWrite(yellow_LED,LOW);
    }
   else if (text== "G OFF"){
     digitalWrite(green_LED,LOW);
   }
  
}

void changeColor(DFRobot_UI::sSlider_t &slider,DFRobot_UI::sTextBox_t &textBox) {
  String s(slider.value);
  textBox.setText("slider's value is " + s);
  if (slider.value>10 && slider.value<=30 ) {
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW); 
  }
  else if(slider.value>30 && slider.value<=60) {
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
  }
  else if (slider.value>60) {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
  }

  else if (slider.value<=10) {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);

  }
}

void btnCallback2(DFRobot_UI::sButton_t &btn) {
   String text((char *)btn.text);
   if(text == "0"){
    digitalWrite(servoPin,HIGH);
    servoPos=500;
    }
   else if(text == "90"){
    digitalWrite(servoPin,HIGH);
    servoPos=1450;
    }
   else if(text=="180"){
     digitalWrite(servoPin,HIGH);
     servoPos=2350;      
      }
  
}


void tbCallback(void * highLightPage){
  uint8_t * hl = (uint8_t *)highLightPage;
  switch (*hl) {
     case 1:{
       DFRobot_UI::sButton_t & btn1 = ui.creatButton();
       btn1.setText("RED");
       btn1.bgColor = COLOR_RGB565_RED;
       btn1.setCallback(btnCallback);
       ui.draw(&btn1,/**x=*/screen.width()/10,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn2 = ui.creatButton();
       btn2.setText("YELLOW");
       btn2.bgColor = COLOR_RGB565_YELLOW;
       btn2.setCallback(btnCallback);
       ui.draw(&btn2,/**x=*/(screen.width()/10)*4,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn3 = ui.creatButton();
       btn3.setText("GREEN");
       btn3.bgColor = COLOR_RGB565_GREEN;
       btn3.setCallback(btnCallback);
       ui.draw(&btn3,/**x=*/(screen.width()/10)*7,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn4 = ui.creatButton();
       btn4.setText("R OFF");
       btn4.bgColor = COLOR_RGB565_BLUE;
       btn4.setCallback(btnCallback);
       ui.draw(&btn4,/**x=*/screen.width()/10,/**y=*/screen.height()/1.5,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn5 = ui.creatButton();
       btn5.setText("Y OFF");
       btn5.bgColor = COLOR_RGB565_BLUE;
       btn5.setCallback(btnCallback);
       ui.draw(&btn5,/**x=*/screen.width()/10*4,/**y=*/screen.height()/1.5,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn6 = ui.creatButton();
       btn6.setText("G OFF");
       btn6.bgColor = COLOR_RGB565_BLUE;
       btn6.setCallback(btnCallback);
       ui.draw(&btn6,/**x=*/screen.width()/10*7,/**y=*/screen.height()/1.5,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       break;

      }
    
    case 2: {
       
       DFRobot_UI::sSlider_t &slider = ui.creatSlider();
       slider.setCallback(changeColor);
       ui.draw(&slider,/*x = */(screen.width() - slider.width) / 2,/*y = */(screen.height() - 2 - 1) / 3 * 1 + 2 + 1);
       break;

        }
     case 3:  {
       DFRobot_UI::sButton_t & btn1 = ui.creatButton();
       btn1.setText("0");
       btn1.bgColor = COLOR_RGB565_BLUE;
       btn1.setCallback(btnCallback2);
       ui.draw(&btn1,/**x=*/screen.width()/10,/**y=*/screen.height()/1.3,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

       DFRobot_UI::sButton_t & btn2 = ui.creatButton();
       btn2.setText("90");
       btn2.bgColor = COLOR_RGB565_BLUE;
       btn2.setCallback(btnCallback2);
       ui.draw(&btn2,/**x=*/screen.width()/10*4,/**y=*/screen.height()/1.3,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

      DFRobot_UI::sButton_t & btn3 = ui.creatButton();
       btn3.setText("180");
       btn3.bgColor = COLOR_RGB565_BLUE;
       btn3.setCallback(btnCallback2);
       ui.draw(&btn3,/**x=*/screen.width()/10*7,/**y=*/screen.height()/1.3,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);
       }
     case 4:  {
       ui.drawString(10,200,"bye c:",COLOR_RGB565_BLUE,ui.bgColor,3,0);break;
       }
      }
  }

void setup()
{

  pinMode(red_LED,OUTPUT);
  pinMode(yellow_LED,OUTPUT);
  pinMode(green_LED,OUTPUT);

  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);

  pinMode(servoPin,OUTPUT);

  Serial.begin(9600);
  ui.begin();
  ui.setTheme(DFRobot_UI::MODERN);

  DFRobot_UI::sTableview_t &tb = ui.creatTableview();//Create a tableview control
  tb.setName(/*page=*/4,/*page1 name=*/"tab1",/*page2 name=*/"tab2",/*page3 name=*/"tab3",/*page4 name=*/"tab4");//Set the number and name of tableview, at most 4 pages.
  tb.setCallback(tbCallback);//Set callback function
  ui.draw(&tb);


}
void loop()
{  
   //refresh
   digitalWrite(servoPin, HIGH);
   delayMicroseconds(servoPos); // Duration of the pusle in microseconds
   digitalWrite(servoPin, LOW);
   delayMicroseconds(20000-servoPos); // 20ms - duration of the pusle. 18550
   ui.refresh();

}
