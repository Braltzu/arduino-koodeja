#include <Arduino_FreeRTOS.h>

// define two tasks for lukemiselle ja kirjoittamiselle
void TaskWrite( void *pvParameters );
void TaskSerialRead( void *pvParameters );

volatile int x=0;//global variable to prevent the task from forgetting the present number

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
 /* while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  } */

  // Now set up two tasks to run independently.
  xTaskCreate(
    Write
    ,  "SerialWrite"    // A name just for humans
    ,  128              // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2                // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    SerialRead
    ,  "SerialRead"
    ,  128              // Stack size
    ,  NULL
    ,  3                // Priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop(){} // Empty. Things are done in Tasks.

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void SerialRead(void *pvParameters)  // This is a task.
{
  //(void) pvParameters;
 for (;;) {  //loop
        if (Serial.available() > 0) { //enable serial port reading
            int luku = Serial.parseInt(); //read number inputs from serial port
            if (luku != 0) {  //check that the number input is not zero
                x += luku; //add the previously added number
                	Serial.println(luku); //print the present number
            }
        }

        vTaskDelay( 100 / portTICK_PERIOD_MS );  //small delay the prevent crashes
    }
  }

void Write(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
for (;;) {  //loop
        if (x > 0) { //condition to prevent numbers below zero from printing
          x--;
            Serial.println(x); //print the new number
        }

        vTaskDelay( 1000 / portTICK_PERIOD_MS );  //1 sec delay to print once per second
    }
}

  

  






  
