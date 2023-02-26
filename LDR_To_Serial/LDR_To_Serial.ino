#define LDR 34

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR,INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(LDR));
  delay(200);
}
