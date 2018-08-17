#include <iostream>
#include <vector>
#include "Song.h"


Song::Song(string name = "no name", string initialLine = "none", int timesPlayed = 0)
{
	songName = name;
	firstLine = initialLine;
	numPlays = timesPlayed;
}

string Song::GetName()
{
	return songName;
}

void Song::ToString()
{
	cout << songName << ": \"" << firstLine << "\", " << numPlays << " play(s)." << endl;
}


void Song::PlaySong()
{
	cout << firstLine << endl;
	numPlays++;
}

