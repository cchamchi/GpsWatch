#include <ESP8266WiFi.h>
#define WIFI_RETRIES 100
extern "C" {
#include "user_interface.h"
}


//char ssid[] = "SK_WiFi7915";
//char pass[] = "1307010367";

bool WiFi_Off() {
  
  int conn_tries = 0;
  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  wifi_set_sleep_type(MODEM_SLEEP_T);

  while ((WiFi.status() == WL_CONNECTED) && (conn_tries++ < WIFI_RETRIES)) {
    delay(100); 
  }
  if (WiFi.status() != WL_CONNECTED)
    return (true);
  else
    return (false);


    
}

bool WiFi_On() {
  
  int conn_tries = 0;

  //WiFi.forceSleepWake();
  WiFi.mode(WIFI_STA);
  wifi_station_connect();
//  WiFi.begin(ssid, pass);

  while ((WiFi.status() != WL_CONNECTED) && (conn_tries++ < WIFI_RETRIES)) {
  delay(100);

  }
  if (WiFi.status() == WL_CONNECTED)
    return (true);
  else
    return (false);
    

  return true;
}
