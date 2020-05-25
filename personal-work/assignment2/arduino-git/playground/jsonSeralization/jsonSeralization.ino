#include <ArduinoJson.h>

void setup(){
    Serial.begin(9600);
}

void loop(){
   // if(Serial.read() == 'j') {
        
        const size_t capacity = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3);
        DynamicJsonDocument doc(capacity);
        
        doc["sensor"] = "gps";
        doc["time"] = 1351824120;
        
        JsonArray data = doc.createNestedArray("data");
        data.add(48.75608);
        data.add(2.302038);
        
        serializeJson(doc, Serial);
        delay(500);
//        int temp = 21;
//        int humidity = 53;
//        
//        root["temperature"] = temp;
//        
//        root["humidity"] = humidity;
//        
//        root.preetyPrintTo(Serial);
        
      //  Serial.println();
    //}
}
