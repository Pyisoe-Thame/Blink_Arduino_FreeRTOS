#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
static const char led_pin = LED_BUILTIN;

// Our task: blink an LED
void toggleLED(void *parameter) {
  while(1)
  {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS); // tick period (can be scaled)
    digitalWrite(led_pin, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS); // Both lines do delay for 500ms
  }
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreate(
    toggleLED,  // Function to be called
    "Toggle LED",  // Name of task for humans
    128,  // Stack size
    NULL,  // Parameter to pass to the task
    1, // Task priority ( 0~24, 0 is the lowest priority)
    NULL  // Task handler
  );  // More arguments like core number in other MCs
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
