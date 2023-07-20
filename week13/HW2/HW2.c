// 키 암호로 암호화 - 파일 입출력
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
			encodedSentence[i] = sentence[i];
	}
	return;
}

int main(void)
{
	int d;            // 거리 설정
	char code[26];
	char key[30] = { 0 };
	char sentence[80] = { 0 }, encodedSentence[80] = {0};
	FILE* fp1 = NULL, * fp2 = NULL;

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
	printf("-------------------------------------------------------\n\n");

	getchar();

	fp1 = fopen("in.txt", "rt");
	fp2 = fopen("out.txt", "wt");
	if (!fp1 || !fp2) return 0;

	while (fgets(sentence, sizeof(sentence), fp1) != NULL) {
		encode(code, sentence, encodedSentence);
		fputs(encodedSentence, fp2);
		memset(encodedSentence, '\0', sizeof(encodedSentence));  // 문자열 버퍼 비우기
	}

	printf("입력파일:in.txt\n");
	printf("출력파일:out.txt\n");

	fclose(fp1);
	fclose(fp2);
	return 0;
}