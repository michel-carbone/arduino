//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

  This program will test the LCD panel and the buttons
  Mark Bramwell, July 2010
  Edits by Michel Carbone, Augustus 2018
********************************************************/
/* convention of pin naming:
   device, e.g. LCD
   pin type & direction at module, e.g. DO for Digital Output
   pin name at module location
*/
// pin-out of LCD Keypad VMA203
#define LCD_AO_AnalogButtons  0
#define LCD_DO_DB4 4
#define LCD_DO_DB5 5
#define LCD_DO_DB6 6
#define LCD_DO_DB7 7
#define LCD_DO_RS 8
#define LCD_DO_EN 9
#define LCD_DO_BacklitCtrl 10

// select the pins used on the LCD panel
LiquidCrystal lcd(LCD_DO_RS, LCD_DO_EN, LCD_DO_DB4, LCD_DO_DB5, LCD_DO_DB6, LCD_DO_DB7);

// define some values used by the panel and buttons
int lcd_key     = 0; //index of pushed button
int adc_key_in  = 0; //analog value read by the ADC
// user friendly name for value to store in lcd_key variable
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5 // default value

// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(LCD_AO_AnalogButtons);      // read the value from the sensor
  // my buttons when read are centered at these values: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */


  return btnNONE;  // when all others fail, return this...
}

void setup()
{
  lcd.begin(16, 2);              // start the library
  lcd.clear();
  pinMode(LCD_DO_BacklitCtrl, OUTPUT);
}

void loop()
{
  //lcd.setCursor(9,1);            // move cursor to second line "1" and 9 spaces over
  // lcd.print(millis()/1000);      // display seconds elapsed since power-up
  //
  //
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);            // move to the begining of the first line
  String text = "My brother...";
  lcd.print(text);
  delay(1000);
  for(int i= 0; i<3; i++)
  {
    digitalWrite(LCD_DO_BacklitCtrl, HIGH); 
    delay(250);
    digitalWrite(LCD_DO_BacklitCtrl, LOW); 
    delay(250);
  }
  digitalWrite(LCD_DO_BacklitCtrl, HIGH); 
  lcd.setCursor(0,1);            // move to the begining of the second line
  lcd.print("Happy Birthday!!");
  delay(1000);
  
  
  switch (lcd_key)               // depending on which button was pushed, we perform an action
  {
    case btnRIGHT:
      {
        //lcd.print("RIGHT ");
        break;
      }
    case btnLEFT:
      {
        //lcd.print("LEFT   ");
        break;
      }
    case btnUP:
      {
        //lcd.print("UP    ");
        break;
      }
    case btnDOWN:
      {
        //lcd.print("DOWN  ");
        break;
      }
    case btnSELECT:
      {
        //lcd.print("SELECT");
        break;
      }
    case btnNONE:
      {
        //lcd.print("NONE  ");
        break;
      }
  }

}
