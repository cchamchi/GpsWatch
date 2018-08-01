
float speed=0.,course=0.,latitude=0.,longitude=0.;
int sat_num=0;
int year;
byte month, day, hour, minute, second;
bool gps_valid=false;
const char *course_cardinal;
void setup() {
  // put your setup code here, to run once:
  oledSetup();
  gpsSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  gpsUpdate();
  oledUpdate();

  //delay(500);
}
