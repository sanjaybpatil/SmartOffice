
//////////////////////////////////////////////
// Get XML formatted data from the web.
// 1/6/08 Bob S. - Created
//
//  Assumptions: single XML line looks like: 
//    <tag>data</tag> or <tag>data 
//
// Get current weather observation for Raleigh from weather.gov in XML format
//
//////////////////////////////////////////////

// Include description files for other libraries used (if any)
#include <string.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

//Set SSID Password for Wifi Access Network to connect to
const char* ssid = "SQS";
const char* password = "d0n773llN0On3";
String webPage = "";
//Define ESP Friendly Pin Mappings
#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12  
#define D7  13

// Define Constants
// Max string length may have to be adjusted depending on data to be extracted
#define MAX_STRING_LEN  20

// Setup vars
char tagStr[MAX_STRING_LEN] = "";
char dataStr[MAX_STRING_LEN] = "";
char tmpStr[MAX_STRING_LEN] = "";
char endTag[3] = {'<', '/', '\0'};
int len;

// Flags to differentiate XML tags from document elements (ie. data)
boolean tagFlag = false;
boolean dataFlag = false;

// Ethernet vars
/*byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 0, 41 };
byte server[] = { 140, 90, 113, 200 }; // www.weather.gov */

// Start ethernet client

/*Client client(server, 80); */
WiFiServer server(80);

void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
// Ethernet.begin(mac, ip);
// delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   webPage += "<h1>ESP8266 Web Server</h1>";
  webPage += "<p>Relay 1  <a href = \'dev11\'><button>ON</button></a>&nbsp<a href=\'dev10\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 2  <a href = \'dev21\'><button>ON</button></a>&nbsp<a href=\'dev20\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 3  <a href = \'dev31\'><button>ON</button></a>&nbsp<a href=\'dev30\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 4  <a href = \'dev41\'><button>ON</button></a>&nbsp<a href=\'dev40\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 5  <a href = \'dev51\'><button>ON</button></a>&nbsp<a href=\'dev50\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 6  <a href = \'dev61\'><button>ON</button></a>&nbsp<a href=\'dev60\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 7  <a href = \'dev71\'><button>ON</button></a>&nbsp<a href=\'dev70\'><button>OFF</button></a></p>";
  webPage += "<p>Relay 8  <a href = \'dev81\'><button>ON</button></a>&nbsp<a href=\'dev80\'><button>OFF</button></a></p>";
  
 while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); 
    WiFi.begin(ssid, password); 
    delay(15000);
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
 
 
  // Start the server
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 // Read serial data in from web:
  while (client.available()) 
  {
     serialEvent(client); 
  } 

 if (!client.connected()) 
 {
   //Serial.println();
   //Serial.println("Disconnected");
   client.stop();

   // Time until next update
   //Serial.println("Waiting");
   for (int t = 1; t <= 15; t++)
   {
     delay(400); // 1 minute
   }

   /*if (client.connect()) 
   {
     //Serial.println("Reconnected");
     client.println("GET /xml/current_obs/KRDU.xml HTTP/1.0");    
     client.println();
     delay(2000);
   } 
   else 
   {
     Serial.println("Reconnect failed");
   }*/       
 }
}

// Process each char from web
void serialEvent(WiFiClient client) 
{

  // Read a char
  char inChar = client.read();
  //Serial.print(".");
 
  if (inChar == '<') 
  {
     addChar(inChar, tmpStr);
     tagFlag = true;
     dataFlag = false;
  } 
  else if (inChar == '>') 
  {
     addChar(inChar, tmpStr);
     if (tagFlag) 
     {      
        strncpy(tagStr, tmpStr, strlen(tmpStr)+1);
     }

     // Clear tmp
     clearStr(tmpStr);

     tagFlag = false;
     dataFlag = true;      
     
  } 
  else if (inChar != 10) 
  {
     if (tagFlag) 
     {
        // Add tag char to string
        addChar(inChar, tmpStr);

        // Check for </XML> end tag, ignore it
        if ( tagFlag && strcmp(tmpStr, endTag) == 0 ) 
        {
           clearStr(tmpStr);
           tagFlag = false;
           dataFlag = false;
        }
     }
     
     if (dataFlag) 
     {
        // Add data char to string
        addChar(inChar, dataStr);
     }
  }  
 
  // If a LF, process the line
  if (inChar == 10 ) 
  {

/*
     Serial.print("tagStr: ");
     Serial.println(tagStr);
     Serial.print("dataStr: ");
     Serial.println(dataStr);
*/

     // Find specific tags and print data
     if (matchTag("<temp_f>")) 
     {
        Serial.print("Temp: ");
        Serial.print(dataStr);
     }
     if (matchTag("<relative_humidity>")) 
     {
        Serial.print(", Humidity: ");
        Serial.print(dataStr);
     }
     if (matchTag("<pressure_in>")) 
     {
        Serial.print(", Pressure: ");
        Serial.print(dataStr);
        Serial.println("");
     }

     // Clear all strings
     clearStr(tmpStr);
     clearStr(tagStr);
     clearStr(dataStr);

     // Clear Flags
     tagFlag = false;
     dataFlag = false;
  }
}

/////////////////////
// Other Functions //
/////////////////////

// Function to clear a string
void clearStr (char* str) 
{
  int len = strlen(str);
  for (int c = 0; c < len; c++) 
  {
     str[c] = 0;
  }
}

//Function to add a char to a string and check its length
void addChar (char ch, char* str) 
{
  char *tagMsg  = "<TRUNCATED_TAG>";
  char *dataMsg = "-TRUNCATED_DATA-";

  // Check the max size of the string to make sure it doesn't grow too
  // big.  If string is beyond MAX_STRING_LEN assume it is unimportant
  // and replace it with a warning message.
  if (strlen(str) > MAX_STRING_LEN - 2) 
  {
     if (tagFlag) 
     {
        clearStr(tagStr);
        strcpy(tagStr,tagMsg);
     }
     if (dataFlag) 
     {
        clearStr(dataStr);
        strcpy(dataStr,dataMsg);
     }

     // Clear the temp buffer and flags to stop current processing 
     clearStr(tmpStr);
     tagFlag = false;
     dataFlag = false;

  } 
  else 
  {
     // Add char to string
     str[strlen(str)] = ch;
  }
}

// Function to check the current tag for a specific string
boolean matchTag (char* searchTag) 
{
  if ( strcmp(tagStr, searchTag) == 0 ) 
  {
     return true;
  }
  else 
  {
     return false;
  }
}


