#include "Arduino.h"

// Define Pins
#define RED 6
#define GREEN 5
#define BLUE 3

#define FADING 50 // Fading delay time between colors

// Define Variables
int redValue, greenValue, blueValue;

void setup()
{
    Serial.begin(9600);

    // Each RGB LED as Output
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}

void loop()
{
    // Start at Red color
    redValue = 255;
    greenValue = 0;
    blueValue = 0;

    // Change from red to green
    for (int i = 0; i < 255; i++)
    {
        redValue -= 1;
        greenValue += 1;

        analogWrite(RED, redValue);
        analogWrite(GREEN, greenValue);
        delay(FADING);
    }

    // Change from green to blue
    for (int i = 0; i < 255; i++)
    {
        greenValue -= 1;
        blueValue += 1;

        analogWrite(GREEN, greenValue);
        analogWrite(BLUE, blueValue);
        delay(FADING);
    }

    // Change from blue back to red
    for (int i = 0; i < 255; i++)
    {
        blueValue -= 1;
        redValue += 1;

        analogWrite(BLUE, blueValue);
        analogWrite(RED, redValue);
        delay(FADING);
    }
}