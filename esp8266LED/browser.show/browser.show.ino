#include <ESP8266WiFi.h>
 
const char* ssid = "ANKIT";
const char* password = "";

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12  
#define D7  13



WiFiServer server(80);

void ShowHTML(WiFiClient client)
{
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); //  do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<body>");
client.println("<FORM>");
client.println("<INPUT TYPE='button' Value='Relay1'onClick='parent.location='/D0'>");
client.println("<INPUT TYPE='button' Value='Relay2'onClick='parent.location='/D1'>");
client.println("<INPUT TYPE='button' Value='Relay3'onClick='parent.location='/D2'>");
client.println("<INPUT TYPE='button' Value='Relay4'onClick='parent.location='/D3'>");
client.println("<INPUT TYPE='button' Value='Relay5'onClick='parent.location='/D4'>");
client.println("<INPUT TYPE='button' Value='Relay6'onClick='parent.location='/D5'>");
client.println("<INPUT TYPE='button' Value='Relay7'onClick='parent.location='/D6'>");
client.println("<INPUT TYPE='button' Value='Relay8'onClick='parent.location='/D7'>");
client.println("</FORM> ");
client.println("</body>");
client.println("</html>");
}


int doSwitch(WiFiClient client)
{

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
        return 0; 
  }
else
  {
    Serial.println("Invalid Request");
  }
  return 1;
}
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
    
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
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
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
  int stop=1;
  while(stop){

  ShowHTML(client);

  stop = doSwitch(client);
 
  }  
 
  client.stop();
  Serial.println("Client disonnected");
  Serial.println("");
 
}



