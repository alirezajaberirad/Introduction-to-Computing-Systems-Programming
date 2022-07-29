#include "header.h"

void initScreen()
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int waitAndGetDirection(int waitTime, char *direction)
{
	DWORD start_time, check_time;

	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}
	}

	switch (ch)
	{
	case 'w':
		ch = 'u';
		break;
	case 'z':
		ch = 'd';
		break;
	case 'a':
		ch = 'l';
		break;
	case 's':
		ch = 'r';
		break;
	default:
		break;
	}

	if (ch != *direction && (ch == 'u' || ch == 'd' || ch == 'l' || ch == 'r'))
	{
		*direction = ch;
		return 1;
	}
	else
		return 0;

}
void showtable(int table[COLUMN_PER_TABLE+1][ROWS_PER_TABLE+1][2]) {
	int i, j;
	char k;
	int column, row,direction;
	for (column = 0;column <= COLUMN_PER_TABLE;column++) {
		for (row = 0;row <= ROWS_PER_TABLE;row++) {
			for (direction = 0;direction <= 1;direction++) {
				if(table[column][row][direction]==1){
					if (direction == 1) {
						k = 219;//I found this char on the asciitable.com//
						for (i = 0;i <CELL_WIDTH;i++) {
							gotoxy(column * 2* CELL_WIDTH, row * CELL_WIDTH + i);
							printf("%c%c", k, k);
						}
					}
					if (direction == 0) {
						k = 219;
						for (i = 0;i <(2* CELL_WIDTH);i++) {
							gotoxy(column * 2* CELL_WIDTH + i, row * CELL_WIDTH);
							printf("%c", k);
						}
					}
				}
			}
		}
	}
	
}

