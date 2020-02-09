//libraries
#include <Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//variables
const char* ssid     = "piseek";
const char* password = "Solent1234";
static const int RXPin = 4, TXPin = 3;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println(F("Starrting"));
  Serial.println();
  int i = 0;
  //test connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void loop()
{
  if ((gps.location.isValid()) && (WiFi.status() == WL_CONNECTED))
  {
    float latitude = gps.location.lat();
    float longitude = gps.location.lng();

    String cordsString = ("lat:" + String(latitude) + "lon:" + String(longitude) + ":end");

    HTTPClient http;                                         //Declare object of class HTTPClient

    http.begin("http://192.168.1.88:8085/hello");            //Specify request destination
    http.addHeader("Content-Type", "text/plain");            //Specify content-type header

    int httpCode = http.POST(String(cordsString));                   //Send the request
    String payload = http.getString();                       //Get the response payload

    Serial.println(httpCode);                                //Print HTTP return code
    Serial.println(payload);                                 //Print request response payload

    http.end();
  }
  else
  {
    Serial.println("ERROR");
  }
}