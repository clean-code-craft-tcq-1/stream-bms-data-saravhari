/* *************************************************************************
* File Name   :	Receiver_RxData.h
* Description : Header file for Data Calcualtions like Mini, Max & Average
* ************************************************************************* */
#ifndef RECEIVER_RXDATA_H
#define RECEIVER_RXDATA_H

/* ******************************* Defines ******************************* */


/* ***************************** Prototypes ***************************** */
void receive_data(void);
void analyse_data(float temperature, float soc, float chargerate);
void decode_data(char *Copy_buffer);

#endif
