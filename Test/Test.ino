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


 
 
 
 
 
 
 
 String WEB = "";
 int id,hw,logs;
 int i=2,j=3;
 int list[3][4] = {
    {52378,52379,52380,52381},
    {84,84,84,84},
    {0,0,0,0}
    };

void putList(int fid,int fhw,int flogs)
{ int x;
  for(x=0;x<=i;x++)
  {
    if(list[0][x] == fid){
      list[2][x] = flogs;
    }
  }
}

void ListEmpty()
{ int x;
  int check=0;
  for(x=0;x<=i;x++)
  {
    if(list[2][x] == 1)
    {
      check=1;
    }
  }
  if(check==0)
  {
    digitalWrite(D4,LOW);
  }
  else
  {
    digitalWrite(D4,HIGH);
  }
}







void setup() {

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
 
  WEB += "<h1>ESP8266 WEB</h1>";
  WEB += "<h2>JUST TEST 1</h2>";
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
    server.send(200,"text/html",WEB);
    delay(100);
  });

  server.on("/05237884login",[](){
    server.send(200,"text/html",WEB);
    Serial.print("/05237884login");
    id=52378;hw=84;logs=1;
    putList(id,hw,logs);
    ListEmpty();
  });

  server.on("/05237884logout",[](){
    server.send(200,"text/html",WEB);
      Serial.print("/05237884logout");
    id=52378;hw=84;logs=0;
    putList(id,hw,logs);
    ListEmpty();
  });

    server.on("/05237984login",[](){
    server.send(200,"text/html",WEB);
    id=52379;hw=84;logs=1;
    putList(id,hw,logs);
    ListEmpty();
  });

  server.on("/05237984logout",[](){
    server.send(200,"text/html",WEB);
    id=52379;hw=84;logs=0;
    putList(id,hw,logs);
    ListEmpty();
  });
  
  server.on("/05238084login",[](){
    server.send(200,"text/html",WEB);
    id=52380;hw=84;logs=1;
    putList(id,hw,logs);
    ListEmpty();
  });

  server.on("/05238084logout",[](){
    server.send(200,"text/html",WEB);
    id=52380;hw=84;logs=0;
    putList(id,hw,logs);
    ListEmpty();
  });
   
  server.on("/05238184login",[](){
    server.send(200,"text/html",WEB);
    id=52381;hw=84;logs=1;
    putList(id,hw,logs);
  ListEmpty();
  });

  server.on("/05238184logout",[](){
    server.send(200,"text/html",WEB);
    id=52381;hw=84;logs=0;
    putList(id,hw,logs);
   ListEmpty();
  });
 
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
 server.handleClient();
}

