#include <iostream>
#include <fstream>
#include <string>

using std::fstream;

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//tutorial
	/*
	fstream file;
	file.open("text.txt");
			//if problem fail = true
	if (file.fail())
	{
		std::cout << "File not found. " << std::endl;
		return -1;
	}



	//reading from file
	string buffer;
	while (std::getline(file, buffer))
	{
		std::cout << buffer << std::endl;
	}
	file.clear(); //resetting error flags

	file.seekp(0, std::ios_base::end);//move cursor to th end

	//writing to file
	file << std::endl << "Tomorrow is a possible end. ";
	file.flush();
	file.close();

	//creates new file for free

	fstream memes;
	memes.open("repost.txt", std::ios::out);

	if (memes.fail())
	{
		std::cout << "problems! " << std::endl;
	}
	memes.close();
	*/
	//1 digital printer
	/*
	bool reset = false;
	string fileName = {};
	string buffer;
	fstream file;

	while(reset == false)
	{
		cout << "choose a file to open. " << endl;
		cin >> fileName;


		file.open(fileName, std::ios_base::_Nocreate);

		if (file.fail())
		{
			cout << "File does not exist try again. " << endl;
		}
		while (std::getline(file, buffer))
		{
			std::cout << buffer << std::endl;	
		}
	
		file.clear(); //resetting error flags
		file.close();
	}
	*/


	//2 my information
	fstream info;
	string fileName = {};
	string name = {};
	string color = {};
	int age = 0;

	cout << "Whats the name of the file you want to create? (dont forget to add .txt) " << endl;
	cin >> fileName;
	info.open(fileName, std::ios_base::out);
	
	if (info.fail())
	{
		cout << "Err File not available. " << endl;
	}
	cout << "Whats your name? " << endl;
	info.seekp(0, std::ios_base::end);
	cin >> name;
	info << std::endl << name;

	cout << "how old are you? " << endl;
	cin >> age;
	info << std::endl << age;

	cout << "Whats your favorite color? " << endl;
	cin >> color;
	info << std::endl << color;
	 
	cout << "File created thanks for providing the nsa with your info! " << endl;

	info.close();
	while (true) {};
}