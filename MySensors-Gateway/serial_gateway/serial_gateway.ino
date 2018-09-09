#define MY_RADIO_RF24
#define MY_RF24_PA_LEVEL RF24_PA_LOW
#define MY_GATEWAY_SERIAL

#define MY_DEFAULT_LED_BLINK_PERIOD 300

#define MY_DEFAULT_ERR_LED_PIN 4
#define MY_DEFAULT_TX_LED_PIN 5
#define MY_DEFAULT_RX_LED_PIN 6

#include <MySensors.h>

void setup()
{
    // Setup locally attached sensors
}

void presentation()
{
    sendSketchInfo("MySensor Gateway", "1.0");
}

void loop()
{
    // Send locally attached sensor data here
}
