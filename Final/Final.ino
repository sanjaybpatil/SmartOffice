/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12  
#define D7  13


/* Set these to your desired credentials. */
const char *ssid = "ESP";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
server.send(200, "text/html", "<h1>You are connected</h1>");
//server.send("HTTP/1.1 200 OK");
//server.send("Content-Type: text/html");
//server.send(""); //  do not forget this one
server.send(200, "text/html", "<!DOCTYPE HTML>");
server.send(200, "text/html", "<html>");
server.send(200, "text/html", "<body>");
server.send(200, "text/html", "<br><br>");
server.send(200, "text/html", "<a href=\"/D0\"\"><button>Relay1</button></a><br />");
server.send(200, "text/html", "<a href=\"/D1\"\"><button>Relay2</button></a><br />");
server.send(200, "text/html", "<a href=\"/D2\"\"><button>Relay3</button></a><br />");
server.send(200, "text/html", "<a href=\"/D3\"\"><button>Relay4</button></a><br />");
server.send(200, "text/html", "<a href=\"/D4\"\"><button>Relay5</button></a><br />");
server.send(200, "text/html", "<a href=\"/D5\"\"><button>Relay6</button></a><br />");
server.send(200, "text/html", "<a href=\"/D6\"\"><button>Relay7</button></a><br />");
server.send(200, "text/html", "<a href=\"/D7\"\"><button>Relay8</button></a><br />"); 
server.send(200, "text/html", "</body>");
server.send(200, "text/html", "</html>");

String req = client.readStringUntil('\r');
Serial.println(req);
client.flush();
int x;

  if(req.indexOf("D0") != -1)
  {
    if(digitalRead(D0))
      digitalWrite(D0,HIGH);
      else
      digitalWrite(D0,LOW);
  }
else  if(req.indexOf("D1") != -1)
  {
    if(digitalRead(D1))
      digitalWrite(D1,HIGH);
      else
      digitalWrite(D1,LOW);
  }
else  if(req.indexOf("D2") != -1)
  {
    if(digitalRead(D2))
      digitalWrite(D2,HIGH);
      else
      digitalWrite(D2,LOW);
  }

else  if(req.indexOf("D3") != -1)
  {
   if(digitalRead(D3))
      digitalWrite(D3,HIGH);
      else
      digitalWrite(D3,LOW);
  }
else  if(req.indexOf("D4") != -1)
  {
    if(digitalRead(D4))
      digitalWrite(D4,HIGH);
      else
      digitalWrite(D4,LOW);
  }
else  if(req.indexOf("D5") != -1)
  {
    if(digitalRead(D5))
      digitalWrite(D5,HIGH);
      else
      digitalWrite(D5,LOW);
  }
else  if(req.indexOf("D6") != -1)
  {
    if(digitalRead(D6))
      digitalWrite(D6,HIGH);
      else
      digitalWrite(D6,LOW);
  }
else  if(req.indexOf("D7") != -1)
  {
    if(digitalRead(D7))
      digitalWrite(D7,HIGH);
      else
      digitalWrite(D7,LOW);
  }
else  if(req.indexOf("STOP") != -1)
  { 
         
  }
else
  {
    Serial.println("Invalid Request");
  }
 
}

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	
	pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  digitalWrite(D0,HIGH);
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
