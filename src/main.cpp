#include <Arduino.h>
#include <Ethernet.h>
#include <ArduinoJson.h>
#include <Keypad.h>
#include "libs/EthernetConnection.cpp"
#include "libs/Json.cpp"
#include "libs/Keyboard.cpp"
#include "libs/Pir.cpp"
#include "libs/Time.cpp"
#include "libs/Buzzer.cpp"
#include "config.h"

#define G_STAND_BY "STAND BY"
#define G_EXPEND "EXPEND"
#define G_PIN_INCORRECT "PIN INCORRECT"
String G_STATUS = G_STAND_BY;

EthernetConnection ethernetConnection = EthernetConnection();
Keyboard keyboard = Keyboard();
Pir pir = Pir();
Buzzer buzzer = Buzzer();

void setup()
{
  Serial.begin(9600);
  ethernetConnection.setIp(IP);
  ethernetConnection.setDns(DNS);
  ethernetConnection.setMac(MAC);
  ethernetConnection.start();

  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Estado inicial Arduino: ");
  Serial.println(G_STATUS);
  buzzer.getStatus();
}

void loop()
{
  //Leer valores desde SAIA
  String line = ethernetConnection.readLine();

  if (line.length() > 0) 
  {
    DynamicJsonDocument document = Json::deserialize(line, line.length());
    String command = document["command"];

    if (command == "null")
    {
      Serial.println("invalid JSON:");
      Serial.println(line);
      Serial.println(command);
    }

    if (command == "ping")
    {
      DynamicJsonDocument document = Json::document();
      document["command"] = "pong";
      ethernetConnection.writeLine(Json::serialize(document));
      Serial.println(millis());
    }

    if(command == "pin-ok") {
      G_STATUS = G_EXPEND;
      //llamar a al fucnion que abre puerta
      Serial.println("Estado actual Arduino: " + G_STATUS);
    }

    if(command == "pin-fail") {
      //buzer falla
    }

    if(command == "expend-end") {
        G_STATUS = G_STAND_BY;
    }

  };

  //Leer valores del teclado y enviar a SAIA
  char key = keyboard.getKey();

  if(key && G_STATUS.equals(G_STAND_BY)) 
  {
    Serial.print("tecla ");
    Serial.println(key);
    Serial.println(millis());
    //envio tecla
    // DynamicJsonDocument document = Json::document();
    // document["command"] = "keyboard";
    // document["value"] = String(key);
    // ethernetConnection.writeLine(Json::serialize(document));
  }


  //Leer valor del Pir
  String pirStatus = pir.getStatus();
  
  ethernetConnection.maintain();

  //
}

//TODO
//buzzer
//temporizador millis
//pir
//luces