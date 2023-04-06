#include "DFRobot_UI.h"
#include "Arduino.h"
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"
#include<stdio.h>
#include<stdlib.h>

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
#endif
#define redledPin 32
#define greenledPin 23
#define yellowledPin 24


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
void btnCallback(DFRobot_UI::sButton_t &btn,DFRobot_UI::sTextBox_t &obj) {
   String text((char *)btn.text);
    if (text == "RED"){
    obj.setText("Red LED is turned ON");
    digitalWrite(redledPin,HIGH);
    }
    else if(text == "GRN"){
    obj.setText("Green LED is turned ON");
    digitalWrite(greenledPin,HIGH);
    }
    else if(text == "clr"){
    obj.setText("Both Red and Green LED are turned OFF");
    digitalWrite(redledPin,LOW);
    digitalWrite(greenledPin,LOW);
    }
    else if (text == "rOFF"){
    obj.setText("Red Led is turned OFF");
    digitalWrite(redledPin,LOW);
    }
    else if (text == "gOFF") {
    obj.setText("Green Led is turned OFF");
    digitalWrite(greenledPin,LOW);
    }
}


void setup()
{
  pinMode(greenledPin,OUTPUT);
  pinMode(redledPin,OUTPUT);
  pinMode(yellowledPin,OUTPUT);
 
  Serial.begin(9600);
  ui.begin();
  // Set the UI theme, there are two themes to choose from: CLASSIC and MODERN.
  ui.setTheme(DFRobot_UI::MODERN);
 
 
  while(true){
     //refresh
     ui.refresh();
     
     
    // getGestures()： Get gesture
    switch(ui.getGestures()){
      //setText：let the text box display a string
      case ui.SDOWNGLIDE :
      
      DFRobot_UI::sTextBox_t & tb = ui.creatText();
      tb.bgColor = 0xe6B6;
      ui.draw(&tb);
      DFRobot_UI::sButton_t & btn1 = ui.creatButton();
      btn1.setText("RED");
      btn1.bgColor = COLOR_RGB565_RED;
      btn1.setCallback(btnCallback);
  //Each button has a text box, its parameter needs to be set by yourself.
      btn1.setOutput(&tb);
      ui.draw(&btn1,/**x=*/screen.width()/10,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);


      DFRobot_UI::sButton_t & btn2 = ui.creatButton();
      btn2.setText("GRN");
      btn2.bgColor = COLOR_RGB565_GREEN;
      btn2.setCallback(btnCallback);
  //Each button has a text box, its parameter needs to be set by yourself.
      btn2.setOutput(&tb);
      ui.draw(&btn2,/**x=*/(screen.width()/10)*4,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);
 
      DFRobot_UI::sButton_t & btn3 = ui.creatButton();
      btn3.bgColor = COLOR_RGB565_BLUE;
      btn3.setText("clr");
      btn3.setCallback(btnCallback);
  //Each button has a text box, its parameter needs to be set by yourself.
      btn3.setOutput(&tb);
      ui.draw(&btn3,/**x=*/(screen.width()/10)*7,/**y=*/screen.height()/2,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);

      DFRobot_UI::sButton_t & btn4 = ui.creatButton();
      btn4.setText("rOFF");
      btn4.bgColor = COLOR_RGB565_RED;
      btn4.setCallback(btnCallback);
  //Each button has a text box, its parameter needs to be set by yourself.
      btn4.setOutput(&tb);
      ui.draw(&btn4,/**x=*/screen.width()/10,/**y=*/screen.height()/1.5,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);


     DFRobot_UI::sButton_t & btn5 = ui.creatButton();
     btn5.setText("gOFF");
     btn5.bgColor = COLOR_RGB565_GREEN;
     btn5.setCallback(btnCallback);
  //Each button has a text box, its parameter needs to be set by yourself.
     btn5.setOutput(&tb);
     ui.draw(&btn5,/**x=*/(screen.width()/10)*4,/**y=*/screen.height()/1.5,/*width*/screen.width()/10*2,/*height*/screen.width()/10*2);
     break;
     
      case ui.SUPGLIDE : break;
      case ui.SLEFTGLIDE : break;
      case ui.SRIGHTGLIDE : break;
      case ui.DLONGPRESSED : break;
      case ui.SCLICK : break;
      case ui.DDOUBLECLICK : break;
      default  :  break;
      }
  }
}
void loop()
{
}


















