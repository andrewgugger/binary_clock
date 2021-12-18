#include "display.h"
int main(void){
	pi_framebuffer_t *fb=getFrameBuffer();
	display_colons(fb);
	int hours, minutes, seconds;
	while(1){
		printf("does it take?");
		scanf("%d:%d:%d", &hours, &minutes, &seconds);
		printf("it does take");
		printf("\n%d:%d:%d", hours, minutes, seconds);
		if(1<=hours && hours<=24 && 0<=minutes && minutes<=59 && 0<=seconds && seconds<=59){
			display_time(hours, minutes, seconds, fb);
		}
		else{
			clear(fb);
			break;
		}
	}
}
