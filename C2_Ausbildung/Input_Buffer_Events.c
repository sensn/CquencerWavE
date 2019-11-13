#include <windows.h>
#include <stdio.h>
#include<conio.h>
#include "rlutil.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD,FILE* fp[]);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
_Bool ispressed = 0;





int input_Buffer_Events_main(VOID)
{
	//system("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
	
	//system("start powershell.exe Start-Transcript -Path C:\Users\ATN_70\Desktop\C2_Ausbildung-master\C2_Ausbildung\ps.txt -NoClobber");
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	printf("columns: %d\n", columns);
	printf("rows: %d\n", rows);




	FILE* f = fopen("somefile.txt", "a+");
	FILE* fp[] = { stdout, f };
	//f = fopen("somefile.txt", "a+");
	//FILE* fp[] = { stdout, f };
	
	/*FILE* fp1;
	int stdout_bk;

	fp1 = fopen("temp.txt", "w");
	dup2(fileno(fp1), fileno(stdout));
*/
	
	

	//TEXTCOLOR
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("This is some nice COLORFUL text, isn't it?");
	//***************



	_Bool leftispressed = 0;
	//printf("[]");
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");


	/*
		 Step-1:
		 Disable 'Quick Edit Mode' option programmatically
	  */
	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");
	/*
	   Step-2:
	   Enable the window and mouse input events,
	   after you have already applied that 'ENABLE_EXTENDED_FLAGS'
	   to disable 'Quick Edit Mode'
	*/


	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	//SetConsoleMode(hStdin, fdwMode);
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 

	while (1)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
			
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				/*FILE* fp1;
				UINT oldcp = GetConsoleOutputCP();
				printf("%u", oldcp);
				
				fp1 = fopen("temp.txt", "w");
				fprintf(fp1, oldcp);
				fclose(fp1);*/
				//system("/TEE  process.out");
				//system("get-process | tee -filepath C:\file.txt");
				//system("start powershell.exe Set-ExecutionPolicy RemoteSigned \n");
				//system(" powershell.exe Get-Process |powershell.exe tee p:\\MyLogfile.txt");
				
				//return 0;
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent,fp);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
		/*for (int i = 0; i < ARRAY_LEN(fp); i++) {
			fprintf(fp[i], stdout);
		}*/
	
	
	}
	
	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	//RESTORE TEXTCOLOR
	  /* Restore original attributes */
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("Back to normal");

	

//	fclose(fp);
	return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	//printf("Key event: ");
	static count = 0;
	if (ker.bKeyDown) {
		//printf("key pressed  %c \n", ker.uChar.AsciiChar);
		if (ker.uChar.AsciiChar =='a')
		ispressed = ++count %2;
		else if (ker.uChar.AsciiChar == 'c')
			system("cls");
		DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		//SetConsoleMode(hStdin, fdwMode);
		if (!SetConsoleMode(hStdin, fdwMode))
			ErrorExit("SetConsoleMode");
	} 

	else {
	//printf("key released %c\n", ker.uChar.AsciiChar);
	
	}
	

	//if (ker.dwControlKeyState == CAPSLOCK_ON)
	//{
	//	//printf("key released %c\n", ker.uChar.AsciiChar);
	//	ispressed = 1;
	//}
	//else {
	//	ispressed = 0;
	//}


	}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer,FILE* fp[])
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	//printf("Mouse event: ");
	char c[199] = { 0 };
	switch (mer.dwEventFlags)
		
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			//freopen("output.txt", "a+", stdout);
			//SetPosition(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			////
			//setColor(10);
			//
			//printf("*");
			//
		
			//freopen("CON", "w", stdout);
			SetPosition(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			//
			setColor(10);
			printf("*");

			//fputc(c, fp);
			//fscanf(stdout,"%[^\n]", c);
			//for (int i = 0; i < 2; i++) {
				//fprintf(fp, c);
			//	fprintf(fp[i], "Current serial number [%ld]\n", serial_info_p->start_int_idx);
			//}





			/*printf("left button press \n");
			printf("left clicked at x=%d, y=%d\n", mer.dwMousePosition.X, mer.dwMousePosition.Y);*/


			/*int myint = 0;
			puts("inputnumber");
			scanf_s("%d", &myint);*/
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			
			//printf("right button press \n");
		}
		else
		{
			//printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		//printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		//printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		//printf("mouse moved\n");
		if (ispressed) {
			SetPosition(mer.dwMousePosition.X, mer.dwMousePosition.Y);
			//
			printf("*");
		}

		break;
	case MOUSE_WHEELED:
		//printf("vertical mouse wheel\n");
		break;
	default:
		//printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}