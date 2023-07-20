// 암호화 - 입출력 파일
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
			encodedSentence[i] = sentence[i];
	}
	return;
}

int main(void)
{
	int d;            // 거리 설정
	char code[26];
	char sentence[80] = {0}, encodedSentence[80] = {0};
	FILE* fp1 = NULL, * fp2 = NULL;

	printf("Enter a distance for encoding:");
	scanf("%d", &d);

	printf("------------------------------------------------------\n");
	makeCode(code, d);
	printf("alphabet:\t\tABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	printf("encoded:\t\t");
	printCode(code);
	printf("-------------------------------------------------------\n");

	getchar();
	
	fp1 = fopen("original.txt", "rt");
	fp2 = fopen("encoded.txt", "wt");
	if (!fp1 || !fp2) return 0;

	while (fgets(sentence, sizeof(sentence), fp1) != NULL) {
		encode(code, sentence, encodedSentence);
		fputs(encodedSentence, fp2);
		memset(encodedSentence, '\0', sizeof(encodedSentence));  // 문자열 버퍼 비우기
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}