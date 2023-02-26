#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>

// ชื่อ wifi / รหัส wifi 
#define WIFI_NAME "XXX"
#define WIFI_PASS "XXX"
const String URL = "https://jsonplaceholder.typicode.com/posts/1";

HTTPClient http;
const int _size = 2*JSON_OBJECT_SIZE(5);
StaticJsonDocument<_size> JSONGet;

void connectWifi(){
  //  คำสั่งในการเชื่อมต่อ wifi
  WiFi.begin(WIFI_NAME,WIFI_PASS);

  //  วนไปเรื่อยๆถ้ายังเชื่อมต่อ wifi ไม่ได้
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  //  เมื่อเชื่อมต่อสำเร็จให้แสดง ip address
  Serial.println("Connecting to WiFi network");
  Serial.print("Ip Address = ");
  Serial.println(WiFi.localIP());
}

void _get(){
  if (WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    http.begin(URL);
    
    int httpResponseCode = http.GET();
    
    if (httpResponseCode < 400){
      String payload = http.getString();
      deserializeJson(JSONGet,payload);
      Serial.println(httpResponseCode);
      Serial.println((const int)JSONGet["userId"]);
    }
    else{
      Serial.println("ERROR on HTTP Request");
    }
  }
}

void setup() {
  Serial.begin(115200);
  connectWifi();
}

void loop() {
  _get();
  delay(3000);
}
