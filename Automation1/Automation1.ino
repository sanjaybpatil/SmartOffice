
 
#include <ESP8266WiFi.h>
#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12  
#define D7  13
 
const char* ssid     = "ESP8266";
const char* password = "Password123";

WiFiServer server(8080);

void doSwitch(WiFiClient client)
{


while(1)
{


String req = client.readStringUntil('\r');
Serial.println(req);
client.flush();

String pin,level;
  if(req.indexOf("01") != -1)
  {
    digitalWrite(D0,LOW);
    pin = "D0";
    level = "LOW";
  }
else  if(req.indexOf("02") != -1)
  {
    digitalWrite(D1,LOW);
    pin = "D1";
    level = "LOW";
  }
else  if(req.indexOf("03") != -1)
  {
    digitalWrite(D2,LOW);
    pin = "D2";
    level = "LOW";
  }

else  if(req.indexOf("04") != -1)
  {
    digitalWrite(D3,LOW);
    pin = "D3";
    level = "LOW";
  }
else  if(req.indexOf("05") != -1)
  {
    digitalWrite(D4,LOW);
    pin = "D4";
    level = "LOW";
  }
else  if(req.indexOf("06") != -1)
  {
    digitalWrite(D5,LOW);
    pin = "D5";
    level = "LOW";
  }
else  if(req.indexOf("07") != -1)
  {
    digitalWrite(D6,LOW);
    pin = "D6";
    level = "LOW";
  }
else  if(req.indexOf("08") != -1)
  {
    digitalWrite(D7,LOW);
    pin = "D7";
    level = "LOW";
  }
else  if(req.indexOf("11") != -1)
  {
    digitalWrite(D0,HIGH);
    pin = "D0";
    level = "HIGH";
  }
else  if(req.indexOf("12") != -1)
  {
    digitalWrite(D1,HIGH);
    pin = "D1";
    level = "HIGH";
  }
else  if(req.indexOf("13") != -1)
  {
    digitalWrite(D2,HIGH);
    pin = "D2";
    level = "HIGH";
  }
else  if(req.indexOf("14") != -1)
  {
    digitalWrite(D3,HIGH);
    pin = "D3";
    level = "HIGH";
  }
else  if(req.indexOf("15") != -1)
  {
    digitalWrite(D4,HIGH);
    pin = "D4";
    level = "HIGH";
  }
else  if(req.indexOf("16") != -1)
  {
    digitalWrite(D5,HIGH);
    pin = "D5";
    level = "HIGH";
  }
else  if(req.indexOf("17") != -1)
  {
    digitalWrite(D6,HIGH);
    pin = "D6";
    level = "HIGH";
  }
else  if(req.indexOf("18") != -1)
  {
    digitalWrite(D7,HIGH);
    pin = "D7";
    level = "HIGH";
  }
else  if(req.indexOf("STOP") != -1)
  {
    break;  
  }
else
  {
    Serial.println("Invalid Request");
  }
String s;
s += pin+" is now ";
s += level+ "\n" ;

client.print(s);
delay(100);
  }

}
 





void setup() {
  Serial.begin(115200);
  delay(100);
 
  //prepare GPIO
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);

  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  
  server.begin();
  Serial.println("Server started");
  
  Serial.print("Use this ip to connect");
  Serial.println("http://");
  Serial.print(WiFi.localIP());
  Serial.print("/");
}
 
int value = 0;
 





void loop() {
  delay(1000);
  ++value;
 

  Serial.println("new client check");
  // Use WiFiClient class to create TCP connections
  WiFiClient client = server.available();

  if (!client) {
    return;
  }
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }


doSwitch(client);
  
  client.stop();
  Serial.println("Client disconnected");
  
 
}

