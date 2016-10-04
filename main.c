/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif


#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include <stdio.h>         /* Includes sprintf */
#include <string.h>        


#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "uart.h"
#include "bluetooth.h"

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{
    
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    uart_setup();
    
    bool result;
    result = bluetooth_setup();
    
    if (result == true) {
        PORTBbits.RB12 = 1;
    } else {
        PORTBbits.RB12 = 0;
    }
    
    Nop();
    
    /* TODO <INSERT USER APPLICATION CODE HERE> */
    //volatile unsigned long x = 0;
    PORTBbits.RB14 = 1;
    
    //long i = 0;
    //long x = 0;
    
    bool endLoop = false;
    char messageBox[CHARACTERS] = {0};
    
    
    while(!endLoop)
    {
//        bool isDataAvailable = false;
//        
//        char newString[30] = {0};
//        isDataAvailable = uart1_recieveData(newString);
//        
//        if (isDataAvailable == true) {
//            if (newString[0] == 'A' && newString[1] == 'O' && newString[2] == 'K' ) {
//                strcpy(newString, "Yo OK\r\n");
//            }
//            uart1_sendData(newString);
//        }
        
//        while (x < 53846) {
//            x = x + 1;
//            for (i = 0; i < 50; i++) {
//                Nop();
//            }
//        }
//        PORTBbits.RB14 = ~PORTBbits.RB14;
//        x = 0;
        
        get_response(messageBox);
        if (messageBox[0] == 'D') {
            endLoop = true;
        }
        
    }
    
    bluetooth_shutdown();
    
    return 0;
}
