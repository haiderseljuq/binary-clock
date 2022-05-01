#include "display.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
   int hours;
   int minutes;
   int seconds;

   open_display();
   display_colons();

   while(scanf("%i:%i:%i",&hours,&minutes,&seconds)){
	if(hours <=24,minutes <=59,seconds <=59){
		display_time(hours,minutes,seconds);
		}
	}
   close_display();
   return 0;
}

