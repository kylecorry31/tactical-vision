#include <bcm2835.h>
#include <stdio.h>
#include <time.h>
#include "ssd1351.h"

int main(int argc, char **argv)
{
    FILE *pFile;
    char* filename;
    size_t pixelSize = 3;
    unsigned char bmpBuffer[OLED_WIDTH * OLED_HEIGHT * 3];

    if (argc == 2){
        filename = argv[1];
    } else {
        filename = "infrared";
    }

    if(!bcm2835_init())
    {
        return -1;
    }

    SSD1351_begin();

    while(1){
        pFile = fopen(filename, "r");

        if (pFile == NULL) {
            printf("file does not exist\n");
            return 0;
        }

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

