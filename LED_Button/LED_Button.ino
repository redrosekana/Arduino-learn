#define LED_RED 32
#define SW 27

void setup() {
  // put your setup code here, to run once:
  pinMode(SW,INPUT_PULLUP);
  pinMode(LED_RED,OUTPUT);
  digitalWrite(LED_RED,LOW);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // เนื่องจากเป็น input_pullup ปล่อย => 1 , กด => 0
  // ถ้ากดไฟดับ ถ้าปล่อยไปจะติด  
  Serial.println(digitalRead(SW));
  // นำค่าไปกำหนดใน digitalWrite ได้เลย  
  
  digitalWrite(LED_RED,digitalRead(SW));
  delay(200);
}
