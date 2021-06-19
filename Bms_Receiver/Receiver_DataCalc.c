/* File Details ***********************************************************************************************
* File Name   : Receiver_DataCalc.c
* Author      : Arul Kumar Sundaramoorthy
* Description : Data calculations like Minimum, Maximum & Average for given numbers
* Functions   : Calc_Maxi, Calc_Mini, Calc_Average
* *********************************************************************************************************** */

/* **************************************** Header Files **************************************************** */
#include "Receiver_CalcStat.c"

/* Function Details *******************************************************************************************
* Function Name : Calc_Maxi
* Description   : Checks the current value with the Previous maximum value
* Arguments     : current_value(float), prev_maxi(float)
* Returns       : current_value(float) or prev_maxi(float) which is greater
* *********************************************************************************************************** */
float Calc_Maxi(float current_value, float prev_maxi)
{
  if(current_value > prev_maxi)
  {
    return current_value;
  }
  else
  {
    return prev_maxi;
  }
}

/* Function Details *******************************************************************************************
* Function Name : Calc_Mini
* Description   : Checks the current value with the Previous minimum value
* Arguments     : current_value(float), prev_mini(float)
* Returns       : current_value(float) or prev_mini(float) which is lesser
* *********************************************************************************************************** */
float Calc_Mini(float current_value, float prev_mini)
{
  if(current_value < prev_mini)
  {
    return current_value;
  }
  else
  {
    return prev_mini;
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
  
  for(int i=0; i<NoOfValues; i++)
  {
	  Sum += Val_Arr[i];
  }
  
  Average = Sum/NoOfValues;
  
  return Average;
}
