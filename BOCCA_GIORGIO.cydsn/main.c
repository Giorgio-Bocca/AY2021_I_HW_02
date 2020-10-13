/* ========================================
*   \file main.c
*   \brief Main file for project ASSIGNMENT 02: RGB LED CONTROL
*
*   This project shows how to control the blink of a RGB Led
*   with a timer and ISR. The code of the isr is written
*   in the file InterruptRoutines.c.
*
*   "Alla pressione del tasto, cambio la sequenza di lampeggiamento dei due colori
*    secondo le varie configurazioni d'interesse. Per tenere traccia del periodo mi 
*    sono servito invece di un contatore, aggiornato dall'interrupt ogni 250ms, 
*    con il quale è stato possibile cambiare la frequenza di lampeggiamento dei 
*    signoli canali a seconda della configurazione corrente"
*
*   \author Giorgio Bocca
 
* ========================================
*/
#include "project.h"
#include "InterruptRoutines.h"
#include "VariabiliGlobali.h"

#define HIGH 1
#define LOW 0

int count=0;
int stato=1; 

int main(void)
{
    int val=1; 
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Timer_LED_RGB_Start(); 
    LED_RGB_ISR_StartEx(Custom_LED_RGB_ISR);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
        /* Place your application code here. */
        val = PushButton_Read(); //leggo il valore della porta collegata al PushButton
        if(val==LOW)
        {
            CyDelay(400); 
            stato++;  //cambio la configurazione di lampeggiamento
            count = 0; //azzero il contatore 
        }
        
        if(stato==8)
        {
                stato=1; //una volta raggiunta l'ultima configurazione, riparto alla prima 
        }
    }
}
/* [] END OF FILE */
