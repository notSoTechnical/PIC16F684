#include <xc.h>
/* By notSoTechnical 2019 */
/* Initial: AY */ 


void PORTA_init(void)
{
    PORTA=0; // ALl PORTA pins are low
    CMCON0=7; // Turn off comparators
    ANSEL=0; // Turn off ADC
    TRISA=0b111111; // RA5 to 0 are input 
    return;
}
/* END OF PORTA_init*/
 

void debounce(void)
{
    int i, j;
        for (i = 0; i< 100; i++)
        for (j = 0; j < 100; j++);
    return;
}


// CONFIG --- Configuration Word --- START
#pragma config FOSC=INTOSCIO
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config MCLRE=OFF
#pragma config CP=OFF
#pragma config CPD=OFF
#pragma config BOREN=OFF
#pragma config IESO=OFF
#pragma config FCMEN=OFF
// CONFIG --- Configuration Word --- END

int main(void) {
    PORTA_init();
    int count=-1;
    
    char trisaArray[11]={0x0F,0x0F,0x2B,0x2B,0x1B,0x1B,0x39,0x39,0x1d,0x1d,0x3F};
    char portaArray[11]={0x10,0x20,0x10,0x04,0x20,0x04,0x04,0x02,0x20,0x2,0x00};
    
    while (1) { 
        
        if (RA3==0) {
            
            debounce();
            TRISA=trisaArray[count]; 
            PORTA=portaArray[count]; 
            count++; 
            count = count%11;
            
                }    
         
    }
        
    return 0;
    
}
/* END OF MAIN ROUTINE*/

