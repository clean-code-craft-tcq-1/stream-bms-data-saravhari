/* File Details ***********************************************************************************************
* File Name   :	main.c
* Author      : Arul Kumar Sundaramoorthy
* Description : Receives the BMS Data & perform calculations on received values
* Functions   : main
* *********************************************************************************************************** */

/* **************************************** Header Files **************************************************** */
#include "Receiver_RxData.h"
#include "Receiver_DataCalc.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

void analyse_data(float temperature, float soc, float chargerate)
{
  static float min_temperature = 0;
  static float min_soc = 0;
  static float min_chargerate = 0;
  static float max_temperature = 0;
  static float max_soc = 0;
  static float max_chargerate = 0;
  static int firstTimeFlag = 0;
  static float temperature_array[5] = {0};
  static float soc_array[5] = {0};
  static float chargerate_array[5] = {0};                         
  float avg_temperature = 0;
  float avg_soc = 0;
  float avg_chargerate = 0;
  
  
  printf("current -%f %f %f\n",temperature,soc,chargerate);
  if(firstTimeFlag == 0)
  {
    firstTimeFlag = 1;
    max_temperature = min_temperature = temperature;
    max_soc = min_soc = soc;
    max_chargerate = min_chargerate = chargerate;
  }
  else
  {
    Calc_MinMax(temperature, &max_temperature, &min_temperature);
    Calc_MinMax(soc, &max_soc, &min_soc);
    Calc_MinMax(chargerate, &max_chargerate, &min_chargerate);
  }
                               
   for(int i=5;i>0;i--)
   {
     temperature_array[i-1] = temperature_array[i];
     soc_array[i-1] = soc_array[i];
     chargerate_array[i-1] = chargerate_array[i];
   }
    temperature_array[5] = temperature;
    soc_array[5] = soc;
    chargerate_array[5] = chargerate;
                               
    avg_temperature = Calc_Average(temperature_array, 5);
    avg_soc = Calc_Average(soc_array, 5);
    avg_chargerate = Calc_Average(chargerate_array, 5);
                               
  
  printf("Temperature %6.2f  %6.2f  %6.2f\n",max_temperature, min_temperature, avg_temperature);
  printf("SOC         %6.2f  %6.2f  %6.2f\n",max_soc, min_soc, avg_soc);
  printf("Charge Rate %6.2f  %6.2f  %6.2f\n",max_chargerate, min_chargerate, avg_chargerate);
}

/* Function Details *******************************************************************************************
* Function Name : receive_data
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
void decode_data(char *Copy_buffer, float *temperature, float *soc, float *chargerate) 
{
  char temp_buffer[10] = {0};
  char soc_buffer[10] = {0};
  char ChargeRate_buffer[10] = {0};
  int value_count = 0;
  int copy_count = 0;

  copy_count = 15;
  value_count = 0;
  
  printf("copy buffer-%s\n",Copy_buffer);
  
  if(Copy_buffer[2] == 't')
  {         
    while((Copy_buffer[copy_count] != ',') && (value_count <= 6))
    {
      temp_buffer[value_count++] = Copy_buffer[copy_count++];
    }

    copy_count +=7;
    value_count = 0;
    while((Copy_buffer[copy_count]!=',')  && (value_count <= 6))
    {
      soc_buffer[value_count++] = Copy_buffer[copy_count++];
    }

    copy_count +=14;
    value_count = 0;
    while((Copy_buffer[copy_count]!='}') && (value_count <= 6))
    {
      ChargeRate_buffer[value_count++] = Copy_buffer[copy_count++];
    }

    printf("Temp - %s %s %s\n",temp_buffer,soc_buffer,ChargeRate_buffer);
    *temperature = atof(temp_buffer);
    *soc = atof(soc_buffer);
    *chargerate = atof(ChargeRate_buffer);
     printf("Temper -%f %f %f\n",temperature,soc,chargerate);
    
    
  }
}

/* Function Details *******************************************************************************************
* Function Name : receive_data
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
void receive_data() 
{
  int count = 0;
  char rv_data[2000] = {0};
  char *Copy_buffer = NULL;
  float temperature = 0;
  float soc = 0;
  float chargerate = 0;
  
    do
    {
      rv_data[0] = '\0';
      Copy_buffer = NULL;
            
      scanf("%s", rv_data);
      Copy_buffer = strstr(rv_data, "{\"temperature\":");
      
      printf("Rcv data-%s\n",rv_data);
      if(Copy_buffer != NULL)
      {
        decode_data(Copy_buffer, &temperature, &soc, &chargerate);
        analyse_data(temperature, soc, chargerate);
      }
      else
      {
        printf("copy data-%s\n",Copy_buffer);
      }
    }while(count++ <= 150);

}
