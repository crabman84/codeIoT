int ledPin = 8;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (true) {
    val = digitalRead(ledPin);
    Serial.print("\n Val: " + digitalRead(ledPin) );
    Serial.print("\n BLINK ON");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("\n BLINK OFF \n");
    delay(300);
  }
}
