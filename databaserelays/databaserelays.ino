

#include <ESP8266WiFi.h>


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
#define INPSIZE 37
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);



String WEB = "";
int id, hw, logs;
int i = 3, j = 3;
int list[4][4] = {
  {52378, 52379, 51506, 52381},
  {84,    84,    84,    84},
  {0,     0,     0,     0},
  {D2,    D2,    D1,    D3},
};

void putList(int fid, int fhw, int flogs)
{ int x;
  for (x = 0; x <= i; x++)
  {
    if (list[0][x] == fid) 
    {
        list[2][x] = flogs;
    }
    
  }
}

void ListEmpty()
{ int x, y, relayex, check;


  for (x = 0; x <= j; x++)
  {


    relayex = list[3][x];
    check = 0;
    for (y = 0; y <= j; y++)
    {


      
      if (relayex == list[3][y])
      {
        if (list[2][y])
        {
          check = 1;
        }
      }


    }
    if (check == 1)
    {
      digitalWrite(relayex, HIGH);
    }
    else
    {
      digitalWrite(relayex, LOW);
    }






  }

}



void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  delay(10);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);


  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D8, LOW);

  WEB += "<h1>ESP8266 WEB</h1>";
  WEB += "<h2>JUST TEST 1</h2>";


  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    WiFi.begin(ssid, password);
    delay(15000);
  }
  Serial.println("");
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
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();


  int index = req.indexOf('/');
  String UEmpIDS = req.substring(index + 1, index + 7);
  String HDWRS   = req.substring(index + 7, index + 9);


  Serial.println(UEmpIDS);
  Serial.println(HDWRS);

  id = UEmpIDS.toInt();
  hw = HDWRS.toInt();

  if (req.indexOf("login") != -1)
  {
    logs = 1;
    Serial.println("Login");
  }
  else if (req.indexOf("logout") != -1)
  {
    Serial.println("Logout");
    logs = 0;
  }
  else
  {
    logs = 0;
    Serial.println("Login");
  }

  putList(id, hw, logs);
  ListEmpty();


  // Send the response to the client
  client.print(WEB);
  delay(1);

  // The client will actually be disconnected
  // when the function returns and 'client' object is detroyed
}


