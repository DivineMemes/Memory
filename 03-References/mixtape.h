#pragma once
#include <string>
struct Track
{
	std::string TrackName;
	float playTime;
	bool Skipped = false;
};

struct Playlist
{
	std::string name;
	Track * trackList;
	int trackCount;
};

void printPLaylist(const Playlist& pl);
void shufflePlaylist(Playlist& pl);
void DedupePlaylist(Playlist& pl);