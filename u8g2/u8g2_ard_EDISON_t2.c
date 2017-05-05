//MY VERY RAW TEST OF U8G2 SETUP WITH EDISON.
//This demo was taken from Oliver Kraus U8g2 library and modified for my needs accordingly.
//All credits to Oliver
 
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

/* Constructor */
//U8G2_LCD PINOUT DEFINITION  /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8)==> MUST STAY LIKE THAT
//REPLACED SAMPLE CONSTRUCTOR WITH MY VERSION OF DISPLAY , SOFTWARE SPI AND PINOUT FOR EDISON
U8G2_PCD8544_84X48_F_4W_SW_SPI u8g2(U8G2_R0, 13, 11 , 10, 9 , 8); // Worked fine with my setup on Arduino Mini Pro and Uno3.
// Now it had to be verified with EDISON
/* u8g2.begin() is required and will sent the setup/init sequence to the display */
void setup(void) {
//NO BACKLIGHT CONTROL FOR THE TEST NEEDED
  u8g2.begin();
}

/* draw something on the display with the `firstPage()`/`nextPage()` loop*/
void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr); // JUST SELECTED A BIG FONT
    u8g2.drawStr(0,20,"Hello K.");
  } while ( u8g2.nextPage() );
  delay(1000);
}

