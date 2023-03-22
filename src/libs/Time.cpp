#include <Arduino.h>

#ifndef Time_h
#define Time_h

class Time
{
  private:
    long start;
    long end;
    bool debug;

  public:
    Time(bool debug = false)
    {
      this->start = millis();
      this->debug = debug;
    }

    void setStart() {
       this->start = millis();
    }

    bool lessThanOrEqual(long value) {
      this->end = millis();
      long diff = this->end - this->start; 
      bool result = diff <= value; 
      this->print(String(diff) + " less than or equal " + String(value) + " : " + String(result));
      return result;
    }
    
    bool greaterThanOrEqual(long value) {
      this->end = millis();
      long diff = this->end - this->start; 
      bool result = diff >= value;
      this->print(String(diff) + " greater than or equal " + String(value) + " : " + String(result));
      return result;
    }

    bool between(long minValue, long maxValue) {
      this->end = millis();
      long diff = this->end - this->start; 
      bool result = diff >= minValue && diff <= maxValue;
      this->print(String(diff) + " between " + String(minValue) + " and " + String(maxValue) + " : " + String(result));
      return result;
    }

    void print(String value) {
      if(this->debug) {
        Serial.println("start: " + String(this->start) + " - end: " + String(this->end) + " - " + value);
      }
    }

};

#endif /*Time_h*/