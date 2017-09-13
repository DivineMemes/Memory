#include <iostream>
#include <cstdlib>
#include <time.h>
#include "assert.h"
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

void diffArrays(int* arrA, size_t arrASize, int* arrB, size_t arrBSize)
{
#ifdef _DEBUG
	if(arrBSize > arrASize)
	{
		cerr << "your a failure" << __LINE__ <<  endl;
		abort();
	}
#endif

	for (int i = 0; i < arrBSize; i++)
	{
		arrA[i] -= arrB[i];
	}
}


void counter()
{
	static int ct = 0;
}

void releaseHalfLove()
{
	static int counter = 0;
	cout << "half life " << counter + 1 << endl;

	counter = ++counter %2;
}

void stepFizzBuzz()
{
	static int counter = 1;
	if (counter % 3 == 0)
	{
		cout << "FIZZ" << endl;
		if (counter % 5 == 0)
		{
			cout << "BUZZ" << endl;
		}
	}
	else if (counter % 5 == 0)
	{
		cout << "BUZZ";
	}
	else
	{
		cout << counter;
	}
	counter++;
	cout << endl;
}


void callMeMaybe()
{
	int meme = rand() % 3+1;
	char memes[] = { "MayMays" };
	char napolean[] = { "TINA COME GET YOUR DINNER YOU FAT LARD" };
	char warframe[] = { "TENNO SCUUUUM" };
	
	if (meme == 1)
	{
	for(int i = 0; i < strlen(memes); i++)
	{
		cout << memes[i];
	}
	cout << endl;
	}

	if (meme == 2)
	{
		for (int i = 0; i < strlen(napolean); i++)
		{
			cout << napolean[i];
		}
		cout << endl;
	}

	if (meme == 3)
	{
		for (int i = 0; i < strlen(warframe); i++)
		{
			cout << warframe[i];
		}
		cout << endl;
	}
	
}




int main()
{
	srand(time(NULL));
	/*
	int numA[] = { 3, 2, 1 };
	int numB[] = { 3, 2, 1, 10, 15 };
	diffArrays(numA, 3, numB, 5);
	for (int i = 0; i < 3; i++)
	{
		std::cout << numA[i] << std::endl;
	}
	*/
	


	//closed 
	//half life 1.5
	/*
	for (int i = 0; i < 4; i++)
	{
		releaseHalfLove();
	}*/

	static int blah = 0;
	for (blah = 0; blah < 10; ++blah)
	{ 
		callMeMaybe();
	}


	while (true) {};
}
