#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

const char* ssid     = "SSID";
const char* password = "Pass WIFI";
const int ldrPin = A0; // Defining LDR PIN 
int input_val = 0;  // Varible to store Input values
const int ledPin = 5; :// pin D1


WiFiClient  client;
long myChannelNumber = xxxxxxx;
const char myWriteAPIKey[] = "xxxxxxxxxx";

void setup() {
   Serial.begin(115200); 
   delay(100);
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, 0);
   pinMode(ldrPin, INPUT);
   
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);
  
   WiFi.begin(ssid, password);
  
   while (WiFi.status() != WL_CONNECTED) {
   delay(200);
   Serial.print("...");
   }
  
   Serial.println("");
   Serial.println("WiFi connected");  
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
   ThingSpeak.begin(client);
  }


void loop() {  
   input_val = analogRead(ldrPin);      // Reading Input
   Serial.print(input_val);
   if (input_val<=500){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is ON");

  }
  else {
  digitalWrite(ledPin, LOW);
  Serial.println("LED is OFF");
  }
  ThingSpeak.writeField(myChannelNumber, 1,input_val, myWriteAPIKey);
}
