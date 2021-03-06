

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

const unsigned char* getAntennaBitmap(){
  int ant_num,num_sat;
  num_sat=getGpsSatNum();
    
    if(num_sat<3)return antno;
    if(num_sat>10)return ant4;
    ant_num= map(num_sat,3,10,1,4);
    switch(ant_num){
      case 1:
        return ant1;
      break;
      case 2:
        return ant2;
      break;
      case 3:
        return ant3;
      break;
      case 4:
        return ant4;
      break;
    }
  
}
const unsigned char* getBatBitmap(){
/*
  int ant_num;
  ant_num=getGpsAntNum();
    
    if(num_sat<4)return antno;
    if(num_sat>12)return ant4;
    ant_num= map(num_sat,4,12,1,4);
    switch(ant_num){
      case 1:
        return ant1;
      break;
      case 2:
        return ant2;
      break;
      case 3:
        return ant3;
      break;
      case 4:
        return ant4;
      break;
    }
*/
  return bat3;
}
