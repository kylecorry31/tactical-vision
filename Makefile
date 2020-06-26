oled:oled.o ssd1351.o
	gcc -Wall -o oled oled.o ssd1351.o -lbcm2835
ssd1351.o:ssd1351.c ssd1351.h
	gcc -Wall -c ssd1351.c -lbcm2835
oled.o:oled.c ssd1351.h 
	gcc -Wall -c oled.c -lbcm2835
clean:
	rm ssd1351.o oled.o oled
