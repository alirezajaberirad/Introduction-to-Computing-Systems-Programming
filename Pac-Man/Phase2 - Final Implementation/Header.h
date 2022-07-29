#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<time.h>

#define ROWS_PER_TABLE 5
#define COLUMN_PER_TABLE 6
#define CELL_WIDTH 14
#define PI 3.14159
#define DELAYTIME 130
//Sets console screen to full screen
//Use this function at the beginning of your program in main()
void initScreen();
//The following function manipulates cursor position
void gotoxy(int x, int y);
//This function will wait for "waitTime" milliseconds and get the new direction from the keybord
//100<waitTime<250 
//Use this function between printing the pacman shapes in a single cell
//If the direction is changed the return value is 1 else the return value is 0
int waitAndGetDirection(int waitTime, char *direction);

void drawPacman(int dx, int dy, float degree, char direction);
void clearCell(int x, int y);
void setNextLocation(int *x, int *y, char direction);
void showbagel(int arr[COLUMN_PER_TABLE][ROWS_PER_TABLE]);
void showtable(int table[COLUMN_PER_TABLE + 1][ROWS_PER_TABLE + 1][2]);

