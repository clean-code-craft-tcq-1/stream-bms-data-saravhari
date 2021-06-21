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

/* Function Details *******************************************************************************************
* Function Name : main
* Description   : main function to receive the Data
* Arguments     : -
* Returns       : 0
* *********************************************************************************************************** */
int main() {
    char *rv_data = NULL;
    scanf("%s", rv_data);
    printf("\n\n\nReceived Data* %s\n\n",rv_data);
    printf("\n\n****************Test$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
    return 0;
}
