#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <ctime>

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


int clicks = 0;
int savedClicks = clicks;
VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
int main(VOID)
{

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
		string buffer;
		string lastOpen;
		while (std::getline(TimeFile, buffer))
		{
			lastOpen = buffer;
			cout << lastOpen << endl;
			cout << buf << endl;
			cout << buf[0] - lastOpen[0] << endl;
			cout << buf[1] - lastOpen[1] << endl;
			cout << buf[3] - lastOpen[3] << endl;
			cout << buf[4] - lastOpen[4] << endl;
			cout << buf[6] - lastOpen[6] << endl;
			cout << buf[7] - lastOpen[7] << endl;
		}
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
	assert(!ClickFile.fail());
	

	

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
	if (ker.wVirtualKeyCode == VK_SHIFT && ker.bKeyDown == false)
	{
		cout << "codes: 'restart', 'instant win' " << endl;
		cin >> input;
		if (input == restart)
		{
			cout << "That was a waste of time." << endl;
			clicks = 0;
			savedClicks = clicks;
			ClickFile << savedClicks;
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
			assert(!ClickFile.fail());
			clicks++;
			savedClicks = clicks;
			ClickFile << savedClicks;
			ClickFile.seekp(0);
			cout << "You have clicked " << clicks << " times." << endl;
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
