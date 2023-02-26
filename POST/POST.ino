#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>

// ชื่อ wifi / รหัส wifi 
#define WIFI_NAME "KANAHOME"
#define WIFI_PASS "mynamekana"
const String URL = "https://jsonplaceholder.typicode.com/posts";

String JSON_String;
HTTPClient http;

const int _size = 2*JSON_OBJECT_SIZE(5);
StaticJsonDocument<_size> JSONPost;

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

void _post(){
  if (WiFi.status() == WL_CONNECTED){
    http.begin(URL);

    JSONPost["userId"] = 1;
    JSONPost["title"] = "Hello World";
    JSONPost["body"] = "My name is kana";
    
    serializeJson(JSONPost,JSON_String);
    http.addHeader("Content-Type","application/json");
    int httpResponseCode = http.POST(JSON_String);
    
    if (httpResponseCode >= 200 && httpResponseCode <= 300 ){
      String payload = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(payload);
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
  _post();
  delay(3000);
}
