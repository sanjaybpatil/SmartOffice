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

IPAddress ip(192,168,0,100);
IPAddress dns1(192,168,192,4);
IPAddress dns2(192,168,70,58);
IPAddress gateway(192,168,160,1);
IPAddress subnet(255,255,224,0);

/* Set these to your desired credentials. */
const char* ssid = "IoT";
const char* password = "Discover&Share";

//WiFiServer server(80);
ESP8266WebServer server(80);

int status = WL_IDLE_STATUS;
/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */



 String webPage = "";


void setup() {
  delay(100);
  Serial.begin(115200);
  Serial.print("");
 // Serial.print("Configuring access point...");
  
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
  
  
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  
  //Check for the present of shield:
  if(WiFi.status() == WL_NO_SHIELD){
  Serial.print("WiFi shield not present");
  while(true); 
  }
  
  int i;
  String check;
  Serial.println("scan start");
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      check = WiFi.SSID(i);      
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
      if(check  == ssid){
        WiFi.begin(ssid,password);
        break;
      }
    }
  }
 
 

 //stat = WiFi.begin(ssid,password);
  //WiFi.config(ip,gateway,subnet,dns1,dns2);
  while(status != WL_CONNECTED){
    Serial.println(status);
    Serial.println("Attempting to connect to SSID ");
    Serial.println(check);
    /*Connect to WPA?WPA@ network Change this line if using open or WEP network*/
   
    
    delay(5000);
  }

 
  

  Serial.print("IP Address :");
  Serial.print(WiFi.localIP());

  
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
  /*//WiFi.softAP(ssid);
  //Wifi.begin(ssid,password);
  //IPAddress myIP = WiFi.softAPIP();
  //Serial.print("AP IP address: ");
  //Serial.println(myIP);*/
  server.begin();
  Serial.print("HTTP server started");
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
