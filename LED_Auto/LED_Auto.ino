#define LED_RED 32
#define LDR 34

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR,INPUT);
  pinMode(LED_RED,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(LDR));
  if (analogRead(LDR) > 3500) {
    digitalWrite(LED_RED,HIGH);
  }else {
    digitalWrite(LED_RED,LOW);
  }
  delay(100);
}
