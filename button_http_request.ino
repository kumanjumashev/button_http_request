#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

int buttonState; //Переменная для кнопки
int buttonPin = 13; //Переменная пина кнопки
int ledPin = 15; //Переменная пина лампочки

void setup(){
  pinMode(buttonPin, INPUT);//То что должна делать кнопка
  pinMode(ledPin, OUTPUT);//То что должна делать лампочка
}

void sendRequest(int value) {

  HTTPClient http;
  WiFiClient client;
  // Указываем адрес на который хотим отправить запрос
  http.begin(client, "http://192.168.0.100/toggle/");
  // Отправляем запрос и записываем ответный код в httpCode
  int httpCode = http.GET();
  Serial.printf("[HTTP] GET... code: %d\n", httpCode);
}

void loop(){ 
 buttonState = digitalRead(buttonPin);//Находим значение кнопки
 Serial.print(buttonState);
 if(buttonState == HIGH){//Если кнопка нажата
   sendRequest(HIGH);//То включить лампочку
 }
}
