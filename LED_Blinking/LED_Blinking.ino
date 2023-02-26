#define LED_RED 32

void setup() {
  Serial.begin(115200);
  pinMode(LED_RED,OUTPUT);
  digitalWrite(LED_RED, LOW);
}

void loop() {
  Serial.println("loop ...");
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);
  delay(500);
}
