#include "mixtape.h"
#include <iostream>
#include <random>
#include <ctime>
void printPLaylist(const Playlist & pl)
{
	std::cout << pl.name << std::endl;

	for (int i = 0; i < pl.trackCount; i++)
	{
		if (pl.trackList[i].Skipped == false)
		{
			std::cout << pl.trackList[i].TrackName << std::endl;
			std::cout << (int)pl.trackList[i].playTime << ":" << (pl.trackList[i].playTime - (int)pl.trackList[i].playTime) * 100 << std::endl;
		}

	}

}


void shufflePlaylist(Playlist& pl)
{
	srand(time(NULL));
	int counter = rand() % 100;
	Track temp;

	while (counter > 0)
	{
		int bogo = rand() % (pl.trackCount - 1);

		temp = pl.trackList[bogo];

		pl.trackList[bogo] = pl.trackList[bogo + 1];
		pl.trackList[bogo + 1] = temp;

		counter--;
	}
}

void DedupePlaylist(Playlist & pl)
{
	for (int i = 0; i < pl.trackCount; i++)
	{
		for (int j = i + 1; j < pl.trackCount; j++)
		{
			if (pl.trackList[i].TrackName == pl.trackList[j].TrackName)
			{
				pl.trackList[j].Skipped = true;
				pl.trackList[j].TrackName = "";
				pl.trackList[j].playTime = 0.0f;
			}
		}
	}
}