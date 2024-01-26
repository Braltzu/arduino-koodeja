#include <Arduino_FreeRTOS.h>  //include the freertos functionality

void addition(void *pvParameters); //name of task1
void decrease(void *pvParameters); //name of task2

volatile int x = 0;  //global variable to prevent the task from forgetting the present number

void setup() {  //basic arduino setup with tasks for freertos
    Serial.begin(9600);  //9600 baud rate for serial port
    
    	xTaskCreate(addition, "Addition", 128, NULL, 1, NULL);  //make 2 global tasks
    	xTaskCreate(decrease, "Decrease", 128, NULL, 2, NULL);
  
    		vTaskStartScheduler();  //Schedule the tasks, same-ish as isr from interrupts
}
void loop() {} //with tasks inside

void addition(void *pvParameters) { //task reads numbers written to serial port and adds them together and prints the present number
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
void decrease(void *pvParameters) {    //task prints the present number as long as it's above zero
    for (;;) {  //loop
        if (x > 0) { //condition to prevent numbers below zero from printing
          x--;
            Serial.println(x); //print the new number
        }

        vTaskDelay( 1000 / portTICK_PERIOD_MS );  //1 sec delay to print once per second
    }
}