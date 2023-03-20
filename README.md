# DFR0669-more-examples
Made during TP Experential Research Programme (ERP) in collaboration with Neo Yu Yun, Praveena Regunathan, Philip Yeo

## General Guide



# CODE EXPLANATION

StackEdit stores your files in your browser, which means all your files are automatically saved locally and are accessible **offline!**

## Tableview / tabs

```
void  tbCallback(void  *  highLightPage){
	uint8_t * hl = (uint8_t *)highLightPage;
	switch  (*hl)  {

		case  1: {
			<your code here>
			break;
		}

		case  2: {
			<your code here>
			break;
		}

		case  3: {
			<your code here>
			break;
		}

		case  4: {
			<your code here>
			break;
		}
	}
}
```


---
For Our Code:
- `tbCallback` generates the UI to include tabs
- `case 1:` Displays ON and OFF buttons for users to control 3 LEDs (red, yellow, green)
- `case 2:` Displays a slider that allows users to control RGB tri-color LED. Depending on the slider's value, the LED would either turn off or display RGB colors
- `case 3:` Displays three buttons that control the servo motor. 
- `case 4:` Displays a text message
---

`tbCallback(void * highLightPage)` requires the case syntax to function, it automatically detects the number of cases and registers them as different tabs, and will construct tab buttons on the top of the screen.

The code under each `case` will be what is displayed/constructed under each tab

##  Buttons
```
	DFRobot_UI::sButton_t & btn1 = ui.creatButton();
	btn1.setText("0");
	btn1.bgColor = COLOR_RGB565_BLUE;
	btn1.setCallback(btnCallback2);
	ui.draw(&btn1,screen.width()/10,screen.height()/1.3,screen.width()/10*2,screen.width()/10*2);
```
`sButton_t & btn1 = ui.creatButton()` allows you to create a button on the LCD touch screen.
- `sButton_t` is needed to create a button on the screen. 
	- If you want to display another feature, e.g, a textbox, you will replace `sButton_t` with `sTextbox_t`
- `btn1` > button name
- `ui.creatButton()` > function to create the button

`btn1.setText("0");` allows you to put text in the button
`btn1.bgColor = COLOR_RGB565_BLUE;` sets the background color of the button
`btn1.setCallback( <function name> );` calls back fun with button functions
- `setCallback( function )`  sets the function to be called when button 1 is pressed.
	- The parameter is an arbitrarily named,  defined function. 
	- Example function is shown below
```
void  btnCallback2(DFRobot_UI::sButton_t  &btn)  {
	String text((char *)btn.text);

	if(text == "0"){
		digitalWrite(servoPin,HIGH);
		servoPos=500;
	}
	else  if(text == "90"){
		digitalWrite(servoPin,HIGH);
		servoPos=1450;
	}
	else  if(text=="180"){
		digitalWrite(servoPin,HIGH);
		servoPos=2350;
	}
}
```
`ui.draw();`
 - ui.draw( object, x, y, width, height )

## Slider
```
DFRobot_UI::sSlider_t &slider = ui.creatSlider();
slider.setCallback(changeColor);
ui.draw(&slider,(screen.width() - slider.width) / 2,(screen.height() - 2 - 1) / 3 * 1 + 2 + 1);
```
- similar to button function
## Text
```
ui.drawString(10,200,"bye c:",COLOR_RGB565_BLUE,ui.bgColor,3,0);
```
`drawString()` allows you to display a text message on the LCD touchscreen
- drawString( x, y, text message, text color , background color, font size, font display mode)

# setup 

This project uses an Arduino Mega 2560, DFR0669 LCD Touch screen, 4 light emitting diodes(LED) ,RGB Tricolor LED, 3 220 ohm resistors and  a Tower Pro micro servo 9g 


### 1)  LCD Touch Screen to the Arduino Mega :

  | LCD pins 	 | Arduino Mega pins |
  |------------|-------------------|
  |VCC    |   any 5V               |
  |GND     |  any GND |
  |SCLK  | Digital Pin 52| 
  |MOSI  |Digital Pin 51|
  |MISO| Digital Pin 50|
  |CS| Digital PIN 3|
  |RES| Digital PIN 4|
  |DC| Digital PIN 2|
  |SCL| SCL 1|
  |SDCS| SDA 1|

###  2) Tricolored LED to Arduino Mega:
When connecting the all RBG Tricolor LED pins to the Arduino Mega use a 220 ohm resistor as a junction 
| RGB Tricolor Led | Arduino Mega pins |
|------------|-------------------|
|-  |   any GND               |
|B    |  Digital Pin 35|
|R | Digital Pin 30| 
|G |Digital Pin 28|

###  3) LED To Arduino Mega:
You can use a breadboard for easier connection 
| LEDs | Arduino Mega pins |
|------------|-------------------|
|cathode of all LEDs|   any GND               |
|anode of 1st  LED  |  Digital Pin 24|
|anode of 2nd LED | Digital Pin 23| 
|anode of 3rd LED |Digital Pin 22|

### 4)  Tower Pro micro servo 9g to Arduino Mega :
| Tower Pro micro servo | Arduino Mega pins |
|------------|-------------------|
|orange wire|   Digital Pin 10              |
|Brown Wire |  any GND|
|Red wire| VCC| 













