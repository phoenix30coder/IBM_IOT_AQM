#include <DHTesp.h>
#include<ThingSpeak.h>
#include <WiFi.h>

const int temp=15;
const int gas = 2;
DHTesp dhtSensor;
TempAndHumidity data;
char sid[] = "Wokwi-GUEST";
char pass[]="";
unsigned long cha = "your chanel id";
const char* key ="your key";

WiFiClient cli;
void setup() {
  
  Serial.begin(115200);
  pinMode(gas, INPUT);
  pinMode(temp,INPUT);

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(cli);
  dhtSensor.setup(temp,DHTesp::DHT22);
}

void loop() {
  getwifi();

  data=dhtSensor.getTempAndHumidity();
  
  Serial.print("Gas Level: ");
  Serial.println(analogRead(2));
  
  Serial.println(("temp"+string(data.temperature)));
  Serial.println("Humi:"+String(data.humidity));


  ThingSpeak.setField(1,data.temperature);
  ThingSpeak.setField(2,data.humidity);
  ThingSpeak.setField(3,distance);
  statuscode = ThingSpeak.writeFields(cha,key);
  if(statuscode == 200){
    Serial.println("updates");
  }
  else{
    Serial.println("error");
  }
  Serial.println("****************");
  delay(15000); // this speeds up the simulation
}


void getwifi(){
    if(WiFi.status()!= WL_CONNECTED){
        Serial.print("attempting");
        while(WiFi.status()!= WL_CONNECTED){
          WiFi.begin(sid,pass);
          Serial.print(".");
          delay(5000);
        }
    }
    Serial.println("connected");

}