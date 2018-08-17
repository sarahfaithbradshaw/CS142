#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song
{
public:
	Song(string name, string initialLine, int timesPlayed);
	string GetName();
	void ToString();
	void PlaySong();

private:
	string songName;
	string firstLine;
	int numPlays;
};

#endif