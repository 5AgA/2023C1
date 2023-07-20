// 시저 암호로 암호화
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void makeCode(char* code, int d)
{
	for (int i = 0; i < 26; i++) {
		int alpha = 'A' + i + d;
		if (alpha <= 90)
			code[i] = alpha;
		else
			code[i] = alpha - 26;
	}
	return;
}

void printCode(char* code)
{
	for (int i = 0; i < 26; i++) 
		printf("%c", code[i]);
	printf("\n");
	return;
}

void encode(char* code, char* sentence, char* encodedSentence)
{
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90)
			encodedSentence[i] = code[sentence[i] - 65];
		else
			encodedSentence[i] = 32;
	}
	return;
}

int main(void)
{
	int d;            // 거리 설정
	char code[26];
	char sentence[80], encodedSentence[80] = { 0 };

	printf("Enter a distance for encoding:");
	scanf("%d", &d);

	printf("------------------------------------------------------\n");
	makeCode(code, d);
	printf("alphabet:\t\tABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	printf("encoded:\t\t");
	printCode(code);
	printf("-------------------------------------------------------\n");

	getchar();
	printf("\n\nEnter a sentence to encode:");
	gets_s(sentence, sizeof(sentence));
	printf("original sentence:\t");
	puts(sentence);

	encode(code, sentence, encodedSentence);
	printf("encoded sentence:\t");
	puts(encodedSentence);

	return 0;
}