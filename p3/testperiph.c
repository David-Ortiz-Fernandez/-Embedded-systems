/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include <xstatus.h>
#include "my_plb_peripheral.h"

#define XPAR_RS232_UART_1_BASEADDR 0x84000000
#define pen 0x00038000
int getNumber (){

	Xuint8 byte;
	Xuint8 uartBuffer[16];
	Xboolean validNumber;
	int digitIndex;
	int digit, number, sign;
	int c;

	while(1){
		byte = 0x00;
		digit = 0;
		digitIndex = 0;
		number = 0;
		validNumber = XTRUE;

		//get bytes from uart until RETURN is entered

		while(byte != 0x0d && byte != 0x0A){
			byte = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
			uartBuffer[digitIndex] = byte;
			XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,byte);
			digitIndex++;
		}

		//calculate number from string of digits

		for(c = 0; c < (digitIndex - 1); c++){
			if(c == 0){
				//check if first byte is a "-"
				if(uartBuffer[c] == 0x2D){
					sign = -1;
					digit = 0;
				}
				//check if first byte is a digit
				else if((uartBuffer[c] >> 4) == 0x03){
					sign = 1;
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			else{
				//check byte is a digit
				if((uartBuffer[c] >> 4) == 0x03){
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			number = (number * 10) + digit;
		}
		number *= sign;
		if(validNumber == XTRUE){
			return number;
		}
		print("This is not a valid number.\n\r");
	}
}


int main() 
{
   XGpio GpioOutput;
   XGpio GpioInput;
   char key;
   Xil_ICacheEnable();
   Xil_DCacheEnable();
   int op=0;
   int op1;
   int op2;
   int sum;
   xil_printf("MENU\n\r");

   while(key!='3'){
   xil_printf("1  Pulsar Boton \n\r");
   xil_printf("2  Soltar Boton \n\r");
   xil_printf("3  Salir");
   print("\r\n");

   //key = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
   	 //  switch(key){
   	  // case '1':
   		//   op=getNumber();
   		  // XGpio_Initialize(&GpioOutput, XPAR_XPS_UARTLITE_0_DEVICE_ID);

   		 //  XGpio_SetDataDirection(&GpioOutput, 1, 0x0);


   		  // XGpio_DiscreteWrite(&GpioOutput, 1,op);
   		   MY_PLB_PERIPHERAL_mWriteSlaveReg0(pen, 1, 0);

   		   //XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,key);
   		   //XGpio_Initialize(&GpioOutput, XPAR_XPS_GPIO_0_DEVICE_ID);
   		   //XGpio_SetDataDirection(&GpioOutput, 1, 0x0);
   		   //XGpio_DiscreteWrite(&GpioOutput, 1, op);
   		   //op=0;
   		   //break;
   	   //case '2':

   		 //  break;
   	   //default:
   		 //  break;
   	   //}
   	print("\r\n");
   }

   xil_printf("SALIENDO\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}



