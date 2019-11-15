#include <ESP8266WiFi.h>
WiFiServer server (80);

const char* ssid = "IX Basement-2.4G";
const char* pwd ="ixbasement@123";

void setup(){
  
  Serial.begin(115200);
  Serial.println("Connecting");

  WiFi.begin(ssid,pwd);
    
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println("Connected");

  Serial.print("IP Address  :");
  Serial.println(WiFi.localIP());

  Serial.print("Copy paste the IP Address:  ");
  Serial.println(WiFi.localIP());

  pinMode(LED_BUILTIN, OUTPUT);

  server.begin();
  Serial.println("Server Connected");
  }

void loop(){

  WiFiClient client = server.available();
  if (!client){
    return;
    }
   Serial.println("Waiting for client");
   while(!client.available()){
   delay(1); 
   }
   Serial.println("Client Connected");
   
   String request = client.readStringUntil('\r');
   Serial.println(request);
   client.flush();

  int value =LOW;
  if(request.indexOf("/LED=ON")!=-1){
  digitalWrite(LED_BUILTIN,HIGH);
  value = HIGH;}

  if(request.indexOf("/LED=OFF")!=-1){
  digitalWrite(LED_BUILTIN,LOW);
  value = LOW;
  }
  client.println("HTTP/1.1 200 OK"); // standalone web server with an ESP8266
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("LED: ");
 
  if(value == HIGH)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  }
  
