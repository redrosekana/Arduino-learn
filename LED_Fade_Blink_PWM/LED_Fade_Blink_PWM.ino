#define LED_RED 32
#define LED_YELLOW 33
#define CHANNEL_0 0
#define FREQ 1000
#define RESOLUTION 8

void setup()
{
    ledcSetup(CHANNEL_0, FREQ, RESOLUTION);
    ledcAttachPin(LED_RED, CHANNEL_0);
    ledcAttachPin(LED_YELLOW, CHANNEL_0);
    ledcWrite(CHANNEL_0,0);
}
void loop(){
  for (int i = 0; i < 256; i++) {
    ledcWrite(CHANNEL_0, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(CHANNEL_0, i);
    delay(10);
  }
  delay(10);
}
