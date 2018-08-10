#include <TimeLib.h>

float speed=0.,course=0.,latitude=0.,longitude=0.;
int sat_num=0;
//int year;
//byte month, day, hour, minute, second;
time_t gps_time,local_time;
int UTC_offset=0;

const char *course_cardinal;
void setup() {
  // put your setup code here, to run once:
  oledSetup();
  gpsSetup();
  WiFi_Off();

}

void loop() {
  // put your main code here, to run repeatedly:
  gpsUpdate();
  oledUpdate();

  //delay(500);
}
