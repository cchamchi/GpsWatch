#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define RX_PIN D3
TinyGPS gps;

SoftwareSerial topgnss(RX_PIN, -1);

void gpsSetup(){
  topgnss.begin(9600);  
  pinMode(RX_PIN, INPUT);  
}

void gpsUpdate(){
  unsigned long age;
  byte hundredths;
  
  if(gps.satellites() !=TinyGPS::GPS_INVALID_SATELLITES){
    speed=gps.f_speed_kmph();
    course=gps.f_course();
    gps.f_get_position(&latitude, &longitude, &age);
    sat_num=gps.satellites();
    gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
    course_cardinal=TinyGPS::cardinal(course);
    gps_valid=true;
  }else{
    gps_valid=false;
  }
  smartdelay(500);
}
static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (topgnss.available())
      gps.encode(topgnss.read());
  } while (millis() - start < ms);
}
