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

/* Function Details *******************************************************************************************
* Function Name : receive_data
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
void decode_data(char *Copy_buffer) 
{
  char temp_buffer[10] = {0};
  char soc_buffer[10] = {0};
  char ChargeRate_buffer[10] = {0};
  float *bms_parameters;
  int value_count = copy_count = 0;
  
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


    bms_parameters[0] = atof(temp_buffer);
    bms_parameters[1] = atof(soc_buffer);
    bms_parameters[2] = atof(ChargeRate_buffer);
    
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
  float temperature = soc = chargerate = 0;  
  float *bms_parameters = NULL;
  
    do
    {
      rv_data[0] = '\0';
      Copy_buffer = NULL;
            
      scanf("%s", rv_data);
      Copy_buffer = strstr(rv_data, "{\"temperature\":");
      
      if(Copy_buffer != NULL)
      {
        decode_data(Copy_buffer, bms_parameters);
        analyse_data(bms_parameters);
      }    
    }while(count++ <= 150);

}
