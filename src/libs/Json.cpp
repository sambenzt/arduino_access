#include <Arduino.h>
#include <ArduinoJson.h>

#ifndef Json_h
#define Json_h

class Json
{
  public:
    static DynamicJsonDocument document(int size = 128) {
      DynamicJsonDocument document(size);
      return document;
    }

    static DynamicJsonDocument deserialize(String line, int size = 128) {
      DynamicJsonDocument document(size);
      deserializeJson(document, line);
      return document;
    }

    static String serialize(DynamicJsonDocument document) {
      String result;
      serializeJson(document, result); 
      return result;
    }
};

#endif /*Json_h*/