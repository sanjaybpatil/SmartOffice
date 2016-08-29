#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "SQS";
const char* password = "d0n773llN0On3";

#define D1  16
#define D2  5
#define D3  4
#define D4  0
#define D5  2
#define D6  14
#define D7  12  
#define D8  13
// Create an instance of the server
// specify the port to listen on as an argument
ESP8266WebServer server(80);

 String webPage = "";

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  
  
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  
  
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  digitalWrite(D8,LOW);


  webPage += "<h1>ESP8266 Web Server</h1>";
  webPage += "<p>Relay 1  <a href = \'dev11\'><button>ON</button></a>&nbsp<a href=\'dev10\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 2  <a href = \'dev21\'><button>ON</button></a>&nbsp<a href=\'dev20\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 3  <a href = \'dev31\'><button>ON</button></a>&nbsp<a href=\'dev30\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 4  <a href = \'dev41\'><button>ON</button></a>&nbsp<a href=\'dev40\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 5  <a href = \'dev51\'><button>ON</button></a>&nbsp<a href=\'dev50\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 6  <a href = \'dev61\'><button>ON</button></a>&nbsp<a href=\'dev60\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 7  <a href = \'dev71\'><button>ON</button></a>&nbsp<a href=\'dev70\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 8  <a href = \'dev81\'><button>ON</button></a>&nbsp<a href=\'dev80\'><button>OFF</button></a></p>";
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
 
 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); 
    WiFi.begin(ssid, password); 
    delay(15000);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("server started");
  server.on("/",[](){
  server.send(200,"text/html",webPage);
  delay(100);
  });

  server.on("/dev10",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D1,LOW);
  delay(100);
  });

  server.on("/dev20",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D2,LOW);
  delay(100);
  });

  server.on("/dev30",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D3,LOW);
  delay(100);
  });

  server.on("/dev40",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D4,LOW);
  delay(100);
  });

  server.on("/dev50",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D5,LOW);
  delay(100);
  });
  
  server.on("/dev60",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D6,LOW);
  delay(100);
  });
  
  server.on("/dev70",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D7,LOW);
  delay(100);
  });
  
  server.on("/dev80",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D8,LOW);
  delay(100);
  });

  server.on("/dev11",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D1,HIGH);
  delay(100);
  });

  server.on("/dev21",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D2,HIGH);
  delay(100);
  });

  server.on("/dev31",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D3,HIGH);
  delay(100);
  });

  server.on("/dev41",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D4,HIGH);
  delay(100);
  });

  server.on("/dev51",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D5,HIGH);
  delay(100);
  });

  server.on("/dev61",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D6,HIGH);
  delay(100);
  });

  server.on("/dev71",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D7,HIGH);
  delay(100);
  });

  server.on("/dev81",[](){
  server.send(200,"text/html",webPage);
  digitalWrite(D8,HIGH);
  delay(100);
  });
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
 server.handleClient();
}

