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
  int count = 0;
  char rv_data[1000];
  char search[] = "{\"temperature\":";
  char *temp_buffer = NULL;
  char *soc_buffer = NULL;
  char *ChargeRate_buffer = NULL;
  char *Copy_buffer = NULL;
  int copy_count = 15;
  int value_count = 0;
  
  float temperature = 0;
  float soc = 0;
  float chargerate = 0;
  
  
    do
    {
      temp_buffer = soc_buffer = ChargeRate_buffer = NULL;
      copy_count = 15;
      value_count = 0;
      
      scanf("%s", rv_data);
      Copy_buffer = strstr(rv_data, search);
      if(Copy_buffer != NULL)
      {
        printf("\n%d-Received Data* %s\n",count,Copy_buffer);
        if(Copy_buffer[2] == 't')
        {
         
          while(Copy_buffer[copy_count]!=',')
          {
            temp_buffer[value_count++] = Copy_buffer[copy_count++];
          }
          
          /*copy_count +=7;
          while(Copy_buffer[copy_count]!=',')
          {
            soc_buffer[value_count++] = Copy_buffer[copy_count++];
          }
          
          copy_count +=14;
          while(Copy_buffer[copy_count]!='}')
          {
            ChargeRate_buffer[value_count++] = Copy_buffer[copy_count++];
          }*/
          
          //temperature = atof(temp_buffer);
          /*soc = atof(soc_buffer);
          chargerate = atof(ChargeRate_buffer);*/
          
          //printf(" Temperature-%f-%f-%f\n",temperature,soc,chargerate);
            
        }
        
      }
      else
      {
      }     
    }while(count++ <= 150);
  
    return 0;
}
