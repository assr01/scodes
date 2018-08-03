#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include<Servo.h>
#define FIREBASE_HOST "nodemcu-1523e.firebaseio.com"
#define FIREBASE_AUTH "6e1M83xZsvbJ4nERnmdglNvAKdaoWyhDeFg3dcbh"
#define WIFI_SSID "RUDRA-SRM MARS ROVER"  
#define WIFI_PASSWORD "hackitifucan"
const int pwm = 5 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
void setup() {
const int pwm = 5;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
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
int i = 0;
void loop() {
// get value 
Serial.print("switch1: ");
Serial.println(Firebase.getFloat("switch1"));
{if(Firebase.getFloat("switch1")==1)
{
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ;}
  else if(Firebase.getFloat("switch2")==1)
{
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ; 
  }
}

// set string value
Firebase.setString("message","Sahi khel gaya");

}
