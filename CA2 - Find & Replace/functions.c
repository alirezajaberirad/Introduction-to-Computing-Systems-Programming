//Alireza JaberiRad   810196438
#include"Header.h"


int howmanychars(char word[50]) {
	int i = 0;
	while (word[i] != NULL) {
		i++;
	}
	i;
	return i;
}

int textlength(FILE*text) {
	int i=0;
	char a[1];
	while (!feof(text)) {
		fread(a, sizeof(char), 1, text);
		i++;
	}
	return i;
}