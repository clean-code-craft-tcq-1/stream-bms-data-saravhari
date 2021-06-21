/* File Details ***********************************************************************************************
* File Name   :	main.c
* Author      : Arul Kumar Sundaramoorthy
* Description : Receives the BMS Data & perform calculations on received values
* Functions   : main
* *********************************************************************************************************** */

/* **************************************** Header Files **************************************************** */
#include "Receiver_DataCalc.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "time.h"

void delay(int seconds)
{
  // Converting time into milli_seconds
  int milli_seconds = 1000 * seconds;

  // Storing start time
  clock_t start_time = clock();
  printf("Start %ld\n",start_time);

  // looping till required time is not achieved
  // which is begin time + wait time in milliseconds 
  while (clock() < start_time + milli_seconds);
  start_time = clock();
  printf("Stop %ld\n",start_time);
}

/* Function Details *******************************************************************************************
* Function Name : main
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
int main() {
  int count;
  char rv_data[1000];
  char search[] = "{\"temperature\":";
  char *Copy_buffer = NULL;
    do
    {
      scanf("%s", rv_data);
      ptr = strstr(rv_data, search);
      if(ptr != NULL)
      {
        printf("\n%d-Received Data* %s\n",count,ptr);
      }
      else
      {
      }     
    }while(count++ <= 150)
    return 0;
}
