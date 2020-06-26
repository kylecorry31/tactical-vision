all: off oled
off:off.o ssd1351.o
	gcc -Wall -o off off.o ssd1351.o -lbcm2835
oled:oled.o ssd1351.o
	gcc -Wall -o oled oled.o ssd1351.o -lbcm2835
ssd1351.o:ssd1351.c ssd1351.h
	gcc -Wall -c ssd1351.c -lbcm2835
oled.o:oled.c ssd1351.h
	gcc -Wall -c oled.c -lbcm2835
off.o:off.c ssd1351.h
	gcc -Wall -c off.c -lbcm2835
clean:
	rm ssd1351.o oled.o off.o oled off
