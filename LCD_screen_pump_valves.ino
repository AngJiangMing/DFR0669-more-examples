#include <Arduino.h>
#include <DFRobot_UI.h>
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"
#include <LongerPump.h>


#define water 32 //V1
#define solA 33 //V2
#define solB 34 //V3
#define product 35 //V4
#define TFT_DC 2
#define TFT_CS 3
#define TFT_RST 4

DFRobot_Touch_GT911 touch;
DFRobot_ILI9488_320x480_HW_SPI screen(TFT_DC,TFT_CS,TFT_RST);//LCD screen type
DFRobot_UI ui(&screen, &touch);


void btnCallback(DFRobot_UI::sButton_t &btn) {
Serial.begin(9600, SERIAL_8E1);
String text((char *)btn.text);
digitalWrite(solA,LOW); // solution A open
digitalWrite(product,LOW); // reactor open
run(1,275,25,1);// 275 is pump speed and 25 is revolutions
delay(5000);
digitalWrite(solA,HIGH); // solution A close
run(1,275,5,1);// 275 is pump speed and 5 is revolutions
delay(5000);
digitalWrite(solB,LOW); // solution B open
run(1,275,25,1);// 275 is pump speed and 25 is revolutions
delay(5000);
digitalWrite(solB,HIGH); // solution B close
run(1,275,5,1);// 275 is pump speed and 5 is revolutions
delay(5000);
digitalWrite(water,LOW); // water open
run(1,275,25,1);// 275 is pump speed and 25 is revolutions
delay(5000);
digitalWrite(water,HIGH); // water close
digitalWrite(product,LOW); // reactor open
run(1,275,5,1);// 275 is pump speed and 5  is revolutions
delay(5000);
digitalWrite(product,HIGH);
stop(1);
}

void setup() {
Serial.begin(9600);
ui.begin();
ui.setTheme(DFRobot_UI::MODERN);
pinMode(water, OUTPUT);//set the pin as output
pinMode(solA, OUTPUT);//set the pin as output
pinMode(solB, OUTPUT);//set the pin as output
pinMode(product, OUTPUT);//set the pin as output
stop(1);//to stop the pump from spinning
DFRobot_UI::sButton_t & btn1 = ui.creatButton();//creates a button
btn1.setText("AUTO");//text on the button
btn1.bgColor = COLOR_RGB565_PURPLE;//colour of button
btn1.setCallback(btnCallback);//sets a function when button is pressed
ui.draw(&btn1,screen.width()/10,screen.height()/2,screen.width()/10*2,screen.width()/10*2);
//button position 
digitalWrite(water, HIGH);//V1 closed
digitalWrite(solA, HIGH);//V2 closed
digitalWrite(solB, HIGH);//V3 closed
digitalWrite(product,HIGH);//V4 closed
}


void loop() {
ui.refresh();
}

