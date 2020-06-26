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
    FILE *pFile ;
    /* 1 pixel of 888 bitmap = 3 bytes */
    size_t pixelSize = 3;
    unsigned char bmpBuffer[OLED_WIDTH * OLED_HEIGHT * 3];

    if(!bcm2835_init())
    {
        return -1;
    }

    SSD1351_begin();
    //SSD1351_mono_bitmap(0, 0, mono_bmp, 128, 128, GREEN);

while(1){
    pFile = fopen("infrared", "r");

   if (pFile == NULL) {
        printf("file does not exist\n");
        return 0;
    }

    //for (int i = 0; i < OLED_WIDTH * OLED_HEIGHT * 3; i++){
    //    bmpBuffer[i] = 127;
    //}

    //fseek(pFile, 54, 0);
    fread(bmpBuffer, pixelSize, OLED_WIDTH * OLED_HEIGHT, pFile);
    fclose(pFile);

    SSD1351_bitmap24(0, 0, bmpBuffer, 128, 128);
    SSD1351_display();
    bcm2835_delay(20);
}
    SSD1351_clear();
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

