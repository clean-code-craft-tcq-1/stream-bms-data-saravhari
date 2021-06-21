/* *************************************************************************
* File Name   :	Receiver_DataCalc.h
* Description : Header file for Data Calcualtions like Mini, Max & Average
* ************************************************************************* */
#ifndef RECEIVER_DATACALC_H
#define RECEIVER_DATACALC_H
#pragma once

/* ******************************* Defines ******************************* */


/* ***************************** Prototypes ***************************** */
void Calc_MinMax(float current_value, float *max_value, float *min_value);
float Calc_Average(float Val_Arr[], int NoOfValues);

#endif
