#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <ctime>
#include <thread>
#include "Sound.h"
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

HANDLE hStdin;
DWORD fdwSaveOldMode;
fstream TimeFile;
fstream ClickFile;
string restart = "restart";
string input;

string timeI;

bool Juice = false;

int clicks = 0;
int savedClicks = clicks;


void ColorPicker(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
int main(VOID)
{
	cout << "Welcome to Console Clicker, you must really hate yourself if you're playing this right now!" << endl;
	srand(NULL);
	char buf[256];
	time_t t = time(NULL);
	struct tm timeInfo;

	if (localtime_s(&timeInfo, &t) == 0)
	{
		strftime(buf, sizeof(buf), "%H:%M:%S", &timeInfo);
	}

	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// check to see if it exists
	//TimeFile.open("TimeRecording", std::ios::out | std::ios::in);
	TimeFile.open("timeRec", std::ios::in | std::ios::out );
	
	if (TimeFile.fail())
	{
		TimeFile.clear();

		TimeFile.open("timeRec", std::ios::out);
	}
	else
	{
		string buffer ;
		string lastOpen;
		string StoiString = "";//array that we convert and reduce back
		int phour = 0;
		int pmin = 0;
		int psec = 0;
		int chour = 0;
		int cmin = 0;
		int csec = 0;

		while (std::getline(TimeFile, buffer))
		{
			lastOpen = buffer;
			//cout << lastOpen << endl;
			//cout << buf << endl;
			//HoldTime.push_back(buf[0]);

		}


		StoiString.push_back(buf[0]);
		StoiString.push_back(buf[1]);
		chour = std::stoi(StoiString);
		StoiString.pop_back();
		StoiString.pop_back();

		StoiString.push_back(buf[3]);
		StoiString.push_back(buf[4]);
		cmin = std::stoi(StoiString);
		StoiString.pop_back();//function that removes the affects of a push back
		StoiString.pop_back();

		StoiString.push_back(buf[6]);
		StoiString.push_back(buf[7]);
		csec = std::stoi(StoiString);
		StoiString.pop_back();
		StoiString.pop_back();


		StoiString.push_back(lastOpen[0]);
		StoiString.push_back(lastOpen[1]);
		phour = std::stoi(StoiString);
		StoiString.pop_back();
		StoiString.pop_back();

		StoiString.push_back(lastOpen[3]);
		StoiString.push_back(lastOpen[4]);
		pmin = std::stoi(StoiString);
		StoiString.pop_back();//function that removes the affects of a push back
		StoiString.pop_back();

		StoiString.push_back(lastOpen[6]);
		StoiString.push_back(lastOpen[7]);
		psec = std::stoi(StoiString);
		StoiString.pop_back();
		StoiString.pop_back();

		//buffer.push_back('x'); pushes x to the end of a string
		
		cout << "The last time you played was " << phour << ":" << pmin << ":" << psec << endl;
		cout << "The current time it "<< chour << ":" << cmin << ":" << csec << endl;
		
	}

	ClickFile.open("clicks", std::ios::out | std::ios::in);
	if (ClickFile.fail())
	{
		// create the file if it does not exist
		ClickFile.clear();

		ClickFile.open("clicks", std::ios::out);	}
	else
	{
		// read the value if it does
		ClickFile >> savedClicks;
		clicks = savedClicks;
		ClickFile.seekp(0);
	}
	ClickFile.clear();
	cout << "Press shift for cheats and fun" << endl;
		cout << "You have " << clicks << " clicks stored up so far." << endl;
	//assert(!ClickFile.fail());
	

	

	//file << endl << savedClicks;
	

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 

	while (true) 
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
					break;

				case MOUSE_EVENT: // mouse input 
					MouseEventProc(irInBuf[i].Event.MouseEvent);
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

		// Restore input mode on exit.

		SetConsoleMode(hStdin, fdwSaveOldMode);
	}
	return 0;
}

//int main()
//{
//	std::thread one(Fakemain);
//	std::thread Tw0(Sound);
//
//	one.join();
//	Tw0.join();
//
//}


VOID ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	char buf[256];
	time_t t = time(NULL);
	struct tm timeInfo;

	if (localtime_s(&timeInfo, &t) == 0)
	{
		strftime(buf, sizeof(buf), "%H:%M:%S", &timeInfo);
	}
	if (ker.wVirtualKeyCode == VK_ESCAPE)
	{
		ClickFile.flush();
		ClickFile.close();
		
		TimeFile.clear();//clears end of file error
		TimeFile.seekp(0);
		TimeFile << buf;


		TimeFile.flush();
		TimeFile.close();
		exit(0);
	}
	if (true)
	{
		 
	}

	if (ker.wVirtualKeyCode == VK_SHIFT && ker.bKeyDown == false)
	{
		cout << "codes: 'restart', 'instant win', 'Juice',  " << endl;
		cin >> input;
		if (input == restart)
		{
			cout << "That was a waste of time." << endl;
			clicks = 0;
			savedClicks = clicks;
			
			ClickFile.close();
			ClickFile.open("clicks", std::ios::out);

			ClickFile.seekp(0);
			ClickFile << savedClicks;
			ClickFile.flush();
		}
		else if (input == "Juice")
		{
			Juice = true;
		}
		else if (input == "InstantWin")
		{
			while (true)
			{
				int randColor = rand() % 5000 + 1;
				ColorPicker(randColor);
				clicks++;
				cout << clicks << endl;
			}
		}
	}
	
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	// ... printing time ...

	// grab time
	// convert time into a string
	

	switch (mer.dwEventFlags)
	{
	case 0:
	case DOUBLE_CLICK:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			int randColor = rand() % 5000 + 1;
			//assert(!ClickFile.fail());
			if (Juice == true) { ColorPicker(randColor);}
			clicks++;
			savedClicks = clicks;
			ClickFile << savedClicks;
			ClickFile.seekp(0);
			cout << "You have clicked " << clicks << " times." << endl;


			if (clicks >= 100)
			{
				clicks++ * 2;
			}
			if (clicks >= 250)
			{
				clicks++ * 4;
			}
			if (clicks >= 500)
			{
				clicks++ * 8;
			}
			if (clicks >= 1000)
			{
				clicks++ * 10;
			}
			if (clicks >= 2000)
			{
				clicks++ * 50;
			}

		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			
		}
		else
		{
			
		}
		break;
	case MOUSE_HWHEELED:
		break;
	case MOUSE_MOVED:
		break;
	case MOUSE_WHEELED:		
		break;
	default:
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	//printf("Resize event\n");
	//printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}