void clearCell(int x, int y) {
	int i,j;
	for (i = 1;i <CELL_WIDTH;i++) {//start from 1 and end when j is equal to cellwidth-1 will prevent from clearing the walls(its why i didnt start from 0 to cellwidth because 1 characters is for the wall
		for (j = 2;j <(2* CELL_WIDTH-1);j++) {//start from 2 and end when j is equal to 2*cellwidth-2 will prevent from clearing the walls(its why i didnt start from 0 to 2*cellwidth because 2 characters are for the walls
			gotoxy(x * 2* CELL_WIDTH + j, y * CELL_WIDTH + i);
			printf(" ");
		}
	}
}
void drawPacman(int dx, int dy, float degree, char direction) {//I used my code that created in CA1-P1// 
	gotoxy((dx * 2* CELL_WIDTH)+2, (dy * CELL_WIDTH));
	int i, j,r=6,k=1;
	if (degree == 60)//in this and three if statement below,the code is converting the degree into the degree of the pacman's mouth that make with x axis in left or right position//
		degree = (PI / 6);
	else if (degree == 90)
		degree = PI / 4;
	else if (degree == 120)
		degree = (PI / 3);
	if (degree == 0) {//because it doesn't matter what direction is in the case that degree=0,I put this "if" in my code,just in order to solving the problem of degree=0  over direction up and down!,because if I didn't use this if statement ,in up and down direction the computer wouldn't show one column of"#"//
		for (i = -r;i <= r;i++) {
			for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
				if (i*i + j*j / 4 <= r*r / 4)
					printf("#");
				else  if (i != -r && j != -2 * r) printf(" ");
			}
			gotoxy((dx * 2* CELL_WIDTH)+2, (dy * CELL_WIDTH)+k);
			k++;//k is for going to the next line,i used this instead of puts()
		}
	}
	else {
		switch (direction) {//switch case starts from here depending on the kind of the direction//
		case 'u':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan((PI / 2 - degree))*j >= 0 || 2 * i + tan((PI / 2 - degree))*j >= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else if (i != -r && j != -2 * r) printf(" ");
				}
				gotoxy((dx * 2* CELL_WIDTH) + 2, (dy * CELL_WIDTH) + k);
				k++;//k is for going to the next line,i used this instead of puts()
			}
			break;
		case 'd':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan((PI / 2 - degree))*j <= 0 || 2 * i + tan((PI / 2 - degree))*j <= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else if (i != -r && j != -2 * r) printf(" ");
				}
				gotoxy((dx * 2* CELL_WIDTH) + 2, (dy * CELL_WIDTH) + k);
				k++;//k is for going to the next line,i used this instead of puts()
			}
			break;
		case 'l':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan(degree)*j <= 0 || 2 * i + tan(degree)*j >= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else if (i != -r && j != -2 * r) printf(" ");
				}
				gotoxy((dx * 2* CELL_WIDTH) + 2, (dy * CELL_WIDTH) + k);
				k++;//k is for going to the next line,i used this instead of puts()
			}
			break;
		case 'r':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan(degree)*j >= 0 || 2 * i + tan(degree)*j <= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else if(i!=-r && j!=-2*r) printf(" ");
				}
				gotoxy((dx * 2* CELL_WIDTH)+2, (dy * CELL_WIDTH) + k);
				k++;//k is for going to the next line,i used this instead of puts()
			}
			break;
		default: printf("The direction that you entered is invalid!\n");//I entered this code just in order to show a notice that the user can understand that he/she entered an invalid direction//
		}
	}
}//drawing function finishes here
void setNextLocation(int *x, int *y, char direction) {
	switch (direction) {//In these if statements that you see below,I'm preventing the pacman from crossing the walls//
	case 'u':
		if((*x!=0 || *y!=0)&&(*x != 1 || *y != 0) && (*x != 2 || *y != 0) && (*x != 3 || *y != 0) && (*x != 4 || *y != 0) && (*x != 5 || *y != 0) && (*x != 4 || *y != 1) && (*x != 0 || *y != 3) && (*x != 1 || *y != 4) && (*x != 2 || *y != 2) && (*x != 3 || *y != 3) && (*x != 4 || *y != 4))
			*y -= 1;
		break;
	case 'd':
		if((*x != 4 || *y != 0) && (*x != 2 || *y != 1) && (*x != 3 || *y != 2) && (*x != 4 || *y != 3) && (*x != 0 || *y != 2) && (*x != 1 || *y != 3) && (*x != 0 || *y != 4) && (*x != 1 || *y != 4) && (*x != 2 || *y != 4) && (*x != 3 || *y != 4) && (*x != 4 || *y != 4) && (*x != 5 || *y != 4))
		*y += 1;
		break;
	case 'l':
		if((*x != 0 || *y != 0) && (*x != 0 || *y != 1) && (*x != 0 || *y != 2) && (*x != 0 || *y != 3) && (*x != 0 || *y != 4) && (*x != 1 || *y != 3) && (*x != 2 || *y != 1) && (*x != 3 || *y != 2) && (*x != 4 || *y != 3) && (*x != 5 || *y != 4) && (*x != 4 || *y != 0) && (*x != 5 || *y != 1))
		*x -= 1;
		break;
	case 'r':
		if((*x != 0 || *y != 3) && (*x != 1 || *y != 1) && (*x != 2 || *y != 2) && (*x != 3 || *y != 3) && (*x != 4 || *y != 4) && (*x != 3 || *y != 0) && (*x != 5 || *y != 0) && (*x != 5 || *y != 1) && (*x != 5 || *y != 2) && (*x != 5 || *y != 3) && (*x != 5 || *y != 4) && (*x != 4 || *y != 1))
		*x += 1;
		break;
	}
}
void showbagel(int arr[COLUMN_PER_TABLE][ROWS_PER_TABLE]){
	int column, row;
	int r = 2;
	int i, j,k=1;
	for (column = 0;column < COLUMN_PER_TABLE;column++) {
		for (row = 0;row < ROWS_PER_TABLE;row++) {

			if (arr[column][row] == 1) {
				gotoxy(column * 2*CELL_WIDTH+ 8, row * CELL_WIDTH + 4);
				for (i = -r;i <= r;i++) {//here i copied the code that i had written for pacman in case that it's mouth degree is equal to 0
					for (j = -2 * r;j <= 2 * r;j++) {
						if (i*i + j*j / 4 <= r*r / 4)
							printf("#");
						else  if (i != -r && j != -2 * r) printf(" ");
					}
					gotoxy((column * 2* CELL_WIDTH + 8) + 2, (row * CELL_WIDTH + 4) + k);
					k++;//k is for going to the next line,i used this instead of puts()
				}
			}
			k = 1;
		}
	}
}