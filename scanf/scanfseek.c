#include<stdio.h>
#pragma warning(disable:4996);
void main() {
	char bs1, bs2, bs3;
	printf("Gib was ein: \n");
	fseek(stdin, 0, SEEK_END);
	scanf("%c", &bs1);
	printf("Gib was ein: \n");
	fseek(stdin, 0, SEEK_END);
	scanf(" %c", &bs2);
	printf("Gib was ein: \n");
	fseek(stdin, 0, SEEK_END);
	scanf("%c", &bs3);

}