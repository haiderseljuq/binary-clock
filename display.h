#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ncurses.h"

int open_display(void);
void display_time(int,int,int);
void display_column(int value,int col,uint16_t color);
void display_colons(void);
void display_hours(int);
void display_minutes(int);
void display_seconds(int);
void display_sigma(void);
void close_display(void);

