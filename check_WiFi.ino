#include <ESP8266WiFi.h>

const char* ssid = "IX Basement-2.4G";
const char* pwd ="ixbasement@123";

void setup(){
  
  Serial.begin(115200);
  Serial.println("Connecting");

  WiFi.begin();
    
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("Connected");
  }

void loop(){
  }
  
