#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

    //define ESP friendly pins
    #define D0 16
    #define D1 5
    #define D2 4
    #define D3 0
    #define D4 2
    #define D5 14
    #define D6 12
    #define D7 13





void setup() {

  //set the GPIO pins D0-D8 of NodeMCU connected to the relay as o/p pins
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
}

void loop() {
int choice=0; //variable to contain choice id of selected device 





 
              
  

  

}

void check_pinStat(int choice)
{
      if(digitalRead(choice)==HIGH)
      {
          switch_OFF(choice);  
        
      }
      else
      {
          switch_ON(choice);  
      }
  
}
void switch_ON(int choice)
{
  
  switch(choice)
  {
       case D0:
               digitalWrite(D0,HIGH); //switch ON relay connected to pin D0  
               break;
       case D1:
               digitalWrite(D1,HIGH); //switch ON relay connected to pin D1  
               break;
       case D2:
               digitalWrite(D2,HIGH); //switch ON relay connected to pin D2  
               break;        
       case D3:
               digitalWrite(D3,HIGH); //switch ON relay connected to pin D3  
               break;

       case D4:
               digitalWrite(D4,HIGH); //switch ON relay connected to pin D4  
               break;
       case D5:
               digitalWrite(D5,HIGH); //switch ON relay connected to pin D5  
               break;
       case D6:
               digitalWrite(D6,HIGH); //switch ON relay connected to pin D6  
               break;
       case D7:
               digitalWrite(D7,HIGH); //switch ON relay connected to pin D7  
               break;
  }
  
  
}

void switch_OFF(int choice)
{
  
  switch(choice)
  {
       case D0:
               digitalWrite(D0,LOW); //switch OFF relay connected to pin D0  
               break;
       case D1:
               digitalWrite(D1,LOW); //switch OFF relay connected to pin D1  
               break;
       case D2:
               digitalWrite(D2,LOW); //switch OFF relay connected to pin D2  
               break;        
       case D3:
               digitalWrite(D3,LOW); //switch OFF relay connected to pin D3  
               break;

       case D4:
               digitalWrite(D4,LOW); //switch OFF relay connected to pin D4  
               break;
       case D5:
               digitalWrite(D5,LOW); //switch OFF relay connected to pin D5  
               break;
       case D6:
               digitalWrite(D6,LOW); //switch OFF relay connected to pin D6  
               break;
       case D7:
               digitalWrite(D7,LOW); //switch OFF relay connected to pin D7  
               break;
  }
  
  
}
