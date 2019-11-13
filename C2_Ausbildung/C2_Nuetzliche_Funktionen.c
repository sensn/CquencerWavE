#include "HeaderC2.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void mymain() {
	//printf("hello");
	

	call_str_func();   //Compare 2 Strings
	
	


} //endfunc
   //***

void SetPosition(int X, int Y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { X, Y };

	SetConsoleCursorPosition(Screen, Position);
}

//*****


#pragma region Compare Strings 

int call_str_func() {
	char str1[100] = "ReVeRSe";
	//char str1[100] = "aa";
	char str2[100] = "String2";
	char str3[MAX_SIZE]="AddToMe-";             // str3  declared but not initialized
	char str4[MAX_SIZE];                // str3  declared but not initialized
	_Bool result;
	//char result;
	size_t result1;

	char tchar = 146;
	//printf("%d", sizeof(long long));

	//result = str_comp(str1, str2);
	//printf("Die Beiden Arrays sind %s\n\n", (result) ? "GLEICH" : "UNGLEICH");
	//
	//result1 = str_length(str1);
	//printf("Arrayslength %u\n\n",result1);

	//result = str_copy(str1, str2);
	//printf("Die Beiden Arrays wurden %s kopiert \n\n", (result) ? "NICHT" : "ERFOLGREICH");
	
	//str_reverse(str1);
	//str_case(str1,1);
	
	//printf("%c => %d", tchar, char_type(tchar));    // Typ von char ermitteln
	
	//printf("%.2lf",power(-4,-3));				// Potenz berechnen base^expo
	
	//printf("%d",str_init(str3));              //  Init char array \0
	
	//str_fill(str3);                     //füllen und ausgeben.
	//***
	//str_add(str3, "HOHOHO");                  //text anfügen

	//str_output(str1);
 //   str_removeSpaces(str1);						//Leerzeichen entfernen
	//puts("");

	//printf("SUMME der CHARs : %d\n",str_sum(str1));                         //Summe der CHars

	//printf("Anzahl des gesuchten CHARs : %d\n", str_findchr(str1,'!'));     //Anzahl eines gusuchten chars
	//str_prepend(str1, str2);

	//printf("Anzahl der geloeschten Zeichen: %d\n",str_delchr(str1, 'e'));             //Zeichen löschen
	
	str_sort(str1,0,2);                    // sort string (ascii-val) str[], int mode: 0=up, 1=down  sorting_algo: 1 bubbleSort, 2: insertionSortRecursive ....
	str_output(str1);
	//str_output(str3);
	//***
	return 0;
}//endfunc

///**
void str_output(char str[]) {
	/*for (size_t i = 0; str[i] != '\0'; i++) {
		printf("%c", str[i]);
	}
	puts("");*/
	printf("%s", str);
}
///**


_Bool str_comp(char str1[],char str2[]) {
	
	 size_t count = 0;
	 size_t z = 0;

		for (size_t i = 0; str1[i] != '\0'; i++, z++)
		{
			//for (size_t j = 0; str2[j] != '\0'; j++)
			//{
				if (str1[i] == str2[i])
				{
					count++;
					//break;
				}
			//}
		}
		////ausgabe
		//for (size_t i = 0; str1[i] != '\0'; i++)
		//{
		//	printf_s("%c", str1[i]);
		//}
		//printf("\n");
		//for (size_t j = 0; str2[j] != '\0'; j++)
		//{
		//	printf_s("%c", str2[j]);
		//}
		////ausgabe Ende

		if (z == count){
			//printf("\tenthalten die gleichen Zeichen\n");
			return 1;
		}
		else{
			return 0;
			//printf("\tenthalten nicht die gleichen Zeichen\n");
		}

}

size_t str_length(char str1[]) {
	size_t count = 0;

	for (size_t i = 0; str1[i] != '\0'; i++,count++)
	{
		}
	return count;
}

_Bool str_copy(char str1[], char str2[]) {
	//for (size_t i = 0; str1[i] != '\0'; i++) {

	for (size_t i = 0; i < str_length(str1); i++) {
		str2[i] = str1[i];
	}
	return 0;
}

_Bool str_reverse(char str[]) {
	
	char tmp;
	//printf("%d", str_length(str));

	//for (size_t i = 0; str1[i] != '\0'; i++) {

	for (size_t i = 0 ; i < str_length(str)/2; i++) {
		 tmp= str[str_length(str)-i-1];
		 str[str_length(str)-i-1] = str[i];
		 str[i] = tmp;		
	}
	
	
	return 0;
}

_Bool str_case(char str[], _Bool toCase ) {
	if (toCase) {
		for (int i = 0; i < str_length(str); i++) {
			str[i] = toupper(str[i]);
		}
    }
	else {
		for (int i = 0; i < str_length(str); i++) {
			str[i] = tolower(str[i]);
		}

	}


}

char char_type(char thechar) {
	char thetype = 0;

	if ((thechar >= 0 && thechar <= 32) || thechar == 127) {
		thetype = 0;
 	} // Steuerzeichen
	 else if (thechar >= 32 && thechar < 127) {
		thetype = 1; //printable
		if ((thechar >= 33 && thechar < 48) || (thechar >= 58 && thechar < 65) || (thechar >= 91 && thechar < 97) || (thechar >= 123 && thechar < 127) || thechar == 96) {
			thetype = 2; //puntation
		}
		else if (thechar >= 48 && thechar < 58) {
			thetype = 3; //digit
		}
		else if (thechar >= 65 && thechar < 91) {
			thetype = 4; //upperCase
		}
		else if (thechar >= 97 && thechar < 123) {
			thetype = 5; //lowerCase
		}
   	 }

	else if (thechar+256 >= 128 && thechar+256 < 256) {
		thetype = 5; // specialCase
	}

	return thetype;
}

