/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "InterruptRoutines.h"
#include "VariabiliGlobali.h"

#define HIGH 1
#define LOW 0

CY_ISR(Custom_LED_RGB_ISR)
{
    count++; //il contatore si aggiorna ogni 250ms
    
    if(stato==1)
    {
        RED_Led_Write(LOW);
        GREEN_Led_Write(LOW);
    }
    
    else if(stato==2)
    {
        RED_Led_Write(LOW);
        
        if(count==4)
        {   //cambio lo stato del verde ogni 4 conteggi, cioè ogni secondo (250ms*4=1s)
            GREEN_Led_Write(!GREEN_Led_Read());
            count=0;
        }
    }
    
    else if(stato==3)
    {
        GREEN_Led_Write(LOW);
        
        if(count==4)
        {   //cambio lo stato del rosso ogni 4 conteggi, cioè ogni secondo (250ms*4=1s)
            RED_Led_Write(!RED_Led_Read());
            count=0;
        }
    }
    
    else if(stato==4)
    {
        if(count==2)
        {   //cambio lo stato del rosso ogni 2 conteggi, cioè ogni 0.5 secondi (250ms*2=0.5s)
            RED_Led_Write(!RED_Led_Read());
            count=0;
        }
        //lo stato del verde è sempre opposto a quello del rosso per l'intero periodo
        GREEN_Led_Write(!RED_Led_Read()); 
        
    }
    
    else if(stato==5)
    {   //cambio lo stato del rosso ogni 250ms, cioè ogni volta che si verifica l'interrupt
        RED_Led_Write(!RED_Led_Read()); 
        //cambio lo stato del verde ogni 250ms, cioè ogni volta che si verifica l'interrupt, mantenendolo opposto a quello del rosso
        GREEN_Led_Write(!RED_Led_Read()); 
   }                                      
    
    else if(stato==6)
    {
        if(count<4)
        {
            RED_Led_Write(LOW);
            GREEN_Led_Write(LOW);
        }
        
        if(count==4)
        {
            GREEN_Led_Write(!GREEN_Led_Read());
        }
        
        if(count==6)
        {    //cambio lo stato del rosso ogni 6 conteggi, cioè ogni 1.5 secondi (250ms*6=1.5s)
             RED_Led_Write(!RED_Led_Read());
        }
        
        if(count==8)
        {   //cambio lo stato di entrambi i colori ogni 8 conteggi, alla fine del periodo, cioè ogni 2 secondi (250ms*8=2s)
            RED_Led_Write(!RED_Led_Read());
            GREEN_Led_Write(!GREEN_Led_Read());
            count=0;
        }
    }
    
    else if(stato==7)
    {
        if(count==2)
        {
            GREEN_Led_Write(!GREEN_Led_Read());
        }
        
        if(count==4)
        {
            GREEN_Led_Write(!GREEN_Led_Read());
            RED_Led_Write(!RED_Led_Read());
            count=0;
        } 
    }
    
    Timer_LED_RGB_ReadStatusRegister();
}
/* [] END OF FILE */
