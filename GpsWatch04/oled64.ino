#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern 

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

void oledSetup(){
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen. 
  // Clear the buffer.
  display.clearDisplay();  
  displayLogo();
}

bool pingpong;
void oledUpdate(){

  if(isGpsUpdated){
    if(isTimeUpdated){
      display.clearDisplay();
      drawAntBat();
      if(!(gps.time.second()%5)){
        pingpong^=1;
      }
      pingpong? drawSpeed():drawWatch();
        
      display.display();
    }    
  }else{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,16);
    display.println("Searching");
    display.println("");
    display.println("GPS signal");
 
    display.display();    
  }



  //displayDebug();
}
void displayLogo(){
  display.clearDisplay(); 
  display.drawBitmap(0,0, satellite, 64, 48, WHITE);
  display.display();
  delay(3000);
}
void drawAntBat(){
  const unsigned char *ant_bitmap,*bat_bitmap;
  ant_bitmap=getAntennaBitmap();
  bat_bitmap=getBatBitmap();
  display.drawBitmap(0,0, ant_bitmap,16, 8, WHITE);
  display.drawBitmap(48,0, bat_bitmap, 16, 8, WHITE);
  
}
void drawWatch(){

  char sz[32];
  int year;
  tmElements_t tmSet;
  breakTime(local_time, tmSet);
  year=tmSet.Year+1970;

  sprintf(sz, "%02d:%02d",tmSet.Hour, tmSet.Minute);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2,16);
  display.print(sz); 
  
  String st;
  st=dayShortStr(dayOfWeek(local_time))+String(" ")+String(tmSet.Day)+String(" ")+monthShortStr(tmSet.Month);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(4,40);
  display.print(st);

  
}
void displayDebug(){
  if(isGpsUpdated){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("E");  // Todo : change E of W by sign of Latitude
    display.println(latitude,6);
    display.print("N"); // Todo : change N of S by sign of Longitude
    display.println(longitude,5);

    
    display.print(course_cardinal);
    display.print("/");
    display.print("Sat");
    display.println(sat_num); 
    display.print(int(speed));
    display.println("km/h");
  
    char sz[32];
    int year;
    tmElements_t tmSet;
    breakTime(local_time, tmSet);
    year=tmSet.Year+1970;
    sprintf(sz, "%02d/%02d/%02d",tmSet.Month, tmSet.Day, year);
    display.println(sz);
    sprintf(sz, "% 02d:%02d:%02d",tmSet.Hour, tmSet.Minute, tmSet.Second);
    display.println(sz);        
    display.display();
  }else{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,4);
    display.println("Searching..");
 
    display.display();
  
  }  
}

void drawSpeed(){
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2,16);
  String st;
  char sz[10];
  
  sprintf(sz, "%3d",int(speed));
  display.print(sz);

    display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(42,23);
  display.print("kmh");  

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(16,33);
  st=course_cardinal;
  display.print(st);
  
}


