#include <iostream>


/*
int sum(int*  numA, int* numB)
{
	return *numA + *numB;
}
*/


int difference(int* numOne, int* numTwo)
{
	return *numOne - *numTwo;
}

void multThree(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
		if (i % 3 == 0)
		{
			std::cout << arr[i] << std::endl;
		}
	}
}

void pointerintarr(int* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{

		std::cout << arr[i] << std::endl;
	}
}

int main()
{

	//tutorial stuff
	/*
	int age = 13;

	int* agePtr = new int(22);
	
	std::cout << age << std::endl;

	std::cout << agePtr << std::endl;

	int* ageAlias = &age;

	*ageAlias = 48;

	std::cout << age << std::endl;

	int result = sum(agePtr, ageAlias);
	std::cout << result << std::endl;

	delete agePtr;
	*/
	
	//closed

	//1 a heap	
	/*
	int* blah = new int (1);

	float* blah2 = new float (1.0);

	bool* memes = new bool(true);
	
	int* array = new int [5];

	float* farray = new float[5];

	bool* barray = new bool[false];

	delete blah;
	delete blah2;
	delete memes;

	delete[] array;
	delete[] farray;
	delete[] barry;
	*/

	//2 sub heap
	/*
	int* numone = new int(10);
	int* numtwo = new int(20);


	int diff = difference(numone, numtwo);
	std::cout << diff << std::endl;
	delete numone;
	delete numtwo;
	*/

	//3 arr pop heap
	/*
	int* numArray = new int[100];
	for (int i = 0; i < 100; i++)
	{
		numArray[i] = i;
		std::cout << numArray[i] << std::endl;
	}
	delete[] numArray;
	*/


	//open

	//1 pop array 1 to x in mults of 3
	/*
	int size = 0;
	std::cout << "How big is the array?" << std::endl;
	std::cin >> size;

	int* arrayNum = new int[size];
	multThree(arrayNum, size);

	
	*/

	//2 print heap allocate int arr
	/*
	int array[5] = { 1, 2, 5, 6, 8 };
	int* s = new int (5);


	pointerintarr(array, s);
	
	*/
	
	//3 Heap alloc array numbers
	/*
	int size = 0;

	std::cout << "Whats the size of the array?" << std::endl;
	std::cin >> size;

	int* array = new int [size];

	int i = 0;

	for (i = 0; i < size; i++)
	{
		std::cout << "Enter number " << i + 1 << std::endl;
		int input = -1;
		std::cin >> input;

		array[i] = input;
		
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}
	*/

	//4 adding up to 21
	/*
	std::cout << "How many? " << std::endl;
	int count = 0;
	std::cin >> count;
	int* numbers = new int[count];
	for (int i = 0; i < count; i++)
	{
		int userInp = 0;
		std::cin >> userInp;
		numbers[i] = userInp;
	}
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += numbers[i];
	}

	if (total == 21)
	{
		std::cout << "memes" << std::endl;
	}
	else
	{
		std::cout << "No MEMEMEMEMES" << std::endl;
	}
	*/




	while (true) {};
}