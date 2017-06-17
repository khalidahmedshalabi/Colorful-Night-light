/*
    This is the code that turns on and changes the color of the RGB LED
*/

// The analog pin which the sensor's V(OUT) pin is connected to
#define SENSOR_PIN   0

// The LEDs
#define RED_LED     11
#define GREEN_LED   9
#define BLUE_LED    10

// This is the first thing that is called right after the Arduino board is turned on
void setup()
{
    // Initialize LEDs as output
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    // Initialize the sensor as input
    pinMode(SENSOR_PIN, INPUT);

    // Start serial connection with the computer which the board is connected to
    Serial.begin(9600);
}

// This function keeps running over and over and over again
// It's a good place to add stuff that needs to be done more than once
void loop()
{
    // Read voltage from the temperature sensor
    int reading = analogRead(SENSOR_PIN);

  	// Convert ADC reading (10-bit) to voltage
 	float voltage = reading * (5.0 / 1024.0);

    // Calculate temperature
    float temperature = (voltage - 0.5) * 100;

    /*
        Conversion help:
            - Resolution of tmp sensor: 10 mV per degree centigrade
            - Offset: 500 mV to allow negative temperatures to be detected

    */

    //Serial.println(temperature);

    // Change the color of the LED based on temperature
    if(temperature < -20.0)
    {
        // Solid blue if temperature is below -20 C
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 255);
    }
  	else if(temperature >= -20.0 && temperature < -10.0)
    {
        // Lighter blue if temp is anywhere between -20 and -10
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 200);
    }
    else if(temperature >= -10.0 && temperature < 0.0)
    {
        // Lighter blue if temp is anywhere between -10 and 0
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 150);
    }
  	else if(temperature >= 0.0 && temperature < 5.0)
    {
        // Lighter blue if temp is anywhere between 0 and 5
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 120);
    }
  	else if(temperature >= 5.0 && temperature < 25.0)
    {
        // Lighter blue if temp is anywhere between 5 and 25
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 100);
    }
    else if(temperature >= 25.0 && temperature < 40.0)
    {
        // Yellow light if temp is anywhere between 24 and 40
        analogWrite(RED_LED, 220);
        analogWrite(GREEN_LED, 200);
        analogWrite(BLUE_LED, 0);
    }
    else if(temperature >= 40.0 && temperature < 80.0)
    {
        // Orange light if temp is anywhere between 39 and 80
        analogWrite(RED_LED, 255);
        analogWrite(GREEN_LED, 138);
        analogWrite(BLUE_LED, 0);
    }
    else
    {
        // Red light if temperature is above 80
        analogWrite(RED_LED, 255);
        analogWrite(GREEN_LED, 0);
        analogWrite(BLUE_LED, 0);
    }

    // Rest for 200 mSec and then repeat
    delay(200);
}
