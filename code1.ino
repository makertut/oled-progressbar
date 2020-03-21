#include <SPI.h>

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>



#define OLED_RESET 4



Adafruit_SSD1306 display(OLED_RESET);



#if (SSD1306_LCDHEIGHT != 64)



#error("Height incorrect, please fix Adafruit_SSD1306.h!");



#endif


int p1 = random(0,100);

int p2 = random(0,100);

int p3 = random(0,100);



void setup() {



   // put your setup code here, to run once:



   // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)



   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)



   Serial.begin(9600);



}



void loop() {



    // Clear the buffer.



    display.clearDisplay();

 

    drawPercentbar( 0, 0, 50, 10,p1);



    drawPercentbar( 0, 20, 100, 15,p2);



    drawPercentbar( 0, 40, 128, 20,p3);



    display.display();

   

    p1++;p2++;p3++;

    if( p1 > 100) p1 =0;

    if( p2 > 100) p2 =0;

    if( p3 > 100) p3 =0;



    delay(100);



}



void drawPercentbar(int x,int y, int width,int height, int progress)

{



   progress = progress > 100 ? 100 : progress;

   progress = progress < 0 ? 0 :progress;



   float bar = ((float)(width-4) / 100) * progress; 

 

   display.drawRect(x, y, width, height, WHITE);

   display.fillRect(x+2, y+2, bar , height-4, WHITE);



 

  // Display progress text

  if( height >= 15){

    display.setCursor((width/2) -3, y+5 );

    display.setTextSize(1);

    display.setTextColor(WHITE);

   if( progress >=50)

     display.setTextColor(BLACK, WHITE); // 'inverted' text

     display.print(progress);

     display.print("%");

  }

}
