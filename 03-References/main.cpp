#include <iostream>
#include "aussiegochi.h"
#include "mixtape.h"
using std::cout;
using std::cin;
using std::endl;


struct Weapon
{
	int bluntDamage;
	int magicDamage;
	int bladeDamage;

	struct OwnerInfo
	{
		int playerID;
		bool isRare;
	};
	OwnerInfo owner;
};

void enhanceWeapon(Weapon& weap)
{
	weap.bluntDamage *= 2;
	weap.magicDamage *= 2;
	weap.bladeDamage *= 2;
}

void sum(int a, int b, int& c)
{
	c = a + b;
}

void product(float a, float b, float& c)
{
	c = a * b;
}

void swap(float& a, float& b)
{
	float swap = 0;
	 swap = a , a = b, b = swap;
}

int main()
{


	//references
	/*
	int meme = 10; //op
	int& repost = meme; //meme stealer
	int* repostPtr = &meme; // user saving repost

	int maymay = meme; // copy in action

	meme = 9001;

	cout << meme << endl;
	cout << repost << endl;
	cout << *repostPtr << endl;
	cout << "maymay" << endl;
	cout << maymay << endl;
	*/





	//references with functuions
	/*
	int valA = 1;
	int valB = 2;
	int valC = -1;


	cout << valC << endl;

	sum(valA, valB, valC);

	cout << valC << endl;
	*/

	//weapon system stuff
	/*
	Weapon hammer;
	hammer.bluntDamage = 9001;
	hammer.bladeDamage = 0;
	hammer.magicDamage = 0;

	
	enhanceWeapon(hammer);

	int thing = -12;
	Weapon aresenal[3] =
	{ // blunt  magic  blade   PID   rarity
		{9001,   0,     0,     {0,    true}},
		{0,      9001,  0,     {0,    true}},
		{0,      0,     8999,  {0,    false}}
	};


	for (int i = 0; i < 3; i++)
	{
		int& pid = aresenal[i].owner.playerID;

		if (pid == 0)
		{
			pid = -1;
		}
	}
	*/


	//closed

	//1: creating references
	/*
	int number = 0;
	float decimal = 0.0f;
	bool tf = false;
	char letter = 'a';


	int& numRef = number;
	float& decRef = decimal;
	bool& tfRef = tf;
	char& letterRef = letter;
	*/


	//2: prod 2 floats
	/*
	float a = 2.9f;
	float b = 3.6f;
	float c = 2.4f;

	product(a, b, c);
	cout << c << endl;
	*/



	//open

	//1: swap
	/*
	float a = 1.0f;
	float b = 2.0f;
	cout << "A = " << a << " B = " << b << endl;

	swap(a, b);

	cout << "A = " << a << " B = " << b << endl;
	*/

	//2 aussi
	Aussiegochi aus;
	{
		aus.happiness = 100;
		aus.hunger = 0;
		aus.sanity = 100;
		aus.thirst = 0;
	};
	



	//3 mixmeme
	Track songs[7];
	songs[0].TrackName = "IdontKNow";
	songs[0].playTime = 3.70f;
	songs[1].TrackName = "PokeMon";
	songs[1].playTime = 2.50f;
	songs[2].TrackName = "SamSmith";
	songs[2].playTime = 1.50f;
	songs[3].TrackName = "2CHAINZ";
	songs[3].playTime = 7.70f;
	songs[4].TrackName = "HapyyBirthday";
	songs[4].playTime = 1.20f;
	songs[5].TrackName = "HapyyBirthday";
	songs[5].playTime = 1.20f;
	songs[6].TrackName = "HapyyBirthday";
	songs[6].playTime = 1.20f;

	Playlist iPod = { "AWesome", songs, 7 };


	printPLaylist(iPod);

	std::cout << "SHUFFLED" << std::endl;
	shufflePlaylist(iPod);
	printPLaylist(iPod);
	DedupePlaylist(iPod);
	printPLaylist(iPod);


	while (true) {};
}