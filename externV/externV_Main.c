#include <stdio.h> // Prototyp f�r printf()


void ausgabe_1(void);	/* Prototyp der Funktion ausgabe_1() */

extern int exint;			/* Diese Anweisung macht die Variable */
						/* x f�r die main() Funktion sichtbar */

static int y = 100; /* Die Variable "y" soll nur in dieser */
/* Datei sichtbar sein */