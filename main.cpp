/*
Authors: skylar mcdermott and Erdinc Ozturk
This program stores a music library using nested maps, populating them from input files
It calculates the listening time  of each artist, album, and song
Displays every artist with their albums and songs
*/


#include <iostream>
#include <map>
#include <string>
// used to read file
#include <fstream>
// used to control output
#include <iomanip>

using namespace std;

// has name and length of a song
struct Song {
	string title;
	int length;
};

// has map of songs, album name, album length, and number of songs
struct Album {
	map<int, Song> songs;
	string name;
	int time;
	int nsongs;
};
// has map of albums, total time, artist name, and number of songs
struct Artist {
	map<int, Album> albums;
	string name;
	int time;
	int nsongs;
}

int main(int argc, char const *argv[])
{
	/* code */

	return 0;
}