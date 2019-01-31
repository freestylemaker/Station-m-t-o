#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <RtcDS3231.h>
#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(7, DHT11);
RtcDS3231<TwoWire> clock(Wire);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
lcd.begin(16, 2);
clock.Begin();
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

RtcDateTime now = clock.GetDateTime();

lcd.setCursor(0, 0);  

lcd.print(now.Hour());
lcd.print(":");
lcd.print(now.Minute());
lcd.print(" ");
lcd.print(now.Day());
lcd.print("/");
lcd.print(now.Month());
lcd.print("/");
lcd.print(now.Year());

lcd.setCursor(0, 1);  


int temperature = dht.readTemperature();
int humidity = dht.readHumidity();

lcd.print("Temp:");  
lcd.print(temperature);
lcd.print("C ");

lcd.print("Hum:");  
lcd.print(humidity);
lcd.print("%");

}
