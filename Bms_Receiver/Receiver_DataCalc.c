/* File Details ***********************************************************************************************
* File Name   : Receiver_DataCalc.c
* Author      : Arul Kumar Sundaramoorthy
* Description : Data calculations like Minimum, Maximum & Average for given numbers
* Functions   : Calc_Maxi, Calc_Mini, Calc_Average
* *********************************************************************************************************** */

/* **************************************** Header Files **************************************************** */
#include "Receiver_DataCalc.h"

/* Function Details *******************************************************************************************
* Function Name : Calc_MinMax
* Description   : Checks the current value with the Previous maximum value
* Arguments     : current_value(float), prev_maxi(float)
* Returns       : current_value(float) or prev_maxi(float) which is greater
* *********************************************************************************************************** */
void Calc_MinMax(float current_value, float *max_value, float *min_value)
{
	if(current_value > *max_value)
	{
		*max_value = current_value;
	}
	
	if(current_value < *min_value)
	{
		*min_value = *current_value;
	}
}


/* Function Details *******************************************************************************************
* Function Name : Calc_Average
* Description   : Calculates the average for given array
* Arguments     : Val_Arr(float Array), NoOfValues(int)
* Returns       : Average(float)
* *********************************************************************************************************** */
float Calc_Average(float Val_Arr[], int NoOfValues)
{
  float Average = 0;
  float Sum = 0;
  
  if(NoOfValues != 0)
 {
   for(int i=0; i<NoOfValues; i++)
   {
     Sum += Val_Arr[i];
   }
 }
 else
 {
   return Average;
 }		
	
  Average = Sum/NoOfValues;
  
  return Average;
}
