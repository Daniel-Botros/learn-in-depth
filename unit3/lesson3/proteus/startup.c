//startup.c
//Eng.Daniel

#include <stdint.h>
//#define STACK_Start_SP 0x20001000
extern int main(void);

void Reset_Handler (void);

void Default_Handler (){
    Reset_Handler ();
}

void NMI_Handler (void) __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler (void) __attribute__((weak,alias("Default_Handler")));;
void MM_fault_Handler (void) __attribute__((weak,alias("Default_Handler")));;
void Bus_fault (void) __attribute__((weak,alias("Default_Handler")));;
void Usage_fault_Handler (void) __attribute__((weak,alias("Default_Handler")));;

extern unsigned int STACK_Start_SP;

uint32_t vectors[] __attribute__((section(".vectors"))) ={

    (uint32_t) &STACK_Start_SP,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &H_fault_Handler,
    (uint32_t) &MM_fault_Handler,
    (uint32_t) &Bus_fault,
    (uint32_t) &Usage_fault_Handler
};

extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;


void Reset_Handler (void){

    //copy data form rom to ram
    unsigned int DATA_size = (unsigned char*) &_E_DATA - (unsigned char*) &_S_DATA ;
    unsigned char* P_src = (unsigned char*)&_E_text ;
    unsigned char* P_dst = (unsigned char*)&_S_DATA ;
    
    for (int i=0 ; i< DATA_size ; i++ ){

        *((unsigned char*)P_dst++) =  *((unsigned char*)P_src++);

    }

    //init .bss in SRAM =0

    unsigned int bss_size = (unsigned char*) &_E_bss - (unsigned char*) &_S_bss ;
    for (int i=0 ; i< bss_size ; i++ ){

        *((unsigned char*)P_dst++) =  (unsigned char)0;

    }
    //jumb to main

    main();
}