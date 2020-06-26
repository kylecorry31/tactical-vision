/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Examples for ER-OLEDM0.95-2C
Display is Hardward SPI 4-Wire SPI Interface 
Tested and worked with: 
Works with Raspberry pi
****************************************************/

#include <bcm2835.h>
#include <stdio.h>
#include <time.h>
#include "ssd1351.h"

int main(int argc, char **argv)
{
    if(!bcm2835_init())
    {
        return -1;
    }

    SSD1351_begin();
    SSD1351_clear_screen(0);
    SSD1351_display();
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

