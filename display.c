#include "display.h"
#include "ncurses.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WHITE 1
#define GREEN 2
#define RED 3
#define BLACK 4
#define BLUE 5


int open_display(void){
	//opens display
	initscr();
	start_color();
	init_pair(WHITE,COLOR_WHITE,COLOR_WHITE);
	init_pair(GREEN,COLOR_GREEN,COLOR_GREEN);
	init_pair(RED,COLOR_RED,COLOR_RED);
	init_pair(BLACK,COLOR_BLACK,COLOR_BLACK);
	init_pair(BLUE,COLOR_BLUE,COLOR_BLUE);
	if(initscr()){return 1;}
	else{return 0;}
}


void display_colons(void){
	//white colons
	attron(COLOR_PAIR(WHITE));
	for (int x =1;x <5;x +=3){
		for(int y =1; y <5; y +=3){
			mvaddch(x,y,'#');
			mvaddch(x+1,y,'#');
			mvaddch(x,y+1,'#');
			mvaddch(x+1,y+1,'#');
		}
	}
refresh();
}

void display_column(int value,int col, uint16_t color){
	for (int y = 0; y < 6; y++){
		if (value % 2){
			attron(COLOR_PAIR(color));
			mvaddch(y,col,'#');
		}
		else{
			attron(COLOR_PAIR(BLACK));
			mvaddch(y,col,'#');
		}
		value = value / 2;
	}
}

void display_hours(int hours){
	display_column(hours,0,BLUE);
}

void display_minutes(int minutes){
	display_column(minutes,3,GREEN);
}

void display_seconds(int seconds){
	display_column(seconds,6,RED);
}

void display_time(int hours,int minutes,int seconds){
	display_hours(hours);
	display_minutes(minutes);
	display_seconds(seconds);

	refresh();
}


void close_display(void) {
    endwin();
}

