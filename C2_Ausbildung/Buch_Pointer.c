/**
* buch3.c
*
* Dieses Programm benutzt Zeiger, um Strukturen an
* Funktionen zu übergeben._
*
**/
#include <stdio.h> /* für printf() und scanf() */
#include <stdlib.h> /* für exit() */
#define MAX_BUCH 10 /* maximale Anzahl der Bücher */
/* --- Deklatation des Datentyps BUCH --- */
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
typedef struct /* Deklaration des Datentyps BUCH */
{
	char autor[31];
	char titel[41];
	short ver_jahr;
	float preis;
} BUCH;

/* --- Funktions-Prototypen --- */
void neueingang_pointer(BUCH* buchzeiger);
void ausgabe_pointer(BUCH* buchzeiger, int anzahl);
void zeige_menue1(void);
int lese_aktion1(void);
/* --------------------------------------------------------------- */
void buch3_main()
{
	int aktion;
	int aktuell = 0; /* enthält Index der aktuellen */
	/* Struktur des Arrays biblio */
	
	BUCH biblio[MAX_BUCH]; /* Definition eines Arrays aus */
	
						   /* Strukturen vom Typ BUCH */
	do
	{
		zeige_menue1(); /* Menü anzeigen */
		aktion = lese_aktion1(); /* Auswahl einlesen */
		switch (aktion) /* Auswahl auswerten */
		{
		case 1: if (aktuell < MAX_BUCH)
			neueingang_pointer(&biblio[aktuell++]);
			  else
		{
			printf("Die maximale Anzahl der ");
			printf("Bücher ist erreicht.\n");
		}
			  break;
		case 2: /* Adresse des ersten Elementes übergeben */
			ausgabe_pointer(&biblio[0], aktuell);
			break;
		case 3: exit(0);
		default: printf("Ungültiger Menüpunkt.\n");
		} /* end of switch */
	} while (aktion != 3); /* end of while */
}
/* --------------------------------------------------------------- */
void neueingang_pointer(BUCH* buchzeiger)
{
	printf("\nAutor: "); /* Autor einlesen */
	fseek(stdin, 0, SEEK_END);
	fgets(buchzeiger->autor,31,stdin);
	
	printf("Titel: "); /* Titel einlesen */
	fseek(stdin, 0, SEEK_END);
	fgets(buchzeiger->titel,41,stdin);
	
	printf("Erscheinungsjahr: "); /* Erscheinungsjahr einlesen */
	fseek(stdin, 0, SEEK_END);
    //fgets((int)&buchzeiger->ver_jahr,4,stdin);
	scanf("%d", &buchzeiger->ver_jahr);
	
	
	printf("Preis: "); /* last not least den Preis */
    fseek(stdin, 0, SEEK_END);
	//fgets(&buchzeiger->preis, 4, stdin);
	scanf("%f", &buchzeiger->preis);
	
	fflush(stdin); /* Eingabepuffer löschen */
}
/* --------------------------------------------------------------- */
void ausgabe_pointer(BUCH* buchzeiger, int anzahl)
{
	int zaehler;
	for (zaehler = 0; zaehler < anzahl; zaehler++, buchzeiger++)
		printf("%s: %s, %4d, öS %.2f\n",
			buchzeiger->autor,
			buchzeiger->titel,
			buchzeiger->ver_jahr,
			buchzeiger->preis);
}
/* --------------------------------------------------------------- */
int lese_aktion1(void)
{
	fseek(stdin, 0, SEEK_END);
	int aktion;
	printf("Bitte waehlen Sie einen Menuepunkt: ");
	scanf("%d", &aktion);
	fflush(stdin);
	return(aktion);
}
/* --------------------------------------------------------------- */
void zeige_menue1(void) /* Menü anzeigen */
{
	printf("\n\t1\t\tBuch eingeben\n");
	printf("\t2\t\tBuch ausgeben\n");
	printf("\n\t3\t\tEnde\n");
}