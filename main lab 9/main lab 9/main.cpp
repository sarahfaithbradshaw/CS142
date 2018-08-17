/*
Sarah Bradshaw, section 002, sarahfaithbradshaw@gmail.com

Test Case 1: adding songs and playlists and adding songs to playlists
Input: adding appropriate song names and playlist names and then adding them to playlists
Expected Output: reasonable output of adding those songs etc
Result: passed

Test Case 2: playing playlist and listing songs and listing playlists
Input: "play", "list", "listp"
Expected Output: accurate playing of inputted songs in that playlist and reasonable display of inputted songs and playlists
Result:passed

Test Case 3: deleting playlists and songs
Input: "delp", "delsp", "desls" then list and listp to check
Expected Output: successful deletion
Result:passed

freeing memory lines: 117, 140, 172, 178
*/

#include <iostream>
#include "Song.h"
#include "Playlist.h"
using namespace std;

void NewSong(vector<Song*>& library);

void NewPlaylist(vector<Playlist*>& library);

void ListSongs(vector<Song*>& librarySongs);

int SelectIndex(string indexString);

void ListPlaylists(vector<Playlist*> libraryPlaylist);

const int MAX_CHAR = MAX_CHAR;

int main()
{
	string userChoice;
	vector<Song*> songLibrary;
	vector<Playlist*> playlistLibrary;
	int playlistIndex = 0;
	int songIndex = 0;
	Song* tempSongPtr = nullptr;
	Playlist* tempPlaylistPtr = nullptr;
	string songIndexString = "Pick a song index number: ";
	string playlistIndexString = "Pick a playlist index number: ";
	string playlistDeleteIndexString = "Pick a playlist index number to delete: ";
	string songDeleteIndexString = "Pick a song index number to delete: ";
	string playlistName;


	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
	cout << "Enter your selection now : ";
	cin >> userChoice;
	cout << endl << endl;


	while (userChoice != "quit")
	{
		if (userChoice == "quit")
		{
			break;
		}
		else if (userChoice == "add")
		{
			NewSong(songLibrary);
		}
		else if (userChoice == "list")
		{
			for (size_t i = 0; i < songLibrary.size(); i++)
			{
				songLibrary.at(i)->ToString();
			}
		}
		else if (userChoice == "addp")
		{
			NewPlaylist(playlistLibrary);
		}
		else if (userChoice == "listp")
		{
			ListPlaylists(playlistLibrary);
		}
		else if (userChoice == "addsp")
		{
			ListPlaylists(playlistLibrary);
			playlistIndex = SelectIndex(playlistIndexString);

			ListSongs(songLibrary);
			songIndex = SelectIndex(songIndexString);

			tempSongPtr = songLibrary.at(songIndex);
			tempPlaylistPtr = playlistLibrary.at(playlistIndex);

			tempPlaylistPtr->AddSongToPlaylist(tempSongPtr);

		}
		else if (userChoice == "play")
		{
			ListPlaylists(playlistLibrary);
			playlistIndex = SelectIndex(playlistIndexString);
			
			playlistName = playlistLibrary.at(playlistIndex)->GetName();
			cout << endl << "Playing first lines of playlist: " << playlistName << endl;

			tempPlaylistPtr = playlistLibrary.at(playlistIndex);

			tempPlaylistPtr->PlayPlaylist();
		}
		else if (userChoice == "delp")
		{
			ListPlaylists(playlistLibrary);
			playlistIndex = SelectIndex(playlistDeleteIndexString);

			delete playlistLibrary.at(playlistIndex);				//freeing memory
			playlistLibrary.erase(playlistLibrary.begin() + playlistIndex);
		}
		else if (userChoice == "delsp")
		{
			ListPlaylists(playlistLibrary);
			playlistIndex = SelectIndex(playlistIndexString);

			playlistLibrary.at(playlistIndex)->GetPlaylistSongs();
			songIndex = SelectIndex(songDeleteIndexString);

			playlistLibrary.at(playlistIndex)->DeleteSongFromPlaylist(songIndex);

		}
		else if (userChoice == "delsl")
		{
			ListSongs(songLibrary);
			songIndex = SelectIndex(songIndexString);
			tempSongPtr = songLibrary.at(songIndex);

			for (size_t i = 0; i < playlistLibrary.size(); i++)
			{
				tempPlaylistPtr = playlistLibrary.at(i);
				tempPlaylistPtr->FindAndDeleteFromPlaylist(tempSongPtr);
			}
			delete songLibrary.at(songIndex);					//freeing memory
			songLibrary.erase(songLibrary.begin() + songIndex);

		}
		else
		{
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl << endl;
		}


		cout << "Enter your selection now : ";
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
		cin >> userChoice;
		cout << endl;
	}

	cout << "Goodbye!";


	//freeing memory for all songs
	for (size_t i = 0; i < songLibrary.size(); i++)
	{
		delete songLibrary.at(i);
	}

	//freeing memory for all playlists
	for (size_t i = 0; i < playlistLibrary.size(); i++)
	{
		delete playlistLibrary.at(i);
	}

	//system("pause");
	return 0;
}

void NewSong(vector<Song*>& library)
{
	string name;
	string null;
	string firstLine;
	Song* songPtr = nullptr;
	int timesPlayed = 0;

	cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

	cout << "Song Name: ";
	getline(cin, null);
	getline(cin, name);

	while (name != "STOP")
	{
		cout << "Song's first line: ";
		getline(cin, firstLine);

		songPtr = new Song(name, firstLine, timesPlayed);
		library.push_back(songPtr);

		cout << "Song Name: ";
		getline(cin, name);
	}
	cout << endl << endl;
}


void NewPlaylist(vector<Playlist*>& library)
{
	string name;
	string null;
	Playlist* playlistPtr = nullptr;

	cout << "Playlist name: ";
	getline(cin, null);
	getline(cin, name);
	playlistPtr = new Playlist(name);
	library.push_back(playlistPtr);
	cout << endl << endl;
}

void ListSongs(vector<Song*>& librarySongs)
{
	for (size_t i = 0; i < librarySongs.size(); i++)
	{
		cout << i << ": " << (librarySongs.at(i))->GetName() << endl;
	}
}

int SelectIndex(string indexString)
{
	int indexSong = 0;

	cout << endl << indexString;
	cin >> indexSong;
	cout << endl;

	return indexSong;
}

void ListPlaylists(vector<Playlist*> libraryPlaylist)
{
	for (size_t i = 0; i < libraryPlaylist.size(); i++)
	{
		cout << i;
		libraryPlaylist.at(i)->ToString();
	}
	cout << endl;
}

