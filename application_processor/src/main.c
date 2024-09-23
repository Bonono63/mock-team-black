#include <stdint.h>
#include <stdio.h>

#include <led.h>
#include <mxc_delay.h>

int main(void)
{
        LED_Init();
        
        while (1)
        {
                LED_On(0);
                LED_On(1);
                MXC_Delay(MXC_DELAY_MSEC(500));
                LED_Off(0);
                LED_Off(1);
                MXC_Delay(MXC_DELAY_MSEC(500));

                printf("Hello World\n");
        }

        return 0;
}
