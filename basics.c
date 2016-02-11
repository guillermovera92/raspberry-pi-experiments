#include <stdlib.h>
#include <stdio.h>
#include "imgproc.h"

// compile: gcc -std=c99 -o basics basics.c -limgproc
// usage: ./basics path/to/img.bmp
// example: ./basics smallSails.bmp

int main(int argc, char *argv[]) {
	init_imgproc();
	Viewer *view = viewOpen(200, 200, "Sails");
	Image *img = imgFromBitmap(argv[1]);
	
	for (int x = 0; x < img -> width; x++) {
		for (int y = 0; y < img -> height; y++) {
			char * pixel = imgGetPixel(img, x, y);
			char red = pixel[2];
			char green = pixel[1];
			char blue = pixel[0];
			
			if (red > green && red > blue) {
				imgSetPixel(img, x, y, 255, 0, 0);
			} else if (green > red && green > blue) {
				imgSetPixel(img, x, y, 0, 255, 0);
			} else {
				imgSetPixel(img, x, y, 0, 0, 255);
		
			}
		}
	}

	viewDisplayImage(view, img);
	waitTime(5000); 
	imgDestroy(img);
	viewClose(view);
	quit_imgproc();
	return 0;
}
