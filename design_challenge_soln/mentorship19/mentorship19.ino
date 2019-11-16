/* ELEC / CPEN Workshop For UBC BEST Mentorship 2019/2020
 *  Reading from a photoresistor and DHT 22 sensor, and output a servo signal based on situation and RGB LED
 *  Using Arduino Uno, LED, potentiometer, DHT22, 3x1k resistors
 *  By: Alessandro Narciso


Servo setup: https://www.arduino.cc/en/Tutorial/Knob
DHT setup: https://www.instructables.com/id/How-to-use-DHT-22-sensor-Arduino-Tutorial/
RGB setup: https://randomnerdtutorials.com/electronics-basics-how-do-rgb-leds-work/
Photoresistor setup: https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/

 */
/*----------------------------------------------------------*/

/**** LIBRARIES ********************/
#include "DHT.h"
#include "Servo.h"

/**** PINS DEFINITIONS ********************/
//temp/hum sensor pins
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

//photoresistor pin
#define lightPin 2

//servo pin
#define servoPin 6

//LED pins
int RGB_red = 9;
int RGB_green = 8;
int RGB_blue = 11;

/**** INITIALIZE ********************/
DHT dht(DHTPIN, DHTTYPE); //temp/hum sensor

//servo motor
Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position

float lightSensorValue = 0;

//SETUP
void setup()
{
  // to potentiometer ground, potentiometer positive to 5V pin
  // in series with 4.7k ohm R to ground
  pinMode(lightPin, INPUT);
  
  // LED setup
  pinMode(RGB_red, OUTPUT);
  pinMode(RGB_green, OUTPUT);
  pinMode(RGB_blue, OUTPUT);

  //servo pins
   myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  
  // DHT setup
  dht.begin();

  //define baud rate
  Serial.begin(9600);
}

//LOOP
void loop()
{
  // reading the value from the light sensor
  lightSensorValue = analogRead(lightPin);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  // sensor values from DHT
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // printing the sensor outputs on serial monitor

  //for debugging and calibrating photoresistor voltage drop
  //Serial.print("Photoresistance: ");
  //Serial.print(lightSensorValue);
  //when in series with 1k resistor: low = 0-100, high = 900
   
 // convert photoresistor resistance readings to more meaningful values 
  float lightPercent = (900 - (900 - lightSensorValue))/900 * 100;
  
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent);
  Serial.print(" %");
  Serial.print("\t");
  
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  
  Serial.print("\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");

  
  //change LED color to red if conditions are bad
  if(lightPercent >= 50 || t > 26)
  {
    digitalWrite(RGB_red,LOW);
    digitalWrite(RGB_blue,HIGH);
    digitalWrite(RGB_green,HIGH);

    for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
      
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    
    for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
  }

  else if(lightPercent >= 50 && lightPercent < 85 || (t >= 24 && t <=26))
  {
    digitalWrite(RGB_red,HIGH);
    digitalWrite(RGB_blue,LOW);
    digitalWrite(RGB_green,HIGH);

    for (pos = 0; pos <= 180; pos += 3) { // goes from 0 degrees to 180 degrees
      
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(7);                       // waits 15ms for the servo to reach the position
    }
    
    for (pos = 180; pos >= 0; pos -= 3) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(7);                       // waits 15ms for the servo to reach the position
    }
  }

  else if(lightPercent < 50 && t < 24){
    digitalWrite(RGB_red,HIGH);
    digitalWrite(RGB_blue,HIGH);
    digitalWrite(RGB_green,LOW);
    
  }
  
  // seperator for lines
  Serial.println("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

  //delay
  delay(1000);

}
