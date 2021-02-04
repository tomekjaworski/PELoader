// locales.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <cassert>

WORD input_codes[65536];
WORD types_c1[65536], types_c2[65536], types_c3[65536];
WORD upper_codes[65536];
WORD lower_codes[65536];

int main()
{
	BOOL b;
	int res;
	FILE* f;
	for (int i = 0; i < 65536; i++)
		input_codes[i] = i;

	b = GetStringTypeW(CT_CTYPE1, (LPCWCH)input_codes, 65536, types_c1);
	b = GetStringTypeW(CT_CTYPE2, (LPCWCH)input_codes, 65536, types_c2);
	b = GetStringTypeW(CT_CTYPE3, (LPCWCH)input_codes, 65536, types_c3);

	const wchar_t* wtext = L"Ala mą kota";
	res = LCMapStringW(NULL, LCMAP_UPPERCASE, wtext, 4, (LPWCH)lower_codes, 100);
	res = LCMapStringW(NULL, LCMAP_LOWERCASE, (LPCWCH)input_codes, 65536, (LPWCH)lower_codes, 0);


	res = LCMapStringW(NULL, LCMAP_UPPERCASE, (LPCWCH)input_codes, 65536, (LPWCH)upper_codes, 65536);
	res = LCMapStringW(NULL, LCMAP_LOWERCASE, (LPCWCH)input_codes, 65536, (LPWCH)lower_codes, 65536);

	f = fopen("conv1.txt", "wt");
	for (int i = 0; i < 65536; i++)
		fprintf(f, "        { 0x%04x, 0x%04x, 0x%04x, 0x%04x } /* %c */,\n", i, types_c1[i], types_c2[i], types_c3[i], i == 0 ? 32 : i);
	fclose(f);

	f = fopen("conv_upper_lower.txt", "wt");
	for (int i = 0; i < 65536; i++)
		fprintf(f, "        { 0x%04x, 0x%04x, 0x%04x } /* %c %c */,\n", i, upper_codes[i], lower_codes[i], i == 0 ? 32 : i, (upper_codes[i] == lower_codes[i] && upper_codes[i] == i) ? ' ' : '*');
	fclose(f);


	{
		BYTE* pbPair;
		UINT    ich;
		UCHAR   sbVector[256];
		for (ich = 0; ich < 256; ich++)
			sbVector[ich] = (UCHAR)ich;
		sbVector[0] = (UCHAR)' ';
		
		int cp = 1250;
		CPINFO cpInfo;
		GetCPInfo(cp, &cpInfo);
		
		for (pbPair = &cpInfo.LeadByte[0]; *pbPair; pbPair += 2)
			// make sure ich within a valid range
			for (ich = *pbPair; ich <= *(pbPair + 1) && ich < 256; ich++)
				sbVector[ich] = (UCHAR)' ';

		int extent = MultiByteToWideChar(cp, MB_PRECOMPOSED, (LPCCH)sbVector, 256, NULL, 0);
		LPWSTR pp = (LPWSTR)malloc(extent * sizeof(char16_t));
		MultiByteToWideChar(1252, MB_PRECOMPOSED, (LPCCH)sbVector, 256, (LPWSTR)pp, extent);

		char fname[100];
		snprintf(fname, sizeof(fname), "conv_ansi_to_ucs%d.txt", cp);
		FILE* f = fopen(fname, "w");
		for (int i = 0; i < extent; i++) {
			fprintf(f, "        {0x%02x, 0x%04x},\n", sbVector[i], pp[i]);
		}
		fclose(f);
		free(pp);

		// i w drugą
		BOOL default_char_used = FALSE;
		extent = WideCharToMultiByte(cp, 0, (LPCWCH)input_codes, 65536, NULL, 0, NULL, &default_char_used);
		short* buffer = (short*)malloc(extent * sizeof(short));
		for (int i = 0; i < extent; i++) {
			default_char_used = FALSE;
			char output;
			int extent2 = WideCharToMultiByte(cp, 0, (LPCWCH)input_codes + i, 1, &output, 1, NULL, &default_char_used);
			assert(1 == extent2);

			if (default_char_used)
				buffer[i] = -1;
			else
				buffer[i] = (short)output & 0x00FF;
		}

		snprintf(fname, sizeof(fname), "conv_ucs%d_to_ansi.txt", cp);
		f = fopen(fname, "w");
		for (int i = 0; i < extent; i++) {
			if (buffer[i] == -1)
				fprintf(f, "        {0x%04x, -1},   /* invalid */\n", input_codes[i]);
			else
				fprintf(f, "        {0x%04x, 0x%02x}, /* -> '%c' */\n", input_codes[i], (char)buffer[i] & 0xFF, (int)buffer[i] & 0xFF);
		}
		fclose(f);
		free(buffer);

	}



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
