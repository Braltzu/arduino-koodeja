#include <Arduino_FreeRTOS.h>
#include <semphr.h>

// define tasks
void TaskReadFromSerial( void *pvParameters ); // Get commands
void TaskBlink( void *pvParameters ); // LED as actuator

//define smaphore handlers
SemaphoreHandle_t activateActuatorSem;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect.
  }

  activateActuatorSem = xSemaphoreCreateBinary();

  if ( activateActuatorSem != NULL )
    xSemaphoreGive( activateActuatorSem );  // Make the Serial Port available for use, by "Giving" the Semaphore.

  // Now set up tasks to run independently.
  
  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *) "Blink"   // A name just for humans
    ,  256  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 1 being the highest, and 4 being the lowest.
    ,  NULL );

   xTaskCreate(
    TaskReadFromSerial
    ,  (const portCHAR *) "ReadFromSerial"
    ,  256  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskReadFromSerial( void *pvParameters )
{
  (void) pvParameters;
  
  for (;;)
  {   
    if(Serial.available()>0){
      char c = Serial.read();
      if (c == '1')
        xSemaphoreGive(activateActuatorSem);
    }
    vTaskDelay( 250 / portTICK_PERIOD_MS ); 
  }
}

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
     xSemaphoreTake(activateActuatorSem, portMAX_DELAY);
     digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
     vTaskDelay( 250 / portTICK_PERIOD_MS ); // wait for one second
     digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
     vTaskDelay( 250 / portTICK_PERIOD_MS ); // wait for one second  
  }
}