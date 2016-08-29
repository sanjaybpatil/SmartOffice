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
const char *pass = "ankitshinde";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
}


 String webPage = "";


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
 
  webPage += "<h1>ESP8266 Web Server</h1>";
  webPage += "<p>Relay1<a href = \'d01\'><button>ON</button></a>&nbsp<a href=\'d00\'><button>OFF</button></a></p>";
  webPage += "<p>Relay2<a href = \'d11\'><button>ON</button></a>&nbsp<a href=\'d10\'><button>OFF</button></a></p>";
  webPage += "<p>Relay3<a href = \'d21\'><button>ON</button></a>&nbsp<a href=\'d20\'><button>OFF</button></a></p>";
  webPage += "<p>Relay4<a href = \'d31\'><button>ON</button></a>&nbsp<a href=\'d30\'><button>OFF</button></a></p>";
  webPage += "<p>Relay5<a href = \'d41\'><button>ON</button></a>&nbsp<a href=\'d40\'><button>OFF</button></a></p>";
  webPage += "<p>Relay6<a href = \'d51\'><button>ON</button></a>&nbsp<a href=\'d50\'><button>OFF</button></a></p>";
  webPage += "<p>Relay7<a href = \'d61\'><button>ON</button></a>&nbsp<a href=\'d60\'><button>OFF</button></a></p>";
  webPage += "<p>Relay8<a href = \'d71\'><button>ON</button></a>&nbsp<a href=\'d70\'><button>OFF</button></a></p>";
    
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println("HTTP server started");
  server.on("/",[](){
    server.send(200,"text/html",webPage);
    });
  
  
  server.on("/d00",[](){
    Serial.print("D00");
  server.send(200,"text/html",webPage);
  digitalWrite(D0,LOW);
  delay(100);
  });

  server.on("/d10",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D1,LOW);
  delay(100);
  });

  server.on("/d20",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D2,LOW);
  delay(100);
  });

  server.on("/d30",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D3,LOW);
  delay(100);
  });

  server.on("/d40",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D4,LOW);
  delay(100);
  });
  
  server.on("/d50",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D5,LOW);
  delay(100);
  });
  
  server.on("/d60",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D6,LOW);
  delay(100);
  });
  
  server.on("/d70",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D7,LOW);
  delay(100);
  });

  server.on("/d01",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D0,HIGH);
  delay(100);
  });

    server.on("/d11",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D1,HIGH);
  delay(100);
  });

    server.on("/d21",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D2,HIGH);
  delay(100);
  });

    server.on("/d31",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D3,HIGH);
  delay(100);
  });

    server.on("/d41",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D4,HIGH);
  delay(100);
  });

    server.on("/d51",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D5,HIGH);
  delay(100);
  });

    server.on("/d61",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D6,HIGH);
  delay(100);
  });

    server.on("/d71",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D7,HIGH);
  delay(100);
  });

  
}

void loop() {
  server.handleClient();
}
