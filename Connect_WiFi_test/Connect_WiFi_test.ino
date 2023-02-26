#include<WiFi.h>

// ชื่อ wifi / รหัส wifi 
#define WIFI_NAME "XXX"
#define WIFI_PASS "XXX"

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

void setup() {
  Serial.begin(115200);
  connectWifi();
}

void loop() {
  Serial.println("Hello World");
  delay(1000);
}
