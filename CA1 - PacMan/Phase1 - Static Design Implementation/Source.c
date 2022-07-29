#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
void drawing(int r, char direction, float degree) {//this fuction will draw the pacman depending on the user inputs//
	int i, j;
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
				else printf(" ");
			}
			puts("");
		}
	}
	else {
		switch (direction) {//switch case starts from here depending on the kind of the direction//
		case 'u':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan((PI / 2 - degree))*j >= 0 || 2 * i + tan((PI / 2 - degree))*j >= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else printf(" ");
				}
				puts("");
			}
			break;
		case 'd':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan((PI / 2 - degree))*j <= 0 || 2 * i + tan((PI / 2 - degree))*j <= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else printf(" ");
				}
				puts("");
			}
			break;
		case 'l':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan(degree)*j <= 0 || 2 * i + tan(degree)*j >= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else printf(" ");
				}
				puts("");
			}
			break;
		case 'r':
			for (i = -r;i <= r;i++) {
				for (j = -2 * r;j <= 2 * r;j++) {//2*is for making the pacman like a circle//
					if (i*i + j*j / 4 <= r*r / 4 && (2 * i - tan(degree)*j >= 0 || 2 * i + tan(degree)*j <= 0))//I added mathematical functions that are used in descart coordinate//
						printf("#");
					else printf(" ");
				}
				puts("");
			}
			break;
		default: printf("The direction that you entered is invalid!\n");//I entered this code just in order to show a notice that the user can understand that he/she entered an invalid direction//
		}
	}
}//drawing function finishes here
void table(int length, int columns, int rows) {//in this function computer draws for you a table that you like!//
	int i, j;
	length++;//I added  +1 to "length" because one character uses for partitioning the table//
	for (i = 1;i <= rows*length + 1;i++) {
		for (j = 1;j <= 2 * columns*length + 1;j++) {//I added 2* to columns*length because the length of the characters that are in a row are 1/2 length of the characters that are in one column, +1 is for the last line of the column//
			if (i%length == 1) {//here we partition the rows//
				printf("-");
				if (j > (2 * columns*length - columns))//if I don't add this if statement the compiler will print "-" more than we need,as much as the number that entered for "columns",this would happen because of two reason:first because of length++ and then because of 2* in 2*length*columns+1 in for statement that is above//
					break;
			}
			else if (j % (2 * length - 1) == 1)//here we partition the columns//
				printf("|");
			else printf(" ");//here is used for inside of each box//
		}
		puts("");
	}
}
