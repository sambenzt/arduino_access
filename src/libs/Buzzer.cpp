#include <Arduino.h>  

#ifndef Buzzer_h
#define Buzzer_h

class Buzzer
{
  private:

  public:
    void getStatus() {
      String status = "ON";
      Serial.println(status);
    }

};

#endif /*Buzzer_h*/