/* *************************************************************************
* File Name   :	Receiver_RxData.h
* Description : Header file for Data Calcualtions like Mini, Max & Average
* ************************************************************************* */
#ifndef RECEIVER_RXDATA_H
#define RECEIVER_RXDATA_H

/* ******************************* Defines ******************************* */
#define NO_OF_AVERAGE 5
#define NO_OF_DIGITS  6
#define STREAM_COUNT 150


/* ***************************** Prototypes ***************************** */
void receive_data(void);
void analyse_data(float temperature, float soc, float chargerate);
void decode_data(char *Copy_buffer, float *temperature, float *soc, float *chargerate);

#if(TEST_ON == TRUE)
void test_Scanf(char *rv_data);
#endif

#endif
