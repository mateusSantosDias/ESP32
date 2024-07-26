#include <Arduino.h>
#include <RH_ASK.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#include "TagIndividuo.h"
#include "TagMaquina.h"

#define LED_INTERNO 2

RH_ASK Transmiter;
TagIndividuo Individuo;
TagMaquina Maquina;

const char *msgIndividuo = "Ping", *msgMaquina = "Maquina";
const char* ssid = "SIEBEN ZWANZIG";
const char* password = "citta@2021";

const char* serverUrl = "http://192.168.1.11:3000/";

void setup() 
   {

       Serial.begin(9600); 

       while (!Serial);

      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED){

          delay(100);
          Serial.print(".");
      }
      Serial.println("Conectado");

   }

void loop() 
   {    
      
      if(WiFi.status()  == WL_CONNECTED){

        HTTPClient http;
        http.begin(serverUrl);

        http.addHeader("content-Type", "application/json");

        String JsonString = "{\"status\":\"ligado\"}";

        int httpResponseCode = http.POST(JsonString);

        Serial.println("Tentando GET no servidor");

        if (httpResponseCode > 0){

          String response = http.getString();

          Serial.println("Resposta do servidor");
          Serial.println(response);

          DynamicJsonDocument responseDoc(200);
          DeserializationError error = deserializeJson(responseDoc, response);

          if (error){

            Serial.print("Falha ao processar o JSON");
            Serial.println(error.c_str());
          } else {

            const char* status = responseDoc["status"];
            Serial.println(status);
          }  
        } else{

          Serial.print("Erro na requisição.");
          Serial.println(httpResponseCode);
        }
        
      }

      delay(10000);
   }
