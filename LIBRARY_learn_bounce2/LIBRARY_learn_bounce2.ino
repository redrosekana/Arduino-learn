#include <Bounce2.h>

#define BUTTON 22
#define LED 32

// สร้าง debouncer ขึ้นมาเป็น instance
Bounce debouncer = Bounce();

// ไว้นับจำนวนครั้งที่กดปุ่ม
int count = 0;
// สถานะของ led
int status = LOW;

void setup() {
   // กำหนดให้ debouncer instance ใช้ BUTTON ในโหมดไหนก็ได้ INPUT,INPUT_PULLUP, OUTPUT
   debouncer.attach(BUTTON, INPUT_PULLUP);
   // กำหนดเวลาการเปลี่ยนสถานะให้กับ debouncer instance ที่ 25 มิลลิวินาที
   debouncer.interval(25); 
  
   pinMode(LED, OUTPUT);
   digitalWrite(LED,status);
   Serial.begin(115200);
}

void loop() {
   debouncer.update(); // อัปเดตสถานะให้กับ debouncer instance
   
   // กำหนดเงื่อนไขให้โค้ดโปรแกรมในวงเล็บปีกกาทำงานเมื่อสถานะปุ่มกดเปลี่ยนจาก HIGH เป็น LOW โดยเช็คจากฟังก์ชั่น fell()
   // หากต้องการเช็คสถานะจาก LOW เป็น HIGH ให้แทนที่ฟังก์ชั่น fell() ด้วยฟังก์ชั่น rose()
   if ( debouncer.fell() ) { 
    Serial.println(count);
    status = !status;
    digitalWrite(LED, status);
    count++;
   }
}
