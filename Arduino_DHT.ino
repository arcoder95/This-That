

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <dht.h>

#define dht_dpin A0

dht DHT;

// measures the air humidity & temperature, and prints the results on LCD-screen every 2 seconds.

void setup() {
  lcd.begin(16, 2);
  lcd.print("Tervetuloa!");
  pinMode(A0,INPUT);
  delay(3000);

}

void loop() {
  DHT.read11(dht_dpin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T= ");
  lcd.print(DHT.temperature);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("AH= ");
  lcd.print(DHT.humidity);
  lcd.print(" %");
  delay(2000);
  

}
