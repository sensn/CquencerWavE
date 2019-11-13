#include "HeaderC2.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)



extern int exint;
static int y = 100;   //static y gilt nur für diese eine Datei

void myfunc() {
	//printf("Hello\n");

	//int z = digit_input();
	//printf("Eingegebene Zahl%i", digit_input());
	//printf("Recursive_Add: %lu", recursive_add((getche()-48)));

	//output_exV_1();


	//output_sphereV();

	//loopdelta();    // float to int in for loop
	//tohex_test();

	// array14();

	//printf("sizeof(size_t)= %u\n", sizeof(size_t));

	//char str[80] = { 0 };
	//str[0] = 'a';
	//printf("%c", str[0]);
	
	//testchar("qwerqwertzqwerqwertzqwerqwertzqwerqwertzqwerqwertzqwerqwertzqwerqw");

	//gleicheZeichen();
	
	wortraten();

}

int digit_input(void){
	int ziffer;							//Ziffer einlesen
	printf("\nGeben Sie bitte eine Ziffer ein: ");
	do
	{
		if (isdigit(ziffer = getche())) /* Zeichen einlesen und überprüfen */
			;
		else
			printf("Keine Ziffer!\n"); /* Warnton ausgeben */
	} while (!isdigit(ziffer)); /* bis eine Ziffer eingegeben wurde */
	return(ziffer - 48); /* Übergabe der Zahl */
}

unsigned long recursive_add(int n){
	unsigned long summe;
	if (n == 0) /*Abbrechen der Rekursion wenn n == 0 */
		return(0);
	summe = n + recursive_add(n - 1); /* Hier ist der rekursive Aufruf!! */
	return(summe); /* Übergabe des Ergebnisses */
}

void output_exV_1(void)
{
	printf("Die Funktion ausgabe_1() meldet: ");
	printf(" x = %d, y = %d \n\n", exint, y);
}

void output_sphereV() {
	
	for (int i = 0; i <= 20; i += 1)												 // 0 bis 4 in 0.2 schritten
		printf("Kugelvolumen : %.3f\t %.2f\n", sphere_volume((float)i/5),(float)i/5);

}

float sphere_volume(float radius) {
	//double Pi = 3.14159;
	//printf("%f", M_PI);

	// 4 * Pi * Radius3 / 3 

	float volume;
	//volume = (4 / 3) * M_PI * pow(radius, 3);
	volume = 4  * PI  * pow(radius, 3) /3 ;

	return volume;
}

void loopdelta() {
	double tMin=0.0;
	double tMax=4.0;
	double deltaT=0.2;

	double time;

	/// https://stackoverflow.com/questions/16595668/any-risk-of-using-float-variables-as-loop-counters-and-their-fractional-incremen
	//***  WRONG
	for (time = tMin; time <= tMax; time += deltaT) {
		// Use the time variable in the loop
		printf("TIME : %.3f\n", time);
	}


	//***  RIGHT   USE INT IN LOOP calculate needed float in Loop.
	
	int nTimes = (tMax - tMin) / deltaT + 1;
		for (int i = 0; i < nTimes; i++) {
			time = tMin + i * deltaT;
			printf("TIME AACC : %.3f\n", time);
		}
		// NOW use a more accurate time variable
		// Or alternatively if you know the minimum, maximum, and number of desired iterations:
		
		//double deltaT = (tMax - tMin) / (nTimes - 1);
		//for (int i = 0; i < nTimes; i++) {
		//	time = tMin + i * deltaT;
		//	printf("TIME ACC1: %.3f\n", time);
		//	// NOW use a more accurate time variable
		//}
		
}

