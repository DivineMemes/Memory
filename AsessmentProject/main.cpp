#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

HANDLE hStdin;
DWORD fdwSaveOldMode;
fstream file;

int clicks = 0;
int savedClicks = clicks;
VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

int main(VOID)
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// check to see if it exists

	file.open("clicks", std::ios::out | std::ios::in);
	if (file.fail())
	{
		// create the file if it does not
		file.clear();

		file.open("clicks", std::ios::out);	}
	else
	{
		// read the value if it does
		file >> savedClicks;
		clicks = savedClicks;
		file.seekp(0);
	}
	file.clear();
	assert(!file.fail());


	

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
	if (ker.wVirtualKeyCode == VK_ESCAPE)
	{
		file.flush();
		file.close();
		
		exit(0);
	}
	/*printf("Key event: ");
	
	if (ker.wVirtualKeyCode == VK_SPACE)
		printf("key pressed\n");
	else printf("key released\n");*/
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	//printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{
	case 0:
	case DOUBLE_CLICK:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			assert(!file.fail());
			clicks++;
			savedClicks = clicks;
			file.seekp(0);
			
			

			file << savedClicks;

			cout << "You have clicked " << clicks << " times." << endl;
			//printf("left button press \n");
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
	case MOUSE_HWHEELED:
		//printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		//printf("mouse moved\n");
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
	//printf("Resize event\n");
	//printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}