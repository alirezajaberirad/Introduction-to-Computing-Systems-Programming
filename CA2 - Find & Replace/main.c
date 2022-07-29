//Alireza JaberiRad   810196438
#include "Header.h"
int main() {
	FILE*fpointer;
	char name[50];
	char *word=NULL,*newword=NULL;
	char *compare = NULL;
	char singlecharbefore[1],singlecharafter[1];
	char *storingarr = NULL;
	int *oldwordlocation=(int *)malloc(sizeof(int));
	int counter;
	int choice;
	int charnums,charnumsnew;
	int txtlength;
	int check = 1;
	int i ,j,k,m;
	word = (char*)realloc(word, 50 * sizeof(char));
	newword= (char*)realloc(newword, 50 * sizeof(char));
	printf("*****WELCOME TO FIND AND REPLACE PROGRAM!*****\n");
	while (check) {
		printf("What do you want to do?\n1)Find a word\n2)Replace a word\n0)Exit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			i = 0;
			counter = 0;
			printf("Enter the file name : ");
			scanf("%s", name);
			if (!fopen(name, "r")) {//here if statement check the return value of fopen function and you know if it was not equal to 0 that means opening the file was not successful and doesn't exist any file with that name 
				printf("File not found!\n");
				break;
			}
			printf("Enter the word : ");
			scanf("%s", word);
			charnums = howmanychars(word);
			word = (char*)realloc(word, charnums * sizeof(char));
			word[charnums] = NULL;
			compare = (char*)realloc(compare, charnums * sizeof(char));
			compare[charnums] = NULL;
			fpointer = fopen(name, "r");
			txtlength = textlength(fpointer);//here computer counts the characters of the text
			fseek(fpointer, 0, SEEK_SET);
			while (!feof(fpointer)) {
				fseek(fpointer, i, SEEK_SET);
				fread(compare, sizeof(char), charnums, fpointer);//this function gets extra \n when sees \n,the problem is not from my code,the function has problem!
				if (!strcmp(compare, word)) {
					fseek(fpointer, i - 1, SEEK_SET);
					fread(singlecharbefore, sizeof(char), 1, fpointer);
					fseek(fpointer, i + charnums, SEEK_SET);
					fread(singlecharafter, sizeof(char), 1, fpointer);
					if ((i == 0 && (singlecharafter[0] == NULL || singlecharafter[0] == 32 || singlecharafter[0] == 9 || singlecharafter[0] == 10)) || (i == (txtlength - charnums-1 )) &&
						(singlecharbefore[0] == NULL || singlecharbefore[0] == 32 || singlecharbefore[0] == 10 || singlecharbefore[0] == 9)) {//because it doesn't exist any (space before the first/after the last character) of the text,I used this if statement to count the first/last string if it is the word that we are searching for,also if (after the first string /before the last string) exist any alphabetical characters,that string shouldn't be counted
						counter++;
					}
					else {
						
						if ((singlecharbefore[0] == NULL || singlecharbefore[0] == 32 || singlecharbefore[0] == 10 ||
							singlecharbefore[0] == 9) && (singlecharafter[0] == NULL || singlecharafter[0] == 32 ||
								singlecharafter[0] == 9 || singlecharafter[0] == 10 )) {//in the text if there is a null or \t or \n or space, before and after the string,then we can count that string
							counter++;
						}
					}
				}
				i++;
				if (i + charnums-1 == txtlength)//i added this line because it coused problem without it,i don't know the reason:( 
					break;
			}
			printf("There were %d -%s- in the text\n", counter, word);
			fclose(fpointer);
			break;

		case 2:
			i = 0;
			counter = 0;
			printf("Enter the file name : ");
			scanf("%s", name);
			if (!fopen(name, "r")) {
				printf("File not found!\n");
				break;
			}
			printf("Enter the word : ");
			scanf("%s", word);
			printf("Enter the new word : ");
			scanf("%s", newword);
			charnums = howmanychars(word);
			charnumsnew = howmanychars(newword);
			word = (char*)realloc(word, charnums * sizeof(char));//i wanted the array to be fit to the size of the word that the user input
			word[charnums] = NULL;
			newword = (char*)realloc(newword, charnumsnew * sizeof(char));//i wanted the array to be fit to the size of the new word that the user input
			newword[charnumsnew] = NULL;
			compare = (char*)realloc(compare, charnums * sizeof(char));//i wanted the array to be fit to the size of the word that the user input
			compare[charnums] = NULL;
			fpointer = fopen(name, "r");
			txtlength = textlength(fpointer);//here computer counts the characters of the text
			fseek(fpointer, 0, SEEK_SET);
			while (!feof(fpointer)) {
				fseek(fpointer, i, SEEK_SET);
				fread(compare, sizeof(char), charnums, fpointer);//this function gets extra \n when sees \n,the problem is not from my code,the function has problem!
				if (!strcmp(compare, word)) {
					fseek(fpointer, i - 1, SEEK_SET);
					fread(singlecharbefore, sizeof(char), 1, fpointer);
					fseek(fpointer, i + charnums, SEEK_SET);
					fread(singlecharafter, sizeof(char), 1, fpointer);
					if ((i == 0 && (singlecharafter[0] == NULL || singlecharafter[0] == 32 || singlecharafter[0] == 9 || singlecharafter[0] == 10)) || (i == (txtlength - charnums - 1)) &&
						(singlecharbefore[0] == NULL || singlecharbefore[0] == 32 || singlecharbefore[0] == 10 || singlecharbefore[0] == 9)) {//because it doesn't exist any (space before the first/after the last character) of the text,I used this if statement to count the first/last string if it is the word that we are searching for,also if (after the first string /before the last string) exist any alphabetical characters,that string shouldn't be counted
						oldwordlocation[counter] = i;
						oldwordlocation = (int*)realloc(oldwordlocation, (counter + 2) * sizeof(int));
						counter++;
					}
					else {

						if ((singlecharbefore[0] == NULL || singlecharbefore[0] == 32 || singlecharbefore[0] == 10 ||
							singlecharbefore[0] == 9) && (singlecharafter[0] == NULL || singlecharafter[0] == 32 ||
								singlecharafter[0] == 9 || singlecharafter[0] == 10)) {//in the text if there is a null or \t or \n or space, before and after the string,then we can count that string
							oldwordlocation[counter] = i;
							oldwordlocation = (int*)realloc(oldwordlocation, (counter + 2) * sizeof(int));
							counter++;
						}
					}
				}
				i++;
				if (i + charnums - 1 == txtlength)//i added this line because it coused problem without it,i don't know the reason:( 
					break;
			}
			oldwordlocation[counter] = txtlength;//because in the for function that you see below,if i dont this line it would not go to the end of the previous file and reading characters finish when it replaces the last old word
			fclose(fpointer);
			i = 0;
			m = 0;
			fpointer = fopen(name, "r");
			storingarr = (char*)realloc(storingarr, (txtlength + (charnumsnew - charnums)*counter) * sizeof(char));//computer realloc the size of storingarrey into the size of the new text
			for (j = 0;j <= counter;j++) {
				while (i < oldwordlocation[j] ) {
					fseek(fpointer, i, SEEK_SET);
					fread(storingarr + m, sizeof(char), 1, fpointer);
					i++;
					m++;
				}
				for (k = 0;k < charnumsnew;k++)
					storingarr[m + k] = newword[k];
				i += charnums;
				m += charnumsnew;
			}
			storingarr[m] = NULL;
			fclose(fpointer);
			fpointer = fopen(name, "w");
			fseek(fpointer, 0, SEEK_SET);
			fwrite(storingarr, sizeof(char), txtlength + (charnumsnew - charnums)*counter-1, fpointer);//this will write the new text in a new text file with same name that had before,its kind of replacing new text file with the old one
			time_t currentTime;
			time(&currentTime);
			fprintf(fpointer, "\n\n*****At %s the word %s was replaced with %s.*****", ctime(&currentTime), word, newword);
			printf("done!\n");
			fclose(fpointer);
			break;

		case 0:
			check = 0;
			break;

		default:
			printf("You entered an invalid number!");
		}
		word = (char*)realloc(word, 50 * sizeof(char));//this will set the capacity of the word to the previous size
		newword = (char*)realloc(newword, 50 * sizeof(char));//this will set the capacity of the newword to the previous size
	}
}