
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
float suhu;

//PH SENSOR VARIABLE
float PH_step;
float Po = 0;
float PH4 = 3.25;
float PH7 = 2.73;
int ph_pin = A0;
float avg_ph;
float ph_array[3];

//WIFI VARIABLE
const char *ssid = "--"; // nama wifi
const char *pass = "--";// password wifi
WiFiClient client;

//HTTP
String token = "--"; //Token device
String serverName = "--"; //URL API

//TIME CONTROL
unsigned int lastRunTime = millis();
unsigned int delayBetweenRun = 60000;

void setup() { 
  // initialize serial communication at 9600 bits per second: 
  Serial.begin(9600); 
  pinMode (ph_pin, INPUT);
  sensors.begin();

  //Try to connect wifi
  tryConnectWifi();
}

void loop(){
  if(WiFi.status() != WL_CONNECTED){
    tryConnectWifi();
  }
  unsigned int timeNow = millis();
  if (timeNow - lastRunTime > delayBetweenRun)
  {
    getSensor();
    sendAPI();
    lastRunTime = timeNow;
  }
}

void getSensor(){
  avg_ph = 0;
  PH_step = (PH4 - PH7) / 3;
    
  for(int i = 0;i<3;i++){
   int sensorValue = analogRead(ph_pin); 
   float voltage = sensorValue * (3.339 / 1023.0);
   Serial.print("Voltage : "); 
   Serial.println(voltage);
   Po = 7.00 + ((PH7 - voltage) / PH_step);
   ph_array[i] = Po;
   delay(1000);
  };
  
  for(int i = 0;i<3;i++){
   avg_ph += ph_array[i];
  };
    
  avg_ph = avg_ph / 3;
  Serial.print("Nilai ph : ");
  Serial.println(avg_ph,2);
  sensors.requestTemperatures();
  suhu = sensors.getTempCByIndex(0);
  Serial.print("Temperature is: "); 
  Serial.print(suhu);
  return;
}

void tryConnectWifi() {
  Serial.print("Connecting to : ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("….");
  }
  Serial.print("\n");
  Serial.print("IP address : ");
  Serial.print(WiFi.localIP());
  Serial.print("\n");
  Serial.print("Terhubung dengan : ");
  Serial.println(ssid);
  return;
}

void sendAPI(){
    Serial.println("");
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(client,serverName);      
      
      // Specify content-type header
      http.addHeader("Content-Type", "application/json");
      // Data to send with HTTP POST
      String httpRequestData = (String)"{\"water_temp\":";
      httpRequestData += suhu;
      httpRequestData += (String)",\"ph_meter\":";
      httpRequestData += avg_ph;
      httpRequestData += (String)",\"token\":\"";
      httpRequestData += token;
      httpRequestData += (String)"\"}";
      Serial.println(httpRequestData);
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData); 
      
      for(int i = 0; i < 3; i++){
        if(httpResponseCode != 200){
          httpResponseCode = http.POST(httpRequestData);
        }else if(httpResponseCode == 200){
          break;
        }
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        delay(1000);
      }
        
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  return;
}
