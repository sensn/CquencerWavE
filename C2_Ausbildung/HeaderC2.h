#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>  

#include "Makros.h"

#include "math.h"
#include "string.h"
#include "windows.h"

//***UMLAUTE***

#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225

//oder ANSI-Codes Direkt in String

//Zeichen     Hex    Okt
//========================
//'Ä'       8E     216
//'ä'       84     204
//'Ö'       99     231
//'ö'       94     224
//'Ü'       9A     232
//'ü'       81     201
//'ß'       E1     341

// cout << "Oberfl\x84 \bche" << endl;
// \b rücktaste
///************



// ***Prototypen C2_Func

void myfunc();
int digit_input(void);		//Ziffer einlesen 
unsigned long recursive_add(int n);
void output_exV_1(void);
void output_sphereV();
float sphere_volume(float radius);
void loopdelta();
char* tohex(unsigned int); //Funktions Prototyp
void tohex_test();
void array14();
void testchar(char mychararr[]);
void gleicheZeichen();
void wortraten();

//*** Prototypen C2_Nuetzliche_Funktionen
#define MAX_SIZE 100

void mymain();
int call_str_func();

void str_output(char str[]);

_Bool str_comp(char str1[], char str2[]);
size_t str_length(char str1[]);
_Bool str_copy(char str1[], char str2[]);
_Bool str_reverse(char str1[]);
_Bool str_case(char str[], _Bool toCase);
char char_type(char thechar);
double power(long long base, char expo);
_Bool str_init(char str[]);
_Bool str_fill(char str[]);
_Bool str_add(char str1[], char str2[]);
_Bool str_removeSpaces(char str[]);
size_t str_sum(char str[]);
size_t str_findchr(char str[], char chr);
_Bool str_prepend(char str1[], char str2[]);

_Bool str_sort(char str[], _Bool mode, size_t sorting_algo);
	void bubbleSortUp(char str[]);
	void bubbleSortDown(char str[]);



void insertionSortRecursiveUp(char arr[],int n);
void insertionSortRecursiveDown(char arr[], int n);
void swap(int* xp, int* yp);



//****

void SetPosition(int X, int Y);
