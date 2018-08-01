#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

void oledSetup(){
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(5000);  
  // Clear the buffer.
  display.clearDisplay();  
}

void oledUpdate(){
  if(gps_valid){
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
    hour+=9;  // GMT+9 ... also the date need tobe change
    hour%=24;  //to auto Time loaction change by latitude
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ",
        month, day, year, hour, minute, second);
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

