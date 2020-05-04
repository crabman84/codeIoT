#include <Adafruit_Sensor.h>

//#include <DHT_U.h>
//#include <DHT.h>

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
// (temp, humidity, Servo Pos)
static float data[3] = {0, 0, 0};


void setup() {
    dht.begin();
    myservo.attach(8);
    Serial.begin(9600);

    //Serial.println("DHTxx test!");
}

void loop() {
    // Serial.println("Hello tello!"); 

    float* data = DHT_read();
    //  float data2 = {1, 2};
    //    DHT_write(data);
    Serial.print(data[0]);
    servo_pos_sweep();
    //  delay(500);
}

float* DHT_read(){

    // Reading temperature or humidity takes about 250 milliseconds!
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    // Read temperature as Fahrenheit (isFahrenheit = true)
    if (isnan(t)) {
        Serial.println("Failed to read temperature from DHT sensor!");
        return data;
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

void servoSetPosition(float pPos){
    data[2] = pPos;
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
      servoSetPosition(pPos);
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




