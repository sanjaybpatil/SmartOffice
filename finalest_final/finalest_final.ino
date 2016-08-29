/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "SQS";
const char* password = "d0n773llN0On3";

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12  
#define D7  13
// Create an instance of the server
// specify the port to listen on as an argument
ESP8266WebServer server(80);

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
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
 
 WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); 
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
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
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
 server.handleClient();
}

