#include "Ubidots.h"

const char* UBIDOTS_TOKEN = ""; //Enter your UBIDOTS_TOKEN
const char* SSID = "";         //Enter your SSID
const char* PASSWORD = "";    //Enter your PASSWORD 

const char* DEVICE_LABEL = "energy";   
const char* VARIABLE_LABEL = "toggle";   
const char* VARIABLE_SENDER = "current";
const char* VARIABLE_SENDER_power = "power_W";
const char* VARIABLE_SENDER_accumulatedWh = "power_Wh";

const int sensorIn = A0;
int mVperAmp = 100; 

unsigned long previousMillis = 0;
const long interval = 1000; 
float accumulatedWh = 0.0;

Ubidots ubidots(UBIDOTS_TOKEN, UBI_TCP);

int relayPin = D4; 

void setup()
{
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 

 WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}    
void loop()
{

     unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float voltage = getVPP(); 
    float VRMS = (voltage / 2.0) * 0.707; 
    float current = VRMS * 1000 / mVperAmp; 

    float power = current * 220.0;    
    float energyWh = power / 3600.0;
    accumulatedWh += energyWh;
    
    float accumulatedkWh = accumulatedWh / 1000.0;

ubidots.add(VARIABLE_SENDER, (round(current * 10) / 10.0) );
ubidots.add(VARIABLE_SENDER_power, (round(power * 10) / 10.0) );
ubidots.add(VARIABLE_SENDER_accumulatedWh, (round(accumulatedWh * 10) / 10.0));

 delay(2000);


bool bufferSent = false;
  bufferSent = ubidots.send(DEVICE_LABEL);  
  if (bufferSent) {
    Serial.println("Values sent by the device");
  }

    Serial.print("Current (A): ");
    Serial.print(current);
    Serial.print(", Power (W): ");
    Serial.print(power);
    Serial.print(", Energy (Wh): ");
    Serial.print(accumulatedWh);
    Serial.print(", Energy (kWh): ");
    Serial.println(accumulatedkWh);
  }

 float value = ubidots.get(DEVICE_LABEL, VARIABLE_LABEL);
    Serial.println(value);
  if (value == 0) {
    digitalWrite(relayPin, HIGH); 
    Serial.println("0");

  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("1");
  }
}

float getVPP() {
  float result;
  int readValue; 
  int maxValue = 0; 
  int minValue = 1024;
  
  unsigned long start_time = millis();
  while((millis() - start_time) < 1000) 
  {
    readValue = analogRead(sensorIn);
    if (readValue > maxValue) {
      maxValue = readValue; 
    }
    if (readValue < minValue) {
      minValue = readValue; 
    }
  }
  result = ((maxValue - minValue) * 5.0) / 1024.0;
  return result;
}