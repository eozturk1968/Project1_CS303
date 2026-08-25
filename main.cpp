/*
Authors: skylar mcdermott and Erdinc Ozturk
This program stores a music library using nested maps, populating them from input files
It calculates the listening time  of each artist, album, and song
Displays every artist with their albums and songs
*/
/*
Sample input
Countdown 2:25 Coltrane,_John Giant_Steps Jazz 3
Down_In_Brazil 6:07 Walton,_Cedar Naima Jazz 4
Giant_Steps 4:02 Puente,_Tito El_Rey Jazz 5
Giant_Steps 4:46 Coltrane,_John Giant_Steps Jazz 1
Mr._P.C. 7:02 Coltrane,_John Giant_Steps Jazz 7
Naima 4:24 Coltrane,_John Giant_Steps Jazz 6
Naima 5:16 Lyle,_Bobby Night_Breeze Jazz 5
Naima 5:36 Tjader,_Cal A_Fuego_Vivo Jazz 6
Naima 7:49 Walton,_Cedar Naima Jazz 6
Naima 8:38 Walton,_Cedar Eastern_Rebellion Jazz 2
This_Guy's_In_Love_With_You 8:10 Walton,_Cedar Naima Jazz 2

*/

#include <iostream>
#include <map>
#include <string>
// used to read file
#include <fstream>
// used to control output formatting
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
};

int main(int argc, char const *argv[])
{
	/* code */
	string fileName = argv[1];
	ifstream musicFile;
	musicFile.open(fileName);
	if (!musicFile.is_open() || argc < 2) {
		cout << "Invalid filename: ' " << fileName << " '.\n";
		return 1; 
	}
	// read in file data


	musicFile.close();
	return 0;
}








