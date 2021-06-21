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
  float avg_temperature = 0;
  float avg_soc = 0;
  float avg_chargerate = 0;
  
  Calc_MinMax(temperature, &max_temperature, &min_temperature);
  Calc_MinMax(soc, &max_soc, &min_soc);
  Calc_MinMax(chargerate, &max_chargerate, &min_chargerate);
  
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
  
  temp_buffer[0] = soc_buffer[0] = ChargeRate_buffer[0] = '\0';
  copy_count = 15;
  value_count = 0;
  
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


    *temperature = atof(temp_buffer);
    *soc = atof(soc_buffer);
    *chargerate = atof(ChargeRate_buffer);
    
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
      
      if(Copy_buffer != NULL)
      {
        decode_data(Copy_buffer, &temperature, &soc, &chargerate);
        analyse_data(temperature, soc, chargerate);
      }    
    }while(count++ <= 150);

}
