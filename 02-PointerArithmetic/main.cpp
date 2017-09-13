#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void printFloats(float* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << endl;
	}
}

int arraySum(int* arr, int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
	
		total += *(arr + i);
		
	}
	return total;
}

float arrayavg(int* arr, int size)
{
	int total = arraySum(arr, size);
	return total / (float)size;
}

int findCount(int target, int* arr, int size)
{
	int repeat = 0;

	for (int i = 0; i < size; i++)
	{
		*(arr + i);
		int check = *(arr + i);
		if (check == target)
		{
			repeat += 1;
		}
	}
	return repeat;
}

void arrCopy(float* srcArr, int srcSize, float* dstArr, int dstSize)
{
	for (int i = 0; i < srcSize; i++)
	{
		*(dstArr + i) = *(srcArr + i);
		cout << *(dstArr + i) << endl;
	}
}

void arrReversal(int* arr, int size)
{
	for (int i = size; i > 0; i--)
	{
		cout << *(arr + (i - 1)) << endl;
	}
}

void cstrReversal(char* arr, int size)
{
	//manually determine last valid character
	int len = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i)=='\0')
		{
			break;
		}
		len++;
	}
	for (int i = 0; i < len / 2; i++)
	{
		int temp = *(arr + i);
		*(arr + i) = *(arr + len - 1 - i);
		*(arr + len - 1 - i) = temp;
	}
}

	int main()
	{
		//doesnt work
		/*
		int a = 1;
		int b = 2;

		int* notA = &a;
		std::cout << &a << std::endl;
		std::cout << *(notA+1) << std::endl;
		*/

		//works
		/*
		int* hArr = new int[2];
		hArr[0] = 1;
		hArr[1] = 2;

		std::cout << hArr[0] << std::endl;
		std::cout << hArr[1] << std::endl;
		std::cout << hArr[0] << std::endl;
		std::cout << *(hArr+1) << std::endl;
		*/



		//closed

		//1 print an array of floats

		//float array[5] = { 1.1f, 2.1f, 3.1f, 4.1f, 5.1f };
		//printFloats(array, 5);

		//2 print sum array
		//int sarray[5] = { 1, 2, 3, 4, 5 };
		//cout << arraySum(sarray, 5) << endl;
		

		//3 array avg
		//float avg = arrayavg(sarray, 5);
		//cout << avg;


		//open

		//1 iteration counter
		/*
		int rarray[5] = { 4, 5, 5, 8, 3 };
		int target = 0;

		cout << "Enter a number you want to track " << endl;
		cin >> target;

		cout << findCount(target, rarray, 5) << endl;
		*/

		//2 array Copy
		int arrayOne[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//float arrayTwo[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		//arrCopy(arrayOne, 10, arrayTwo, 10);

		arrReversal(arrayOne, 10);

		char* name = new char[5];
		name[0] = 'W';
		name[1] = 'y';
		name[2] = 'a';
		name[3] = 't';
		name[4] = 't';



		while (true) {};
}