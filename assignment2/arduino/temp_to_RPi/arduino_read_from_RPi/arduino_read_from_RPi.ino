int r;
void setup(){
 Serial.begin(9600);
 r = 1; 
}

void loop(){
  if(Serial.available()){
    ///From RPi to Arduino
    r = r * (Serial.read() - '0');
    //  converting the value of chars to integer
    Serial.println(r);
  }
}
