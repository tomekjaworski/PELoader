// simple_io.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char text[100];
	printf("Podaj jakis tekst: ");
	fgets(text, sizeof(text), stdin);

	const char* chars_of_intrest = "AEIOUY";
	int* bins = (int*)calloc(strlen(chars_of_intrest), sizeof(int));
	if (bins == NULL) {
		printf("Brak pamieci (?)\n");
		return 1;
	}

	for (const char* ptext = text; *ptext != '\x0'; ++ptext) {
		int ch = toupper(*ptext);
		const char* pch = strchr(chars_of_intrest, ch);
		if (pch == NULL)
			continue;
		int idx = pch - chars_of_intrest;
		++bins[idx];
	}

	for (int i = 0; i < strlen(chars_of_intrest); ++i)
		printf("[%5c] ", chars_of_intrest[i]);
	printf("\n");
	for (int i = 0; i < strlen(chars_of_intrest); ++i)
		printf("[%5d] ", bins[i]);
	printf("\n");
	free(bins);
	return 0;
}
