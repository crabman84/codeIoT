// Temp light Control: Control the intesity of an LED using a servo motor... 
////    ...whos values are depedant on the temperature input from the DHT sensor

//----------DHT library & Initialisation----------//
#include "DHT.h"
#define DHTPIN 2 // what digital pin we're connected to
  // Uncomment whatever type you're using!
  //#define DHTTYPE DHT11 // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
//----------END: DHT library ----------//

//----------Servor Library and initialsation ----------//
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//----------END: Servor Library and initialsation ----------//

void setup() {
   Serial.begin(9600);

  //-----------DHT setup-----------//
  DHT_setup();
  //-----------Servo setup-----------//
  servo_setup();

  // put your setup code here, to run once:

}

void loop() {
  //-----------run DHT-----------//
    
    // put your main code here, to run repeatedly:
    float* data = DHT_read();
    DHT_write(data);
  //-----------EDN: run DHT-----------//
  float latestPos;
  latestPos = calculatePosFromTemp(data);
  //-----------run Servo-----------//
    //servo_pos_sweep();
    servoSetPosition(latestPos);
  //-----------EDN: run Servo-----------//

  delay(250);
  
}

void DHT_setup(){
   Serial.println("DHTxx test!");
   dht.begin();
}


float* DHT_read(){

    // Reading temperature or humidity takes about 250 milliseconds!
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    static float data[2];

    // Read temperature as Fahrenheit (isFahrenheit = true)
    if (isnan(t)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

     data[0] = t;
     data[1] = hic;
     return data;
    
}

void DHT_write(float * data){
    float temp = data[0];
    float hic = data[1];

    printData(" Temperature: |", temp, " *C| ");
    printData(" Heat Index: |", hic, " *C| ");
    Serial.print(" \n");
    
}

void servo_setup(){
   Serial.println("Servo Sweep Test!");
   myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

float calculatePosFromTemp(float* data){
    const int maxPos = 171; //value is in degrees
    const float maxTemp = 50; // value is in Celcius
    const float conversionVal = maxPos/maxTemp;
    float currentTemp = data[0];

    float nextPos;
    if(currentTemp > 25){
      nextPos = 171;
      Serial.println("It is TOO HOT! Make it COLD again!");
    }
    else if(currentTemp < 19){
      nextPos = 0;
      Serial.println("It is TOO COLD! Make it HOT again!");
    }
    else{
      nextPos = currentTemp * conversionVal;
      Serial.println("This is nice...");
    }
    printData("Next Pos: |", nextPos, "°|");

    return nextPos;
}

void servoSetPosition(float pPos){
    myservo.write(pPos); // tell servo to go to position in variable 'pos'
}

void servo_pos_sweep(){
    float pos = 0;    // variable to store the servo position
    int speedRateLimiter = 6;
    int motorPause = 100;
    for (pos = 0; pos <= 171; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      //printData("Pos: ", pos, "°");
      printf(" \n");
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(speedRateLimiter);                       // waits 15ms for the servo to reach the position
    }
    
    //delay(motorPause);
    for (pos = 172; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      //printData("Pos: ", pos, "°");
      printf(" \n");
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(speedRateLimiter);                       // waits 15ms for the servo to reach the position
    }
}

//-----------Overloaded functions-----------//
void printData(String pName, int pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}

void printData(String pName, float pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}

void printData(String pName, long pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}

void printData(String pName, byte pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}

void printData(String pName, bool pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}

void printData(String pName, char pData, String pScale){
      Serial.print(pName);
      Serial.print(pData);
      Serial.print(pScale);
}
  //-----------EDN: Overloaded functions-----------//
