#include <iostream>
#include <vector>
#include "Playlist.h"
#include "Song.h"

Playlist::Playlist(string playlistName = "none")
{
	name = playlistName;
}

void Playlist::ToString()
{
	cout << ": " << name << endl;
}

string Playlist::GetName()
{
	return name;
}

void Playlist::AddSongToPlaylist(Song* newSongPtr)
{
	playlist.push_back(newSongPtr);
}

void Playlist::PlayPlaylist()
{
	for (size_t i = 0; i < playlist.size(); i++)
	{
		playlist.at(i)->PlaySong();
	}
	cout << endl;
}

void Playlist::GetPlaylistSongs()
{
	for (size_t i = 0; i < playlist.size(); i++)
	{
		cout << i << ": " << playlist.at(i)->GetName() << endl;
	}
}

void Playlist::DeleteSongFromPlaylist(int songIndex)
{
	playlist.erase(playlist.begin() + songIndex);
}

void Playlist::FindAndDeleteFromPlaylist(Song*& songPtr)
{
	for (size_t i = 0; i < playlist.size(); i++)
	{
		if (playlist.at(i) == songPtr)
		{
			DeleteSongFromPlaylist(i);
		}
	}
}
