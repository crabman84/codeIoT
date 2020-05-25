int bluePin = 11;
int redPin = 10;
int greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  //Blue
  GreenRedBlue(LOW, LOW, HIGH, 700);
  //Red
  GreenRedBlue(LOW, HIGH, LOW, 700);
  //Green
  GreenRedBlue(HIGH, LOW, LOW, 300);

  // put your main code here, to run repeatedly:
}

void GreenRedBlue(uint8_t green, uint8_t red, uint8_t blue, int delayVal){
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
  digitalWrite(redPin, red);
  delay(delayVal);
}

void greenLight(){
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, HIGH);
}

void redLight(){
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
}


void blueLight(){
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, LOW);
}

void All(){
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
}
