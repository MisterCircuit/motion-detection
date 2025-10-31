int relay = 7;
int pir = 4;


void setup() {
  pinMode (pir, INPUT);
  pinMode (relay, OUTPUT);
  Serial.begin(9600);
  delay (5000);

}

void loop() {

  if (digitalRead(pir) == HIGH) {
    digitalWrite(relay, HIGH);
    Serial.println("PIR Active");

  }
  else {
    digitalWrite(relay, LOW);
  }

}
