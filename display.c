#include "display.h"
#define WHITE 0xFFFF
#define BLUE 0x00FF
#define GREEN 0x7E0
#define RED 0xF800
#define BLACK 0x0000
void display_time(int hours, int minutes, int seconds, pi_framebuffer_t *dev){
	pi_framebuffer_t *fb=getFrameBuffer();
	display_hours(hours, fb);
	display_minutes(minutes, fb);
	display_seconds(seconds, fb);
}

void display_colons(pi_framebuffer_t *dev){
	sense_fb_bitmap_t *bm=dev->bitmap;
	//bottom left
	bm->pixel[1][4]=WHITE;
	bm->pixel[1][5]=WHITE;
	bm->pixel[2][4]=WHITE;
	bm->pixel[2][5]=WHITE;
	//top left
	bm->pixel[5][4]=WHITE;
	bm->pixel[5][5]=WHITE;
	bm->pixel[4][4]=WHITE;
	bm->pixel[4][5]=WHITE;
	//top right
	bm->pixel[5][2]=WHITE;
	bm->pixel[5][1]=WHITE;
	bm->pixel[4][2]=WHITE;
	bm->pixel[4][1]=WHITE;
	
	//bottom right
	bm->pixel[1][2]=WHITE;
	bm->pixel[1][1]=WHITE;
	bm->pixel[2][2]=WHITE;
	bm->pixel[2][1]=WHITE;
}

void display_hours(int hours, pi_framebuffer_t *dev){
	printf("hour startty");
	sense_fb_bitmap_t *bm=dev->bitmap;
	//clear hours pixels:
	int g = 0;
	while(g<7){
		bm->pixel[g][6]=BLACK;
		g++;
	}

	//convert to binary
	int bin[7],n,i;
	n = hours;
	for(i=0;n>0;i++){
		bin[i]=n%2;
		n = n/2;
	}
	
	//column is always 6 so 0,6 1,6
	int p = 0;
	for(i = i-1;0<=i;i--){
		if(bin[i]==1){
			bm->pixel[p][6]=BLUE;
		}
		p++;
	}
	printf("hours complete");
}

void display_minutes(int minutes, pi_framebuffer_t *dev){
	printf("minute srat");
	sense_fb_bitmap_t *bm=dev->bitmap;
	//clear minutes pixels:
	int g = 0;
	while(g<7){
		bm->pixel[g][3]=BLACK;
		g++;
	}

	//convert to binary
	int bin[7],n,i;
	n = minutes;
	for(i=0;n>0;i++){
		bin[i]=n%2;
		//printf("%d",bin[i]);
		n = n/2;
	}
	
	//column is always 3 so 0,3 1,3
	int p = 0;
	for(i = i-1;0<=i;i--){
		if(bin[i]==1){
			bm->pixel[p][3]=GREEN;
		}
		p++;
	}
	printf("minutes complete");
}

void display_seconds(int seconds, pi_framebuffer_t *dev){
	printf("seconds start");
	sense_fb_bitmap_t *bm=dev->bitmap;
	//clear minutes pixels:
	int g = 0;
	while(g<7){
		bm->pixel[g][0]=BLACK;
		g++;
	}

	//convert to binary
	int bin[7],n,i;
	n = seconds;
	for(i=0;n>0;i++){
		bin[i]=n%2;
		printf("%d",bin[i]);
		n = n/2;
	}
	
	//column is always 0 so 0,0 1,0
	int p = 0;
	for(i = i-1;0<=i;i--){
		if(bin[i]==1){
			bm->pixel[p][0]=GREEN;
		}
		p++;
	}
	printf("seconds complete");
}

void clear(pi_framebuffer_t *dev){
	pi_framebuffer_t *fb=getFrameBuffer();
	clearFrameBuffer(fb,BLACK);
}
