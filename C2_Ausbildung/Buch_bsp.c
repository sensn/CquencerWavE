/**
* buch1.c
*
* Dieses Programm demonstriert die �bergabe von
* Strukturen an Funktionen.
*
**/

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> /* f�r printf() und scanf() */
typedef struct /* Deklaration des Datentyps BUCH */
{
	char autor[31];
	char titel[41];
	short ver_jahr;
	float preis;
} BUCH;
/*--- Funktionsprototypen ---*/
void ausgabe(BUCH);
BUCH neueingang(); /* Deklaration der Funktion neueingang()*/

/* --------------------------------------------------------------- */
void buch_main()
{
	BUCH eins; /* Definiton der Strukturvariablen eins */
	BUCH zwei; /* Definiton der Strukturvariablen zwei */

	eins = neueingang(); /* Daten f�r das erste Buch einlesen */
	zwei = neueingang(); /* Daten f�r das zweite Buch einlesen */

	ausgabe(eins); /* Daten f�r das erste Buch ausgeben */    //CALL BY VALUE!
	ausgabe(zwei); /* Daten f�r das zweite Buch ausgeben */	  //CALL BY VALUE!	
}
/* --------------------------------------------------------------- */
BUCH neueingang()
{
	BUCH neu; /* neue Struktur des Typs BUCH */

	printf("\nAutor: "); /* Autor einlesen */
	fseek(stdin, 0, SEEK_END);
	fgets(neu.autor,31,stdin);
	
	printf("Titel: "); /* Titel einlesen */
	fseek(stdin, 0, SEEK_END);
	fgets(neu.titel,2,stdin);

	printf("Erscheinungsjahr: "); /* Erscheinungsjahr einlesen */
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &neu.ver_jahr);

	printf("Preis: "); /* last not least den Preis */
	fseek(stdin, 0, SEEK_END);
	scanf("%f", &neu.preis);
	
	fflush(stdin); /* Eingabepuffer l�schen */
	return(neu); /* Struktur zur�ckgeben */
}
/* --------------------------------------------------------------- */
void ausgabe(BUCH nummer)
{
	printf("\nAutor: %s\n", nummer.autor);
	printf("Titel: %s\n", nummer.titel);
	printf("veroeffentlicht in: %4d\n", nummer.ver_jahr);
	printf("Preis: S %.2f\n", nummer.preis);
}
