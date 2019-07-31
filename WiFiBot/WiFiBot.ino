#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "token";
char ssid[] = "your ssid";
char pass[] = "yourpassword";
#define ENB D3 //ENB
#define MB1 D4 //IN3
#define MB2 D5 //IN4 
#define MA1 D7 //IN1
#define MA2 D6 //IN2
#define ENA D8 //ENA
void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V6) {
  HIGH = param.asInt();
  Serial.println(HIGH);
}
BLYNK_WRITE(V1) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  Serial.println("Forward");
}
BLYNK_WRITE(V2) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
  Serial.println("Right");
}
BLYNK_WRITE(V3) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
  Serial.println("Backward");
}
BLYNK_WRITE(V4) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  Serial.println("Left");
}
BLYNK_WRITE(V5) {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  Serial.println("STOP");
}

void loop() {
  Blynk.run();
}
