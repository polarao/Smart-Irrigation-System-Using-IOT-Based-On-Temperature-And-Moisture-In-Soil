/*
 * --polarao-----
 * ---smart irrigation system using IOT based temperature and moisture in soil----
 * static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
 */
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "HTTPSRedirect.h"
#define dht_dpin 0//D3
const char* ssid     = "Pola";
const char* password = "Pola@1234";
const char* host = "iotpolarao.000webhostapp.com";
DHT dht(dht_dpin, DHTTYPE); 
uint8_t M_Pin = D1;//5

String url2;

int sense_Pin = 16;//D0
int mois = 1;


const char* host1 = "script.google.com";
const char *GScriptId = "AKfycbxOLElujQcy1-ZUer1KgEvK16gkTLUqYftApjNCM_IRTL3HSuDk"; // Replace with your own google script id
const int httpsPort1 = 443; 
String url1 = String("/macros/s/") + GScriptId + "/exec?id=1mSLXJU3VXEpzZzK4yw7rF53McjE2vFZ2cY-OPQ-NV3A&sheet=Sheet1";
HTTPSRedirect* client1 = nullptr;
void setup() {
   pinMode(M_Pin, OUTPUT);
   dht.begin();
  Serial.begin(115200);
  Serial.println("Humidity and temperature\n\n");
  delay(100);
  //motor
 

  
  // We start by connecting to a WiFi network

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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

  //motor
digitalWrite(M_Pin, 0);

 client1 = new HTTPSRedirect(httpsPort1);
client1->setInsecure();
client1->setPrintResponseBody(true);
client1->setContentTypeHeader("application/json");
Serial.print("Connecting to ");
Serial.println(host1); 
}

int value = 0;

void loop() {
  
  delay(500);
  ++value;

   Serial.print("MOISTURE LEVEL : ");
   mois= analogRead(sense_Pin);
   mois= mois;
   Serial.println(mois);

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  float h=1;
  float t=1;
   h = dht.readHumidity();
    t = dht.readTemperature();
    
   //posting data to server start
  // We now create a URI for the request
  String url = "/weather/insert.php";
 
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url +"?temp="+t+"&hum="+h+"&mois="+mois+" HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");

  //post data to server end
  //start get motor data
 

  bool flag = false;
for (int i = 0; i < 5; i++) {
  int retval = client1->connect(host1, httpsPort1);
  if (retval == 1) {
    flag = true;
    break;
  }
  else
    Serial.println("Connection failed. Retrying...");
}
if (!flag) {
  Serial.print("Could not connect to server: ");
  
  Serial.println(host1);
  Serial.println("Exiting...");
  return;
}
Serial.println("pola");
client1->GET(url1, host1);
String str=client1->getResponseBody();
String str2=str.substring(45,47);

if(str2=="on")
{
          digitalWrite(M_Pin, 1);
          delay(100);
          Serial.println("D1 is On..!");
  }else if(str2=="of"){
          digitalWrite(M_Pin, 0);
          delay(100);
          Serial.println("D1 is Off..!");
    }
Serial.println(str2);

 delay(2000); 
 
  //end get motor data
  
}
