// simple_file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(int argc, const char** argv)
{
	//
	// Test fopen - brak pliku
	FILE* fnone = fopen("no_such_file", "rb");
	assert(fnone == NULL);

	//
	// Test zapisu
	FILE* f1 = fopen("1.txt", "wt");
	assert(f1 != NULL);
	fprintf(f1, "Content [%s]\n", argv[0]);
	fclose(f1);

	//
	// test wczytywania
	FILE* f2 = fopen("1.txt", "rt");
	assert(f2 != NULL);
	
	char temp1[1024];
	char* pc_result = fgets(temp1, sizeof(temp1), f2);
	fclose(f2);
	assert(pc_result == temp1);

	char temp2[1024];
	snprintf(temp2, sizeof(temp2), "Content [%s]\n", argv[0]);
	int iresult = strcmp(temp1, temp2);
	assert(iresult == 0);

	//
	// Test dodawania (append)
	_unlink("values.txt");
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		FILE* f3 = fopen("values.txt", "at");
		assert(f3 != NULL);
		fprintf(f3, "%d\n", i);
		fclose(f3);
		sum += i;
	}

	FILE* f4 = fopen("values.txt", "rt");
	assert(f4 != NULL);

	for (int i = 0; i < 10; i++) {
		int value;
		iresult = fscanf(f4, "%d", &value);
		assert(iresult == 1);
		sum -= value;
	}
	fclose(f4);
	assert(sum == 0);

	//
	// Koniec
	printf("Ok.\n");
}

