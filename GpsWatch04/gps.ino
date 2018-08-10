//#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <TinyGPS++.h>

#define RX_PIN D3
TinyGPSPlus gps;

//SoftwareSerial topgnss(RX_PIN, -1);

#define topgnss Serial

static bool isGpsUpdated=false;
static bool isTimeUpdated=false;
void gpsSetup(){
  topgnss.begin(9600);  
  pinMode(RX_PIN, INPUT);  
}

void gpsUpdate(){
  unsigned long age;
  byte hundredths;
  int year;
  tmElements_t tmSet;
  
  if(gps.satellites.isValid()){
    speed=gps.speed.kmph();
    course=gps.course.deg();
    latitude=gps.location.lat();
    longitude=gps.location.lng();
    sat_num=gps.satellites.value();
    course_cardinal=gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : " ";
    isGpsUpdated=true;
  }else{
    isGpsUpdated=false;
  }

  
  if(gps.time.isUpdated()){
    year=gps.date.year();
    tmSet.Month=gps.date.month();
    tmSet.Day=gps.date.day();
    tmSet.Hour=gps.time.hour();
    tmSet.Minute=gps.time.minute();
    tmSet.Second=gps.time.second();

    tmSet.Year = year - 1970;   // ime() returns the time as the number of seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
    //timeZoneAdjust
    //UTC_offset=ceil(longitude/15.);
    UTC_offset= int((longitude - 7.5) / 15) + 1 +1; //GMT9

    gps_time= makeTime(tmSet);
    local_time= gps_time+ (UTC_offset * SECS_PER_HOUR);    
    isTimeUpdated=true;
  }else{
    isTimeUpdated=false;   
  }
  
  smartdelay(700);
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

int getGpsSatNum(){
  int sat_num;
  sat_num=gps.satellites.value();
  if(gps.satellites.isValid()){
    return sat_num;
  }else{
    return 0;
  }
}




