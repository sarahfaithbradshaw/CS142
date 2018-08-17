#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist
{
public:
	Playlist(string playlistName);
	void ToString();
	string GetName();
	void AddSongToPlaylist(Song* newSongPtr);
	void PlayPlaylist();
	void GetPlaylistSongs();
	void DeleteSongFromPlaylist(int songIndex);
	void FindAndDeleteFromPlaylist(Song*& songPtr);

private:
	string name;
	vector<Song*> playlist;
};

#endif
