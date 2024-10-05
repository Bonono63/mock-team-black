#include <stdint.h>
#include <stdio.h>

#include <led.h>
#include <mxc_delay.h>
#include "mxc.h"

#define I2C_INST MXC_I2C1 //i have no fucking clue what im doing its 2am 
#define I2C_SPEED 10000 //idk random value 
#define I2C_ADDR 0x50 //hardcode this later for testing


void writeData(unit8_t master, uint8_t *data, int length){
        MXC_I2C_MasterWrite(I2C_INST, master, data, length, 0);
}
void readData(uint8_t slave, uint8_t *buffer, int length){
        MXC_I2C_MasterRead(I2C_MASTER, slave_addr, buffer, length, 0);
}


int main(void)
{       
        MXC_ICC_Enable(MXC_ICC0); //it does a thing possibly
        MXC_SYS_Clock_Select(MXC_SYS_CLOCK_IPO);
        MXC_I2C_Init(I2C_INST, I2C_SPEED, 0);
        MXC_I2C_SetFrequency(I2C_INST, I2C_SPEED);

        uint8_t dataToSend = 0x55;
        uint8_t recievedData = 0x00;

        writeData(I2C_ADDR, &dataToSend, 1);
        readData(I2C_ADDR, &recievedData,1);
        printf("Retard alert\n 0x%x",recievedData);

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
