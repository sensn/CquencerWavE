#include <stdio.h> // Prototyp für printf()


void ausgabe_1(void);	/* Prototyp der Funktion ausgabe_1() */

extern int exint;			/* Diese Anweisung macht die Variable */
						/* x für die main() Funktion sichtbar */

static int y = 100; /* Die Variable "y" soll nur in dieser */
/* Datei sichtbar sein */