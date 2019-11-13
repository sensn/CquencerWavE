#include <stdio.h> /* für printf() und scanf() */
#include <stdlib.h> /* für exit() */
#include "HeaderC2.h"
#include <time.h>
#include <windows.h>// for sleep()
#include <process.h>
#include <conio.h>
//
//#include <windowsx.h>
//#include <mmsystem.h>

//
// PAYSOUND: To do that, right - click on your project and select properties.Then go to the linker->input item.Add ";winmm.lib" to the end of the Additional Dependencies box.
//	PlaySound("C:\\Users\\ATN_70\\Desktop\\C2_Ausbildung\\C2_Ausbildung\\snare.wav", NULL, SND_ASYNC);     PLAY THE SOUND using win api
//PlaySound(NULL, 0, 0);   //Stopd sound that is playing asynchronously



#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void SetPosition(int X, int Y);

typedef struct {
	int trigger[16];
	int notenumber;
	int vel;
	int channel;
}Room;


typedef struct {
	int screenX;
	int screenY;
	Room room[3];

}House;



int main_nestedStruct(int argc, char** argv) {
	_Bool isplaying = 1;
	
	double time_spent = 0.0;

	long begin = clock();

	// do some stuff here
	Sleep(3);

	long end = clock();
	double theend = clock();

	// calculate elapsed time by finding difference (end - begin) and
	// divide by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

//	printf("Time elpased is %f seconds", time_spent);

	//
	int index = 0;

	double ms;
	double dur;
	double swing=0;
	double theswing = 0.33;
	int thebpm=120;
	
	ms = ((60000.0 / (double)thebpm) / (double)4);  //Millisecond per quarternote
	//ms = 125;  //Millisecond per quarternote
	dur = (ms/1000)*CLOCKS_PER_SEC;
	printf("MILLIS PER QUATER:%f\n\n", ms);
	printf("ms/Clocks :%f\n\n", dur);
	
	//
	
	House myHouse = { 640,400, .room[0] = {{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},64,127,1},
							   .room[1] = {{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},64,127,1},
							   .room[2] = {{1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},64,127,1} };
	//printf("THE ROOM: %d\n", myHouse.room[1].notenumber);

	while (isplaying) {
		begin = clock();
		if ((double) begin > theend) {
			
			theend =(double) clock() + dur + (dur * (swing));
			swing=(index % 2)?0: theswing;
			//printf("%f", swing);
			//printf("*");    //Do things...
			
			for (int i = 0; i < 3; i++) {
				if (myHouse.room[i].trigger[index]) {
					SetPosition(index, i+5);
					printf("*");
				//	PlaySound("C:\\Users\\ATN_70\\Desktop\\C2_Ausbildung\\C2_Ausbildung\\snare.wav", NULL, SND_ASYNC);     PLAY THE SOUND using win api
				}
				else {
					//	printf("-");
				}
			}//for



			index++;
		} //if beginn > end


		if (index == 16) { //reset things
			//tickindex = 0;
			index = 0;
			system("cls");
			//puts("");

		}

	}


	//struct timespec now;
	//struct timespec then;

	//long long rightnow;
	//long long rightthen;
	//long akt_zeit;
	//long end_zeit;

	//int zahl=5;
	//time(&then);
	//rightthen = then.tv_nsec + 1000000000LL;

	//while (zahl != 0) {
	//	time(&now);
	//	rightnow = now.tv_sec;
	//	printf("NOW: %llu\n", rightnow);

	//	if (rightnow > rightthen) {
	//		time(&then);
	//		rightthen = then.tv_nsec + 10000000LL;

	//		printf("NOW: %llu\n", rightnow);
	//		printf("THEN: %llu\n", rightthen);
	//	}

	//

	//}

	return(0);

}


// **Set Cursor Pos


