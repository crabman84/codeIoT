//Initialise traffic Light vars
int carGreenPin = 12;
int carBluePin = 11;
int carRedPin = 10;

//Initialise Pedestrian Movement vars
int pedGo = 7;
int pedStop = 6;

//Initialise Pedestrian Traffic Light vars
int pedGreenPin = 12;
int pedBluePin = 11;
int pedRedPin = 10;


void setup() {
  Serial.begin(9600);

  pinMode(carRedPin, OUTPUT);
  pinMode(carBluePin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);

  pinMode(pedGo, OUTPUT);
  pinMode(pedStop, OUTPUT);

  pinMode(pedRedPin, OUTPUT);
  pinMode(pedBluePin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  //Red
  TrafficLights(LOW, HIGH, LOW, 600);
  //Green
  TrafficLights(HIGH, LOW, LOW, 600);
  //Blue
  TrafficLights(LOW, LOW, HIGH, 400);

  // put your main code here, to run repeatedly:
}

//void TrafficLights(uint8_t pGreen, uint8_t pRed, uint8_t pBlue, int pDelayVal){
//  GreenRedBlue(pGreen, pRed, pBlue, pDelayVal);
//  PedestrianGo(pGreen, pRed);
//}

void TrafficLights(uint8_t green, uint8_t red, uint8_t blue, int delayVal) {
  //Serial.println(green);
  digitalWrite(carGreenPin, green);
  digitalWrite(carBluePin, blue);
  digitalWrite(carRedPin, red);
  PedestrianGo(green, red);
  delay(delayVal);
}

void CarLights(uint8_t isGreen, uint8_t isRed, uint8_t isBlue) {
  digitalWrite(carGreenPin, isGreen);
  digitalWrite(carBluePin, isBlue);
  digitalWrite(carRedPin, isRed);
}

void PedestrianLights(uint8_t isGreen, uint8_t isRed, uint8_t isBlue) {
  digitalWrite(pedGreenPin, isGreen);
  digitalWrite(pedBluePin, isBlue);
  digitalWrite(pedRedPin, isRed);
}

void PedestrianGo(uint8_t isGreen, uint8_t isRed) {
  digitalWrite(pedGo, HIGH);
  digitalWrite(pedStop, HIGH);

  if (isGreen && !isRed) {
    Serial.println("Ped Go");
    digitalWrite(pedGo, LOW);
    digitalWrite(pedStop, HIGH);
  }
  else if (!isGreen && isRed) {
    Serial.println("STOP");
    digitalWrite(pedGo, HIGH);
    digitalWrite(pedStop, LOW);
  }
  else {
    digitalWrite(pedGo, LOW);
    digitalWrite(pedStop, HIGH);
  }
}

/*
void greenLight() {
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, HIGH);
}

void redLight() {
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
}

void blueLight() {
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, LOW);
}

void All() {
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
}

*/
