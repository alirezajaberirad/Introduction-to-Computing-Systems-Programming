#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int i, j, r, num = 0;
	float degree;
	char direction;
	printf("**welcome to the PACMAN project\n**");
	while (num != 3) {//this while statement is using in order to give the user the to use the app until whenever he/she wants//
		printf("Enter a num to choose one of the given items:\n");
		printf("1.Drawing pacman.\n2.Making table.\n3.Exit!:(\n");
		scanf_s("%d", &num);
		switch (num) {
		case 1://here is for drawing pacman//
			printf("enter the radius: ");
			scanf_s("%d", &r);
			printf("enter the direction(u,d,l,r): ");
			scanf_s(" %c", &direction);
			printf_s("enter pacman's mouth degree(0,60,90,120): ");
			scanf_s("%f", &degree);
			drawing(r, direction, degree);
			break;
		case 2://here is for drawing table//
			int rows, columns, length;
			printf("in this part you can make your table!\n");
			printf("enter the length of each box of the table : ");
			scanf_s("%d", &length);
			printf("enter number of rows that you want : ");
			scanf_s("%d", &rows);
			printf("enter number of columns that you want : ");
			scanf_s("%d", &columns);
			table(length, columns, rows);
			break;
		case 3: printf_s("It'll be a long day without you my friend,I'll compile my code for you when I see you again.\nIt took a long time from where we began,and I'll tell you all about it when I see you again.\nwhen I see you agaaaaaaaaaaaaaaaaaaaaaaaaaaiiiiiiiiiiiiiiiiiinnn:(\nBYE:(....\n ");
			break;//this case is the trajic part of the program ;)//
		default: printf("you entered invalid number\n");
		}
	}
}