#include <SPI.h>


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);
static const unsigned char PROGMEM bat3[] = {
B00111111, B11111100,
 B00100000, B00000100,
 B00101101, B10110111,
 B00101101, B10110111,
 B00101101, B10110111,
 B00101101, B10110111,
 B00100000, B00000100,
 B00111111, B11111100,
};

static const unsigned char PROGMEM bat2[] = {
 B00111111, B11111100,
 B00100000, B00000100,
 B00101101, B10000111,
 B00101101, B10000111,
 B00101101, B10000111,
 B00101101, B10000111,
 B00100000, B00000100,
 B00111111, B11111100,
};

static const unsigned char PROGMEM bat1[] = {
 B00111111, B11111100,
 B00100000, B00000100,
 B00101100, B00000111,
 B00101100, B00000111,
 B00101100, B00000111,
 B00101100, B00000111,
 B00100000, B00000100,
 B00111111, B11111100,
};

static const unsigned char PROGMEM bat0[] = {
 B00111111, B11111100,
 B00100000, B00000100,
 B00100000, B00000111,
 B00100000, B00000111,
 B00100000, B00000111,
 B00100000, B00000111,
 B00100000, B00000100,
 B00111111, B11111100,
};




static const unsigned char PROGMEM ant4[] = {
 B11111110, B00000011,
 B01111100, B00000011,
 B00111000, B00011011,
 B00010000, B00011011,
 B00010000, B11011011,
 B00010000, B11011011,
 B00010110, B11011011,
 B00010110, B11011011,
};

static const unsigned char PROGMEM ant3[] = {
 B11111110, B00000000,
 B01111100, B00000000,
 B00111000, B00011000,
 B00010000, B00011000,
 B00010000, B11011000,
 B00010000, B11011000,
 B00010110, B11011000,
 B00010110, B11011000,
};
static const unsigned char PROGMEM ant2[] = {
 B11111110, B00000000,
 B01111100, B00000000,
 B00111000, B00000000,
 B00010000, B00000000,
 B00010000, B11000000,
 B00010000, B11000000,
 B00010110, B11000000,
 B00010110, B11000000,
};
static const unsigned char PROGMEM ant1[] = {
 B11111110, B00000000,
 B01111100, B00000000,
 B00111000, B00000000,
 B00010000, B00000000,
 B00010000, B00000000,
 B00010000, B00000000,
 B00010110, B00000000,
 B00010110, B00000000,
};

static const unsigned char PROGMEM antno[] = {
 B11111110, B00000000,
 B01111100, B00000000,
 B00111000, B10000100,
 B00010000, B01001000,
 B00010000, B00110000,
 B00010000, B00110000,
 B00010000, B01001000,
 B00010000, B10000100,
};
static const unsigned char PROGMEM  satellite [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xB2, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x41, 0xA0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x05, 0x80, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00,
0x00, 0x34, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00,
0x00, 0x68, 0x00, 0x02, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x01, 0x20, 0x00, 0x00, 0x00,
0x00, 0x0A, 0x00, 0x00, 0x11, 0xE0, 0x00, 0x00, 0x00, 0x05, 0x80, 0x00, 0x4F, 0xFC, 0x00, 0x00,
0x00, 0x03, 0x40, 0x00, 0x58, 0x06, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x57, 0xFB, 0x00, 0x00,
0x00, 0x00, 0x58, 0x00, 0x5F, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x34, 0x01, 0xBF, 0xFD, 0x00, 0x00,
0x00, 0x00, 0x0A, 0x02, 0x7F, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x05, 0xEC, 0xFF, 0xFA, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFB, 0xFF, 0xE2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x5F, 0xFF, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0xBF, 0xFE, 0x41, 0xA0, 0x00,
0x00, 0x00, 0x01, 0xBF, 0xFD, 0x80, 0x50, 0x00, 0x00, 0x00, 0x01, 0x7F, 0xFB, 0x00, 0x2C, 0x00,
0xF0, 0x38, 0x00, 0xBF, 0xF4, 0x00, 0x1A, 0x00, 0x50, 0x28, 0x00, 0x87, 0x14, 0x00, 0x05, 0x00,
0x50, 0x28, 0x00, 0x70, 0x74, 0x00, 0x02, 0xC0, 0x50, 0x14, 0x00, 0x1F, 0xCA, 0x00, 0x01, 0xA0,
0x50, 0x14, 0x00, 0x00, 0x08, 0x00, 0x00, 0x50, 0x28, 0x0A, 0x00, 0x00, 0x07, 0x80, 0x00, 0x2C,
0x28, 0x0D, 0x00, 0x00, 0x03, 0x40, 0x00, 0x36, 0x14, 0x04, 0x80, 0x00, 0x00, 0xB0, 0x00, 0x08,
0x14, 0x03, 0x40, 0x00, 0x00, 0x58, 0x00, 0xD0, 0x0A, 0x01, 0xA0, 0x00, 0x00, 0x34, 0x01, 0x60,
0x05, 0x00, 0x78, 0x00, 0x00, 0x0A, 0x02, 0x80, 0x06, 0x80, 0x1E, 0x00, 0x00, 0x05, 0x8D, 0x00,
0x03, 0x40, 0x07, 0xE0, 0x00, 0x03, 0x5E, 0x00, 0x00, 0xA0, 0x00, 0xFC, 0x00, 0x00, 0xAC, 0x00,
0x00, 0x58, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  // put your setup code here, to run once:

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display(); 
  // Clear the buffer.
  display.clearDisplay(); 

    // display.drawBitmap(x, y, array, widtg, height, Color(black/white));
  //display.drawBitmap(0,0, satellite, 64, 48, WHITE);
  //display.drawBitmap(0,0, face, 64, 64, WHITE);
  //display.drawBitmap(0,20, gps_receiving, 15, 15, WHITE);
  //display.drawBitmap(20,20, gps_disconnected, 15, 15, WHITE);

  display.drawBitmap(0,0, ant4,16, 8, WHITE);
  display.drawBitmap(48,0, bat3, 16, 8, WHITE);
  


  

}

void loop() {
  // put your main code here, to run repeatedly:

  display.clearDisplay();  
  display.drawBitmap(0,0, ant4,16, 8, WHITE);
  display.drawBitmap(48,0, bat3, 16, 8, WHITE);
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2,16);
  display.print("17:30");

  const char* month_list[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  int current_month = 8;//1 to 12
  const char* current_month_name = month_list[current_month-1];
    display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(6,40);

  char sz[10];
  sprintf(sz, "%s %d %s",current_month_name,2, current_month_name);
  display.print(sz);  
  display.display();

  delay(5000);

  display.clearDisplay();  
  display.drawBitmap(0,0, ant4,16, 8, WHITE);
  display.drawBitmap(48,0, bat3, 16, 8, WHITE);
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2,16);
  display.print("000");

    display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(42,23);
  display.print("kmh");  

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(16,33);
  display.print("SSW"); 
  
  display.display();  

  delay(5000);

  display.clearDisplay();  
  
  display.setTextSize(1);
  
  display.setCursor(0,0);
  display.setTextColor(BLACK, WHITE);
  display.println("Latitude  ");
  display.setTextColor(WHITE);
  display.println("E32.123456");
  display.setTextColor(BLACK, WHITE);
  display.println("Longitude ");
  display.setTextColor(WHITE);
  display.println("N127.12345");
  display.setTextColor(BLACK, WHITE);
  display.println("Altitude  ");
  display.setTextColor(WHITE);
  display.println("000.00"); 
  
  display.display();  

  delay(5000);


}