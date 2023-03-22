#include <Arduino.h>

#ifndef Convert_h
#define Convert_h

class Convert
{
  public:
    static long hexadecimalStringToLong(String recv) {
      char c[recv.length() + 1];
      recv.toCharArray(c, recv.length() + 1);
      return strtol(c, NULL, 16); 
    }
};

#endif /*Convert_h*/