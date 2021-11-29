/*********************************************************** 
File name: MechDesignProject.ino 
Description: Temperature/Humidity display for arduino
Author: Emory / Gerard
Date: 11/21/2021  
***********************************************************/ 
 
#include <LiquidCrystal.h> 
#include <Servo.h>
#include <dht11.h>

Servo tservo;
Servo hservo;

dht11 DHT11;
#define DHT11PIN 2
 
int tim = 50;                       //the value of delay time 
// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(4, 6, 10, 11, 12, 13); 
int thermistorPin = 0;           // thermistor connected to analog pin 3 
 
void setup() 
{ 
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows:  
  lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner  
  tservo.attach(8);
  hservo.attach(9);
} 
 
void loop()  
{ 
  float a = analogRead(thermistorPin); 
  //the calculating formula of temperature 
  float resistor = (1023.0*10000)/a-10000; 
  float tempC = (3435.0/(log(resistor/10000)+(3435.0/(273.15+25)))) - 273.15;

  int chk = DHT11.read(DHT11PIN);
     
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0 
  lcd.print("     adeept     ");// Print a message of "Temp: "to the LCD. 
  
  lcd.setCursor(0, 1); // set the cursor to column 0, line 0 
  lcd.print("  Temp: ");// Print a message of "Temp: "to the LCD. 
  lcd.print(tempC);// Print a centigrade temperature to the LCD.  
  lcd.print(" F  "); // Print the unit of the centigrade temperature to the LCD. 

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print("Humidity:");// Print a message of "Humidity: "to the LCD.
  lcd.print((float)DHT11.humidity, 2);// Print a message of "Humidity: "to the LCD.
  lcd.print(" % "); // Print the unit of the centigrade temperature to the LCD.

  //set direction for temperature

  tempC = map(tempC,0,120,0,180);
  tservo.write(tempC);
  delay(15);

  //set direction for humidity

  humid = map(humid,0,100,0,180);
  tservo.write(humid);
  delay(15);
  
  delay(500); 
} 
