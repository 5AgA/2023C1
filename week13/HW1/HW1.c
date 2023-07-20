// 키 암호로 암호화
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_duplicated_char(char* word)
{
	int i, j, k;
	for (i = 0; i < strlen(word); i++) 
		for (j = i + 1; j < strlen(word); j++)
			if (word[i] == word[j]) {
				for (k = j; k < strlen(word); k++)
					word[k] = word[k + 1];
				word[k] = "\0";
			}
	return;
}

void makeCode(char* code, int d, char* key)
{
	int isIn, i, j, k = 0;
	char a;
	for (i = 0; i < 26; i++) {
		a = i + 'A'; isIn = 0;
		for (j = 0; j < strlen(key); j++)
			if (key[j] == a) {
				isIn = 1;
				break;
			}
		
		if (isIn == 1)
			code[(d + j) % 26] = a;
		else
			code[(d + j + k++) % 26] = a;
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
	char key[30] = { 0 };
	char sentence[80], encodedSentence[80] = { 0 };

	printf("Enter a word to use for encoding(대문자로 된 단어 입력):");
	scanf("%s", key);
	remove_duplicated_char(key);
	printf("Enter a distance for encoding:");
	scanf("%d", &d);

	printf("------------------------------------------------------\n");
	makeCode(code, d, key);
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