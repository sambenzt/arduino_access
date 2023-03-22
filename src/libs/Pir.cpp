#include <Arduino.h>

#ifndef Pir_h
#define Pir_h

class Pir
{
  private:

  public:
    Pir()
    {
       
    }

    String getStatus() {
      String status = "ON";
      return status;
    }

};

#endif /*Pir_h*/