double power( long long base, char expo) {
	//printf("base %lf")
	 double result= 1;

	if (expo==0) {
		result = 1;
		return result;
	}
	else {
		if (expo > 0) {
			for (int i = 0; i < expo; i++) {
				result *= base;
				//printf("%d", i);
			}
			return result;
		}
		else if (expo < 0) {
			//printf("%d", -expo);
			for (int i = 0; i < -(expo); i++) {
				result *= base;
				//printf("%d", i);
			}
			return (1.0/result);
		}
	}
}

_Bool str_init(char str[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		str[i] = '\0' ;
	}

	return 0;
}

_Bool str_fill(char str[]) {
	//printf("%u", str_length(str));
	str_init(str);
	
	
	for (size_t i = 0; i < MAX_SIZE; i++) {
		scanf_s("%c", &str[i]);
		if (str[i] == '\n') {
			break;
		}
	}
	fflush(stdin);
}

_Bool str_add(char str1[], char str2[]) {
	size_t mycount = 0;


	if ((MAX_SIZE - str_length(str1)) > str_length(str2)) {
		for (size_t i = str_length(str1); i < str_length(str1) + str_length(str2); i++, mycount++) {
			str1[i] = str2[mycount];
		}
	}
	else {
		puts("Array is too small for me!");
	}

	return 0;
}

_Bool str_removeSpaces(char str[]) {
	size_t textStartindex=NULL;
	size_t textEndindex = NULL;

	///SPACES AM ANFANG

	for (size_t i = 0; i < MAX_SIZE; i++) {				//textStartIndex bestimmen
		if (str[i] != 32 && str[i] != '\0') {
			textStartindex = i;
		//	printf("StartINDEX : %d\n", textStartindex);
			break;
		}
	}

	for (size_t i = MAX_SIZE; i > 0; i--) {				//textEndIndex bestimmen
		if (str[i] != 32 && str[i] != '\0') {
			textEndindex = i;
			//printf("%d Endindex\n", i);
			break;
		}
	}


	if (textStartindex != NULL && textStartindex > 0) {
		for (size_t i = 0; i < textEndindex+1-textStartindex; i++) {
			//printf("%d nach links\n", i);
			str[i] = str[i + textStartindex];    //nach links rücken - Leerzeichen am Anfang entfernen
		
		}
		
	}
	textEndindex = textEndindex - textStartindex;
	//printf("neuer Endindex: %d\n", textEndindex);


	if (textEndindex != NULL) {
		for (size_t i = MAX_SIZE; i > textEndindex; i--) {
			//printf("0Byte an Endstelle %d eingefügt\n", i);
			str[i] = '\0';  //Statt Leerzeichen NullByte eienfügen - Leerzeichen am Ende entfernen
			
		}
	}

	//WENN String nur aus Leerzeichen besteht.
	if (textStartindex == NULL && textEndindex == NULL) {
		//puts("Nur Leerzeichen! String wird mit 0Byte initialisiert.");
		str_init(str);
	}


}

size_t str_sum(char str[]) {
	size_t sum = 0;;
	
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		sum += str[i];
	}
	return sum;
}


size_t str_findchr(char str[], char chr) {
	size_t count = 0;;

	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == chr) {
			count++;
		}
	}
	return count;
}

_Bool str_prepend(char str1[], char str2[]) {
	
	//char temp;



	if ((MAX_SIZE - str_length(str1)) > str_length(str2)) {

		/*for (size_t i = 0; i < str_length(str1) + str_length(str2); i++) {
			temp = str1[i];
			str1[i] = str2[i];
			str1[i + str1Length] = temp;
		}

		for (size_t i = str2Length; i < str1Length - str2Length; i++) {
			
			str1[i] = str2[i];
			str1[i + str1Length] = temp;
		}*/



		//SHIFTING IT!

		for (int i = str_length(str1); i >= 0;i--) {
			str1[i+ str_length(str2)] = str1[i];
		}
		for (size_t i = 0; i < str_length(str2); i++) {
			str1[i] = str2[i];
		}
	}
	else {
		puts("Array is too small for me!");
	}
	return 0;
}

size_t str_delchr(char str[], char chr) {
	size_t count = 0;

	for (int i = 0; i < str[i] != '\0'; i++) {
		if (str[i] == chr) {
			count++;
			
			for (int y = i;  str[y] != '\0'; y++) {
				str[y] = str[y + 1];				
			}
			i--;
		}
	}	
	return count;
}

_Bool str_sort(char str[], _Bool mode, size_t sorting_algo) {
	//(mode) ? insertionSortRecursiveUp(str, str_length(str)) : insertionSortRecursiveDown(str, str_length(str));

	switch (sorting_algo) {
	case 1: (mode) ? bubbleSortDown(str) : bubbleSortUp(str); break;
	case 2: (mode) ? insertionSortRecursiveDown(str, str_length(str)) : insertionSortRecursiveUp(str, str_length(str)); break;
	
	
	default: break;
	}




	
		
	return 0;
}
void bubbleSortUp(char str[]){
	char temp = '\0';

	for (int i = 0; i < str_length(str) - 1; i++) {
	for (int j = 0; j < str_length(str) - i - 1; j++) {
			if (str[j] > str[j + 1]) {
				//swap(&str[j], &str[j + 1]);
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}
void bubbleSortDown(char str[]) {
	char temp = '\0';

	for (int i = 0; i < str_length(str) - 1; i++) {
		for (int j = 0; j < str_length(str) - i - 1; j++) {
			if (str[j] < str[j + 1]) {
				//swap(&str[j], &str[j + 1]);
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}








#pragma endregion