int button = 26;
int led = 20;
bool ledIsOn; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  ledIsOn = false;

  
}

void loop() {
  digitalWrite(led, LOW);
  if(digitalRead(button) == HIGH){
    Serial.println("button is HIGH -_-");
  }
  if(digitalRead(button) == HIGH && ledIsOn){
      digitalWrite(led, LOW);
      ledIsOn = false;
      Serial.println("led is ON");
      delay(20);
  }
  else if(digitalRead(button) == HIGH && !ledIsOn){
      digitalWrite(led, HIGH);
      ledIsOn = true;
      Serial.println("led is OFF");
      delay(20);
  }
  else{
        digitalWrite(led, LOW);
      ledIsOn = false;
  }
  // put your main code here, to run repeatedly:

}
