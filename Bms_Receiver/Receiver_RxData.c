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
#include "test_receiver.h"


void analyse_data(float temperature, float soc, float chargerate)
{
  /* Local Variables */
  static float min_temperature = 0;
  static float min_soc = 0;
  static float min_chargerate = 0;
  static float max_temperature = 0;
  static float max_soc = 0;
  static float max_chargerate = 0;
  static int firstTimeFlag = 0;
  static float temperature_array[NO_OF_AVERAGE] = {0};
  static float soc_array[NO_OF_AVERAGE] = {0};
  static float chargerate_array[NO_OF_AVERAGE] = {0};                         
  float avg_temperature = 0;
  float avg_soc = 0;
  float avg_chargerate = 0;
  
   if(firstTimeFlag == 0)
  {
    firstTimeFlag = 1;     
    max_temperature = min_temperature = temperature;
    max_soc = min_soc = soc;
    max_chargerate = min_chargerate = chargerate;
    printf("              Max      Min      Avg\n");
  }
  else
  {
    Calc_MinMax(temperature, &max_temperature, &min_temperature);
    Calc_MinMax(soc, &max_soc, &min_soc);
    Calc_MinMax(chargerate, &max_chargerate, &min_chargerate);
  }
                               
   for(int i=NO_OF_AVERAGE;i>0;i--)
   {
     temperature_array[i-1] = temperature_array[i];
     soc_array[i-1] = soc_array[i];
     chargerate_array[i-1] = chargerate_array[i];
   }
    temperature_array[NO_OF_AVERAGE] = temperature;
    soc_array[NO_OF_AVERAGE] = soc;
    chargerate_array[NO_OF_AVERAGE] = chargerate;
                               
    avg_temperature = Calc_Average(temperature_array, NO_OF_AVERAGE);
    avg_soc = Calc_Average(soc_array, NO_OF_AVERAGE);
    avg_chargerate = Calc_Average(chargerate_array, NO_OF_AVERAGE);
                               
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
  /* Local variables */
  char temp_buffer[10] = {0};
  char soc_buffer[10] = {0};
  char ChargeRate_buffer[10] = {0};
  int value_count = 0;
  int copy_count = 15;
         
  while(Copy_buffer[copy_count] != ',')
  {
    temp_buffer[value_count++] = Copy_buffer[copy_count++];
  }

  copy_count +=7;
  value_count = 0;
  while(Copy_buffer[copy_count]!=',')
  {
    soc_buffer[value_count++] = Copy_buffer[copy_count++];
  }

  copy_count +=14;
  value_count = 0;
  while(Copy_buffer[copy_count]!='}')
  {
    ChargeRate_buffer[value_count++] = Copy_buffer[copy_count++];
  }

  *temperature = atof(temp_buffer);
  *soc = atof(soc_buffer);
  *chargerate = atof(ChargeRate_buffer);    
    
}

/* Function Details *******************************************************************************************
* Function Name : receive_data
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
int receive_data() 
{
	int count = 0;
	char rv_data[2000] = {0};
	char *Copy_buffer = NULL;
	float temperature = 0;
	float soc = 0;
	float chargerate = 0;
	int ret_val = 0;

	do
	{
		rv_data[0] = '\0';
		Copy_buffer = NULL;

		#if(TEST_ON == TRUE)
			test_Scanf(rv_data);
		#else
			scanf("%s", rv_data);
		#endif

		Copy_buffer = strstr(rv_data, "{\"temperature\":");

		if(Copy_buffer != NULL)
		{
			decode_data(Copy_buffer, &temperature, &soc, &chargerate);
			analyse_data(temperature, soc, chargerate);
			ret_val = 1;
		}
	}while(count++ <= STREAM_COUNT);
	
	return ret_val;
}

#if(TEST_ON == TRUE)
void test_Scanf(char *rv_data)
{
	char data[100] = "{\"temperature\":36.19,\"soc\":56.37,\"chargeRate\":0.72}";
	strcpy(rv_data , data);
}
#endif
