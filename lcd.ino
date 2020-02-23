#include <LiquidCrystal.h>    // importa libreria
#include <DHT.h>

const int sensorDHT=10;
int sensorPin=8;
int sensorPin2=8;
int sensorValue=0;

int temp = 0, humedad, lluvia;
int t = 1023;

DHT dht (sensorDHT,DHT11);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 de modulo 1602A

void setup() {
  Serial.begin(9600); //Comunicacion con la PC a 9600 batios
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
  dht.begin();//iniciamos nuestro sensor
  pinMode (8,INPUT); 
  pinMode(10, INPUT);
}

void loop() {
  
  int lluvia= map(analogRead(A1), 0.00, 1023, 30,0);//map() 
      sensorValue = analogRead(sensorPin);
      humedad= dht.readHumidity(); //Permite leer la humedad incluyendo la libreria 
      temp= dht.readTemperature(); //Permite leer la temperatura "" "" 
      //Serial.println("");
  lcd.setCursor(0, 0);      // ubica cursor en columna 0, linea 0
  lcd.print("Temperatura:");
  lcd.println(temp);
  lcd.print(" °C");// escribe el texto en pantalla
  lcd.setCursor(0, 1);      // ubica cursor en columna 0, linea 1
  lcd.print("Humedad:");
  lcd.println(humedad);   // escribe valor en segundos devuelto por funcion millis()
  lcd.print(" %");     // imprime a continuacion abreviatura de segundos
  lcd.setCursor(0, 2);
  lcd.print("LLuvia: ");
  lcd.print(lluvia);
  lcd.print("mm");    
     /* Serial.print("Temperatura: ");
      Serial.print(temp);
      Serial.print("°C"); //temperatura: 21°C
      Serial.print("Humedd:");
      Serial.print(humedad);
      Serial.print("%");
      Serial.println(""); 
      Serial.print("LLuvia: ");
      Serial.print(lluvia);
      Serial.print("mm");*/
  delay(500);
}
