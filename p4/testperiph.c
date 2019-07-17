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
 * functionality of your ssystem.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "pantallica.h"
#define AZUL 				0x000001C0
#define VERDE 				0x00000038
#define VERDE_OSCURO		0x00000018
#define ROJO 				0x00000007
#define BLANCO				0X000001FF

#define nfilas				16
#define ncolumnas			8


#define PANTALLA_BASE_ADDR 0x00038000

int main()
{


   Xil_ICacheEnable();
   Xil_DCacheEnable();

   print("---Entering main---\n\r");


   /*
    * Peripheral SelfTest will not be run for RS232
    * because it has been selected as the STDOUT device
    */

   {

	   Xuint32 baseaddr;
	  Xuint32 Data, Data2;
	  char fila, columna, posicion,color,posicionAux;
 	   baseaddr = PANTALLA_BASE_ADDR;
 	  color=VERDE; /*ponemos color blanco */

 		xil_printf("Data configuracion =%x\r\n",Data);

 		  while (!(PANTALLICA_mWriteFIFOFull(baseaddr)))
 				{
 			  /* La pantalla es un array de 16 filas por 8 columnas
 			   * Se accede a una posición dada por columna*16+fila
 			   * El dato hay que enviarlo con el siguiente formato
 			   * 7 bits menos significativos (bits 6..0) la posición
 			   * 9 bits mas significativos (bits 31 .. 23) el color
 			   */
 			   	   for(fila=0; fila <nfilas; fila++)
 			   	   {
 			   		   if (fila<8) color=ROJO;
 			   		  else color=AZUL;
 			   		   for(columna=0; columna<ncolumnas; columna++)
 			        {
 		   			posicion=columna *nfilas + fila;

 			   		Data=   ((color & 0x1FF) << 23)| (posicion & 0x7f) ;

 			   		PANTALLICA_mWriteToFIFO(baseaddr, 0, Data);
 			   		xil_printf("Data configuracion =%d %d %08x\r\n",fila, columna,Data);
 			        }
 				}
 		   }

   }
    print("---Exiting main---\n\r");

   Xil_DCacheDisable();
   Xil_ICacheDisable();

   return 0;
}