void tohex_test() {
	
		unsigned int eingabe = 0;
		int test;
		printf("\nGeben Sie bitte eine Dezimalzahl,\n");
		printf("oder eine \"0\" zum Beenden, ein:\n ");
		do
		{
			printf("\nIhre Dezimalzahl: ");
			if (test = scanf("%4i", &eingabe)); /* Zahl einlesen */
			printf("Hex-Darstellung: %s\n", /* Umwandeln und ausgeben */
				tohex(eingabe));
		} while (test && eingabe); /* Solange einlesen, bis Zahl */
		/* zwischen 0 und 255 eingegeben wurde */
	}


	char* tohex(unsigned int dez) /* Die Funktion wandelt eine */
	/* vorzeichenlose Dezimalzahl in */
	/* eine vierstellige Hexzahl um */
	{
		static char hex[] = "0123456789ABCDEF";
		static char hex_string[] = "0000"; /* nimmt die Hexzahl auf */
		int i;
		for (i = 3; i >= 0; i--, dez >>= 4)
			hex_string[i] = hex[dez & 0x000F]; /* Bit 0..3 stehenlassen */
		return(hex_string);
	}


	void array14() {
		
		long long unsigned max = pow(2, NUMBITS) - 1;
		long long unsigned zahl = 255;
		int mybin[NUMBITS] = { 0 };

		

		
		for (int i = 0; i <= NUMBITS -1; i++) {
			mybin[i] = zahl % 2;
			zahl /= 2;
			
			if (!zahl)
			//	mybin[i] = 0;
			break;

		}

		for (int i = NUMBITS -1; i >= 0; i--) {
			printf("%d", mybin[i]);
		}




	}


	//Bsp.17

	void testchar(char mychararr[]) {

		//char mychararr[80];
		//mychararr = thechar;
		
		int result;

		int alphabet = 0, number = 0;

		for (size_t i = 0; mychararr[i] != '\0'; i++)
		{
			// check for alphabets 
			if (isalpha(mychararr[i]))
				alphabet++;

			// check for decimal digits 
			else if (isdigit(mychararr[i]))
				number++;
		}

		printf("Alphabetic_letters = %d, "
			"Decimal_digits = %d\n", alphabet, number);



		// *** Length Variante***///

		int length = strlen(mychararr);
		for (int i = 0; i <= length-1; i++) {
			result = (isalpha) ? 1 : 0;
		} //do something with result..


		// *** ASCII -Variante***///   Schaut ob des Buchstom san.
		
		for (int i = 0; i <= length-1; i++) {
			if ((mychararr[i] >= 65 && mychararr[i] <= 90) || (mychararr[i] >= 97 && mychararr[i] <= 122)) {
				printf("Des is a Buchstom: %d. num:%d \n", mychararr[i],i);
			}
			else {
				printf("Des san net nur Buchstom: %d  %d. \n",mychararr[i],i);
			}
		}



	}

	void gleicheZeichen() {
		char string[] = "AKSJDUEHFTYF";
		char spanset[] = "ADEFFHJKSTUY";
		size_t cnt = 0;
		// Such-Zeiger auf den Beginn von string setzen
		char* ptr = string;

		//// naechste Ziffer suchen
		//ptr = strpbrk(ptr, spanset);

		//printf("Ziffer gefunden: %c\n", *ptr);

		//// Such-Zeiger weiterruecken
		//ptr++;

		//// naechste Ziffer suchen
		//ptr = strpbrk(ptr, spanset);

		//printf("Ziffer gefunden: %c\n", *ptr);

		for (size_t i = 0; string[i] != '\0'; i++)
		{
			ptr = strpbrk(ptr, spanset);
	
			if (ptr == NULL){
				printf("ISNULL\n");
			break;
			}
			else {
				printf("Zeichen gefunden: %c\n", *ptr);
				ptr++;
				cnt++;
			}
			
		} //for

		printf("%s ZEICHEN enthalten", (cnt == strlen(string)) ? "Alle" : "NICHT alle");
	}

	void wortraten() {

		//char wantedWord[15] = { '\0' };
		char wantedWord[15] = "hello";
		char token;
		int tries = 15;
		char workArr[15] = {'\0'};


		for (size_t i = 0; wantedWord[i] != '\0'; i++)
		{
			workArr[i] = '_';
			printf("%c", '_');
		}
		
		
		
		printf("\n");
		int right = strlen(wantedWord);
		
		while (tries>0 && right>0)  {
			
			token = getche();

			tries--;
			//printf("TT %d", tries);
			system("cls");
			printf("Versuche %d - Richtig:%d\n\n\t", tries, -right+1);

			for (size_t i = 0; wantedWord[i] != '\0'; i++)
			{
				if (wantedWord[i] == token) {


					if (workArr[i] != token) {    // richtiger buchstaben schon mal eingegeben?
						
						workArr[i] = token;
						//printf("%c", token);
						right--;
						//printf("RICHTIG:%d", right);
					}
				}
				
				printf("%c", workArr[i]);
				
				if (right == 0) {
					//printf("break");
					break;
				}
				
			}
			

		} //while
		printf("\n\nEND - Versuche : %d ",tries);
	}//endfunc


