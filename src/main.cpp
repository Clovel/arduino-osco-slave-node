/**
 * @brief Main source file. Contains the main routines.
 * 
 * @file main.cpp
 */

/* Includes -------------------------------------------- */
#include <Arduino.h>

/* Defines --------------------------------------------- */
#define LED_GREEN_PIN 8
#define LED_YELLOW_PIN 7
#define LED_RED_PIN 6
#define LOG_BAUDRATE 115200U

/* Global variables ------------------------------------ */

/* Static variables ------------------------------------ */
static int sPinGreenState  = 0;
static int sPinYellowState = 0;
static int sPinRedState    = 0;

/* On-boot routine ------------------------------------- */
void setup(void) {
    /* Set the PIN mode */
    pinMode(LED_GREEN_PIN,  OUTPUT);
    pinMode(LED_YELLOW_PIN, OUTPUT);
    pinMode(LED_RED_PIN,    OUTPUT);

    /* Set up serial port */
    Serial.begin(LOG_BAUDRATE);

    /* System boot succesful */
    Serial.println("[BOOT ] System boot succesful");
}

/* Loop routine ---------------------------------------- */
void loop(void) {
    /* Set LED state */
    sPinGreenState  = sPinGreenState  == HIGH ? LOW : HIGH;
    sPinYellowState = sPinYellowState == HIGH ? LOW : HIGH;
    sPinRedState    = sPinRedState    == HIGH ? LOW : HIGH;
    digitalWrite(LED_GREEN_PIN,  sPinGreenState);
    digitalWrite(LED_YELLOW_PIN, sPinYellowState);
    digitalWrite(LED_RED_PIN,    sPinRedState);

    /* Loop avery 1 second */
    delay(1000U);
}
