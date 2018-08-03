#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "nodemcu-1523e.firebaseio.com"
#define FIREBASE_AUTH "6e1M83xZsvbJ4nERnmdglNvAKdaoWyhDeFg3dcbh"
#define WIFI_SSID "RUDRA-SRM MARS ROVER"  
#define WIFI_PASSWORD "hackitifucan"
void setup() {
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
int n = 0;
void loop() {
// get value 
Serial.print("switch1: ");
Serial.println(Firebase.getFloat("switch1"));
{if(Firebase.getFloat("switch1")==1)
{
   digitalWrite(5, HIGH);   
  }
  else
{
   digitalWrite(5, LOW);   
  }
}
  {if(Firebase.getFloat("switch2")==1)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
  }
// set string value
Firebase.setString("message","Sahi khel gaya");

}
