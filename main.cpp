// F767ZI PWM test  D6/PE_9 TIM1_CH1  or D13/PA_5 TIM2_CH1

#include "mbed.h"
#define PRREG(z) printf(#z" 0x%x\n",z)

#if 0
PwmOut pwm(D6), led(LED2);

int main()
{
    printf("D6 PE_9\n");
    // specify period first, then everything else
   // pwm.period(0.001f);  //  second period
   //pwm.write(0.50f);  // 50% duty cycle
   
// manual 1 mhz
    PRREG(RCC->APB2ENR);
    PRREG(GPIOE->AFR[1]);  //alt PE_9
    TIM1->PSC = 0;
    TIM1->ARR = 216-1;
    TIM1->CCR1 = 216/2;
    TIM1->CNT = 0;
    TIM1->CR1 = 1;  
    
    PRREG(TIM1->CR1);
    PRREG(TIM1->PSC);
    PRREG(TIM1->ARR);
    PRREG(TIM1->CCR1);
    led.period(2.0);
    led.write(0.5);
    while (1);         // led flashing
}
#else
PwmOut pwm(D13), led(LED3);

int main()
{
    printf("D13 PA_5\n");
    // specify period first, then everything else
    //pwm.period(0.001f);  //  second period
     //pwm.write(0.50f);  // 50% duty cycle

// manual 1 mhz
    PRREG(RCC->APB1ENR);
    PRREG(GPIOA->AFR[0]);  //alt PA_5
    TIM2->PSC = 0; 
    TIM2->ARR = 108-1;
    TIM2->CCR1 = 108/2;
    TIM2->CNT = 0;   // need this
    TIM2->CR1 =  TIM_CR1_CEN;  

    PRREG(TIM2->CR1);
    PRREG(TIM2->PSC);
    PRREG(TIM2->ARR);
    PRREG(TIM2->CCR1);
    
    printf("us_ticker\n");
    PRREG(TIM5->CR1);  // us_ticker
    PRREG(TIM5->PSC);
    PRREG(TIM5->ARR);
    PRREG(TIM5->CCR1);
    PRREG(TIM5->CNT);
    
    led.period(0.5);
    led.write(0.5);
    while (1);         // led flashing
}
#endif