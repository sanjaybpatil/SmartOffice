/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>
#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12
#define D7  13
const char* ssid = "ESP8266-NodeMCU";
const char* password = "Password123";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

//  prepare GPIO2
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);  
//  Connect to WiFi network
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  //Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
 
String pin,level;
      if (req.indexOf("/D0/0") != -1)
    {digitalWrite(D0,LOW);pin = "D0" ;level = "LOW";}
 else if (req.indexOf("/D1/0") != -1) 
    {digitalWrite(D1,LOW);pin = "D1" ;level = "LOW";}
 else if (req.indexOf("/D2/0") != -1) 
    {digitalWrite(D2,LOW);pin = "D2" ;level = "LOW";}
 else if (req.indexOf("/D3/0") != -1) 
    {digitalWrite(D3,LOW);pin = "D3" ;level = "LOW";}
 else if (req.indexOf("/D4/0") != -1) 
    {digitalWrite(D4,LOW);pin = "D4" ;level = "LOW";}
 else if (req.indexOf("/D5/0") != -1) 
    {digitalWrite(D5,LOW);pin = "D5" ;level = "LOW";}
 else if (req.indexOf("/D6/0") != -1) 
    {digitalWrite(D6,LOW);pin = "D6" ;level = "LOW";}
 else if (req.indexOf("/D7/0") != -1) 
    {digitalWrite(D7,LOW);pin = "D7" ;level = "LOW";}
 else if (req.indexOf("/D0/1") != -1)
    {digitalWrite(D0,HIGH);pin = "D0" ;level = "HIGH";}
 else if (req.indexOf("/D1/1") != -1)
    {digitalWrite(D1,HIGH);pin = "D1" ;level = "HIGH";}
 else if (req.indexOf("/D2/1") != -1) 
    {digitalWrite(D2,HIGH);pin = "D2" ;level = "HIGH";}
 else if (req.indexOf("/D3/1") != -1) 
    {digitalWrite(D3,HIGH);pin = "D3" ;level = "HIGH";}
 else if (req.indexOf("/D4/1") != -1) 
    {digitalWrite(D4,HIGH);pin = "D4" ;level = "HIGH";}
 else if (req.indexOf("/D5/1") != -1)
    {digitalWrite(D5,HIGH);pin = "D5" ;level = "HIGH";}
 else if (req.indexOf("/D6/1") != -1)
    {digitalWrite(D6,HIGH);pin = "D6" ;level = "HIGH";}
 else if (req.indexOf("/D7/1") != -1) 
    {digitalWrite(D7,HIGH);pin = "D7" ;level = "HIGH";}
 else
    {Serial.println("Invalid choice");}

 /* 
  // Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1)
    val = 0;
  else if (req.indexOf("/gpio/1") != -1)
    val = 1;
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(2, val);
  
  client.flush();
*/
//   Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
  s += pin+"is now";
  s += level;
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
 // Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}





