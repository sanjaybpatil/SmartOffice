
#include<ESP8266WiFi.h>

WiFiServer server(80);
char ssid[]="ANKIT";
char password[]="ankitshinde"; 
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
WiFi.disconnect();
WiFi.mode(WIFI_STA );
WiFi.begin(ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Hello World/n");
WiFiClient client = server.available();
delay(500);
String req = client.readStringUntil('\r');
Serial.print(req);
Serial.print("Hello World/n");

}
