#define SW 22

void setup() {
  // put your setup code here, to run once:
  pinMode(SW,INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // เป็นการอ่านค่าปกติยังไม่มีการ debounce  
  Serial.println(digitalRead(SW));
  delay(200);
}
