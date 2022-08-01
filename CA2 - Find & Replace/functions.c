#include"Header.h"


int howmanychars(char word[50]) {//this function will count the number of the characters in word given to the program by user
	int i = 0;
	while (word[i] != NULL) {
		i++;
	}
	i;
	return i;
}

int textlength(FILE*text) {//this function will count the number of characters in the text file
	int i=0;
	char a[1];
	while (!feof(text)) {
		fread(a, sizeof(char), 1, text);
		i++;
	}
	return i;
}