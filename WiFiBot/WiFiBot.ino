#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "G3Q_u-s0oGy98u-56YQCotxltNSjNZDz";
char ssid[] = "DeadSec_Dev1";
char pass[] = "##5823#36257##";
int high;
int low = 0;
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
  high = param.asInt();
  Serial.println(high);
}
BLYNK_WRITE(V1) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, high);
  digitalWrite(MA2, low);
  digitalWrite(MB1, high);
  digitalWrite(MB2, low);
  Serial.println("Forward");
}
BLYNK_WRITE(V2) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, high);
  digitalWrite(MA2, low);
  digitalWrite(MB1, low);
  digitalWrite(MB2, high);
  Serial.println("Right");
}
BLYNK_WRITE(V3) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, low);
  digitalWrite(MA2, high);
  digitalWrite(MB1, low);
  digitalWrite(MB2, high);
  Serial.println("Backward");
}
BLYNK_WRITE(V4) {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(MA1, low);
  digitalWrite(MA2, high);
  digitalWrite(MB1, high);
  digitalWrite(MB2, low);
  Serial.println("Left");
}
BLYNK_WRITE(V5) {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(MA1, low);
  digitalWrite(MA2, low);
  digitalWrite(MB1, low);
  digitalWrite(MB2, low);
  Serial.println("STOP");
}

void loop() {
  Blynk.run();
}
