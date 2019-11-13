#include <stdio.h> /* für printf() und scanf() */
#include <stdlib.h> /* für exit() */

#include "HeaderC2.h"
#define MAX_CHAR 100 /* maximale Anzahl der Bücher */

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

struct thestruct {
	char name[MAX_CHAR];
	int x;
	int y;

	struct date_st {
		int day;
		int month;
	}date;
};
typedef struct {
	int stiege;
	int tuer;
}Hause;


typedef struct {
	char street[100];
	int housenumber;
	Hause hause[10];
}Adresse;



//*** Bitföd
struct flag_st {
	unsigned f1 : 1;
	unsigned f2 : 1;
	unsigned f3 : 1;
	unsigned f4 : 1;
	unsigned f5 : 1;
};




int struct_uebung1(){
	struct thestruct ts1 = {"MI NAME HUBERT!",27,73,55,77};
	struct thestruct ts2;
	struct flag_st flag[10];
	char newname[33] = "Supermann";
	Hause h1 = { 444,222 };
	//Adresse adr1 = {"Rotensternstrasse",21,{777,999}};
	Adresse adr1 = { "Rotensternstrasse",21, .hause[0].stiege = 776, .hause[0].tuer = 333 };
	//adr1.hause.stiege = 12,129;
	
		str_init(adr1.street);

	/*	printf("STRLENGTH: %d", str_length(adr1.street));
		printf("STRLENGTH: %d", str_length(newname));
		printf("STRLENGTH: %s", adr1.street);*/
		
		str_copy(newname,adr1.street);
		
		//printf("STRLENGTH: %s", adr1.street);
	
//	ts2 = ts1;
	
	//printf("%s %d %d %d\n\n\n", ts2.name, ts2.x, ts2.y,ts1.date.day);
	printf("Street: %s %d %d\n\n\n", adr1.street,adr1.housenumber,adr1.hause[0].stiege);
	//printf("H1: %d\n\n\n", h1.stiege);


	flag[9].f1 = 0;


}