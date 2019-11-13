//Eingabe& Ausgabe funktionieren, 1

/* Arbeitsauftrag */

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 35
#define X_COUNT 3
#define Y_COUNT 3
struct dat
{
	int posX;
	int posY;
	char playerChr;

	char name[MAX];
	
	struct date {
		int day;
		int month;
		int year;
	}date;
	

} ;

int aa_struct(int argc, char** argv)
{
	int posX;
	int posY;
	int eingabe = 4;  //4 for tictac toe

	

	int xs = X_COUNT +1;
	int ys = Y_COUNT +1;

	struct dat lib[X_COUNT+1][Y_COUNT+1] = { '\0' };
	
	char player[2] = { 'X','O' };
	int p = 2;
//	pintf("PLAYER : %c", player[0]);
	
	do
	{
		system("cls");  // Clean the screen!
						//Print the Rastaman!
		
		for (size_t x = 1; x < xs; x++) {
			printf(" _");
		}
		puts("");
		for (size_t x = 1; x < xs; x++) {
			for (size_t y = 1; y < ys; y++) {
				printf("|");
				
				printf("%c", ((lib[x][y].posX >0 && lib[x][y].posY >0) && (x == lib[x][y].posX && y == lib[x][y].posY)) ? lib[x][y].playerChr :'_');
				//printf("%s", ((lib[x][y].posX >0 && lib[x][y].posY >0) && (x == lib[x][y].posX && y == lib[x][y].posY)) ? "T" :"_" );
				if (y == ys-1)
					printf("|");
			}
			puts("");
		}



		//***GEWINNABFRAGE
		for (size_t i = 1; i < 4; i++) {
			if ((lib[i][1].playerChr != NULL && lib[i][1].playerChr == lib[i][2].playerChr && lib[i][1].playerChr == lib[i][3].playerChr) || (lib[1][i].playerChr != NULL && lib[1][i].playerChr == lib[2][i].playerChr && lib[1][i].playerChr == lib[3][i].playerChr) || (lib[1][1].playerChr != NULL && lib[1][1].playerChr == lib[2][2].playerChr && lib[1][1].playerChr == lib[3][3].playerChr) || (lib[1][3].playerChr != NULL && lib[1][3].playerChr == lib[2][2].playerChr && lib[1][3].playerChr == lib[3][1].playerChr)) {
				printf("Player %d WON!",((p+1)%2+1));
				exit(0);
 			}
		}
		//********


		/*printf_s("\n(1)Save Data, (2)Browse Data, ,(3)Delete Entry (0)Exit\n> ");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &eingabe);*/

		

		switch (eingabe)
		{
		case 0: printf_s("\nGoodbye!\n\n"); break;
		case 1: {


			printf_s("Save to... \nX: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posX);

			printf_s("Y: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posY);

			//if (lib[posX][posY].playerChr == NULL) {
			lib[posX][posY].posX = posX;
			lib[posX][posY].posY = posY;
			lib[posX][posY].playerChr = player[0];
			//	lib[posX][posY].playerChr = player[p % 2];
				//p++;
				//} // if not NULL

			printf_s("\nName: ");
			fseek(stdin, 0, SEEK_END);
			fgets(lib[posX][posY].name, MAX, stdin);
			printf_s("Date (dd.mm.yyyy): ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%2d.%2d.%4d", &lib[posX][posY].date.day, &lib[posX][posY].date.month, &lib[posX][posY].date.year);


		}
			break;
		case 2: {
			printf_s("Open from... \nX: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posX);

			printf_s("Y: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posY);

			printf_s("\nData at[%d][%d]:\t%s", posX, posY, lib[posX][posY].name);
			//printf_s("\nDEBUG_LIB_Data Lib[%d][%d]:\t%s", lib[posX][posY].posX, lib[posX][posY].posY, lib[posX][posY].name);
			printf_s("\t\t\t\t%2d.%2d.%4d\n", lib[posX][posY].date.day, lib[posX][posY].date.month, lib[posX][posY].date.year);
			break;
		}
		case 3: {
			printf_s("Delete Entry... \nX: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posX);


			printf_s("Y: ");

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posY);

			str_init(lib[posX][posY].name);
			//lib[posX][posY].date.day = 0;
			lib[posX][posY].posX = 0;
			lib[posX][posY].posY = 0;

			break;
		}
		case 4: {
			printf_s("Player %d\nX: ",(p%2)+1);

			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posX);

			printf_s("Y: ");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &posY);

			if (lib[posX][posY].playerChr == NULL) {
				lib[posX][posY].posX = posX;
				lib[posX][posY].posY = posY;

				lib[posX][posY].playerChr = player[p % 2];
				p++;
			} // if not NULL
			break;
		}
		default: printf_s("Falsche Eingabe!\n"); break;
		} //switch
		
	} while (eingabe != 0);
	return 0;
}
