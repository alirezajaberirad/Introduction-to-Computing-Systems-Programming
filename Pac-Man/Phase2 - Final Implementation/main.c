#include "header.h"

int main() {
	initScreen();
	int L = 1;//i use L for if statement that is used inside of while function in easy setting
	int i, j;//in the rest of the code you'll see these two variables,these are just for preventing the computer from not showing the bagel if in hard setting first bagel is in (0,0)cell and in medium setting if after eating 29 bagels the next bagel is in the previous location of packman 
	int arr[COLUMN_PER_TABLE][ROWS_PER_TABLE] = { 0 };//this array is for the bagels
	char d = 'r';//I could make the game start whenever the gamer wants by adding getch() but i decided to start the game after choosing the hardness with pacman's mouth in right direction
	int x = 0, y = 0;//both of them are equal to 0 because pacman starts moving from (0,0) cell
	int m, n, counter = 0,hardness;//m is like x and n is like y,you'll see its usage in switch case function
	printf("Select the hardness of the game\n\t1)easy\n\t2)medium\n\t3)hard");//easy setting is a table with structure of bagels that you wanted from us,in hard setting computer sets the next location of bagel by random,medium is a combine of easy and hard setting:it first runs with easy and after eating all bagels,the hard setting would be enabled
	scanf("%d", &hardness);
	srand(time(NULL));
	int table[COLUMN_PER_TABLE+1][ROWS_PER_TABLE+1][2] = { 0 };//go to if statement of the showtable function to see why i made the array equal to 0//
	table[0][0][0] = 1;//in table[][][]=1 I'm choosing the lines that are used for drawing the table that you wanted from me//
	table[1][0][0] = 1;
	table[2][0][0] = 1;
	table[3][0][0] = 1;
	table[4][0][0] = 1;
	table[5][0][0] = 1;

	table[0][0][1] = 1;
	table[0][1][1] = 1;
	table[0][2][1] = 1;
	table[0][3][1] = 1;
	table[0][4][1] = 1;

	table[6][0][1] = 1;
	table[6][1][1] = 1;
	table[6][2][1] = 1;
	table[6][3][1] = 1;
	table[6][4][1] = 1;

	table[0][5][0] = 1;
	table[1][5][0] = 1;
	table[2][5][0] = 1;
	table[3][5][0] = 1;
	table[4][5][0] = 1;
	table[5][5][0] = 1;
	gotoxy(COLUMN_PER_TABLE * 2* CELL_WIDTH, ROWS_PER_TABLE * CELL_WIDTH);//I saw an empty field in my table and then I decided to add these two lines of code to solve it//
	printf("%c", 219);

	table[4][0][1] = 1;
	table[4][1][0] = 1;
	table[5][1][1] = 1;

	table[0][3][0] = 1;
	table[1][3][1] = 1;
	table[1][4][0] = 1;

	table[5][4][1] = 1;
	table[4][4][0] = 1;
	table[4][3][1] = 1;
	table[3][2][1] = 1;
	table[2][1][1] = 1;
	table[3][3][0] = 1;
	table[2][2][0] = 1;

	switch (hardness) {
	case 1://easy
		showtable(table);
		for (m = 0;m <COLUMN_PER_TABLE;m++) {
			for (n = 0;n <ROWS_PER_TABLE;n++) {
				if(m!=0 || n!=0)//when the game starts packman is in (0,0) cell so I added this if statement to prevent the game from starting with score=1!
				arr[m][n]=1;
		}
	}
		showbagel(arr);
		gotoxy(COLUMN_PER_TABLE * 2* CELL_WIDTH + 2, 2* CELL_WIDTH+2);
		printf("to exit the game press Alt+F4");
		while (L) {//each time it first clears the previous cell that pacman have been in it and then it sets the next location and shows pacman
			clearCell(x, y);
			setNextLocation(&x, &y, d);
			drawPacman(x, y, 0, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 120, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 0, d);
			if (arr[x][y] == 1) {//it'll check wheter there is a bagel in the cell that pacman is in it or not. arr[][]=1 means that there is a bagel in the cell and arr[][]=0 means that there is no bagel in that cell
				counter++;
				arr[x][y] = 0;
			}
			gotoxy(COLUMN_PER_TABLE * 2* CELL_WIDTH + 2, 2* CELL_WIDTH);
			printf("score: %d", counter);//it shows the score
			if (counter == 29) {//it check whether the game is finished or not
				gotoxy(COLUMN_PER_TABLE * 2 * CELL_WIDTH + 2, 2 * CELL_WIDTH + 4);
				printf("***YOU FINISHED THE GAME SUCCESSFULLY!***");
				L = 0;//this will make the if statement that is inside of the while function incorrect and will jump out of the while function
			}
		}
		getch();
		break;
	case 2://medium
		showtable(table);
		for (m = 0;m <COLUMN_PER_TABLE;m++) {
			for (n = 0;n <ROWS_PER_TABLE;n++) {
				if (m != 0 || n != 0)//when the game starts packman is in (0,0) cell so I added this if statement to prevent the game from starting with score=1!
					arr[m][n] = 1;
			}
		}
		showbagel(arr);
		gotoxy(COLUMN_PER_TABLE * 2* CELL_WIDTH + 2, 2* CELL_WIDTH+2);
		printf("to exit the game press Alt+F4");
		while (1) {
			clearCell(x, y);
			setNextLocation(&x, &y, d);
			drawPacman(x, y, 0, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 120, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 0, d);
			if (arr[x][y] == 1) {
				counter++;
				arr[x][y] = 0;
			}
			gotoxy(COLUMN_PER_TABLE * 2* CELL_WIDTH + 2, 2* CELL_WIDTH);
			printf("score: %d", counter);
			if (counter == (COLUMN_PER_TABLE*ROWS_PER_TABLE-1))
				break;
		}
		i = rand() % COLUMN_PER_TABLE;
		j = rand() % ROWS_PER_TABLE;
		m = i;
		n = j;
		arr[i][j] = 1;
		showbagel(arr);
		while (1) {
			if(i!=x || j!=y)//in random it may shows the first bagel in cell(0,0) and without this if statement,clearcell will clear cell(0,0) in the begining and would not show the first bagel
			clearCell(x, y);
			setNextLocation(&x, &y, d);
			drawPacman(x, y, 0, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 120, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 0, d);
			if (m == x && n == y) {//here the computer is checking whether pacman and the bagel are in the same cell and if its true it sets the new area of bagel//
				counter++;
				arr[m][n] = 0;
				m = rand() % COLUMN_PER_TABLE;
				n = rand() % ROWS_PER_TABLE;
				arr[m][n] = 1;
				showbagel(arr);
			}
			gotoxy(COLUMN_PER_TABLE * 2*CELL_WIDTH + 2, 2*CELL_WIDTH);//here I selected a location to show the score
			printf("score: %d", counter);
			i = COLUMN_PER_TABLE + 4;
			j = ROWS_PER_TABLE + 4;
		}
		break;
	case 3://hard
		showtable(table);
		i = rand() % COLUMN_PER_TABLE;
		j = rand() % ROWS_PER_TABLE;
		m = i;
		n = j;
		clearCell(0, 0);
		arr[i][j] = 1;
		showbagel(arr);
		gotoxy(COLUMN_PER_TABLE * 2*CELL_WIDTH + 2, 2*CELL_WIDTH+2);//here I selected a location to tell the gamer how he/she can exit from the game 
		printf("to exit the game press Alt+F4");
		while (1) {
			if(i!=0 || j!=0)
			clearCell(x, y);
			setNextLocation(&x, &y, d);
			drawPacman(x, y, 0, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 120, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 90, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 60, d);
			waitAndGetDirection(DELAYTIME, &d);
			drawPacman(x, y, 0, d);
			if (m == x && n == y) {//here the computer is checking whether pacman and the bagel are in the same cell and if its true it sets the new area of bagel//
				counter++;
				arr[m][n] = 0;
				m = rand() % COLUMN_PER_TABLE;
				n = rand() % ROWS_PER_TABLE;
				arr[m][n] = 1;
				showbagel(arr);
				
			}
			gotoxy(COLUMN_PER_TABLE * 2*CELL_WIDTH + 2, 2*CELL_WIDTH);//here I selected a location to show the score
			printf("score: %d", counter);
			i = 1;
			j = 1;
		}
		break;
	default: 
		clearCell(0, 0);
		gotoxy(0, 0);
		printf("You entered invalid character.Please close the app and try again.\n");
	}
}