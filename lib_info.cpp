/*
Authors: Skylar Mcdermott and Erdinc Ozturk
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
// used to control output

using namespace std;

// has name and length of a song
struct Song {
	string title;
	int time = 0;
};

// has map of songs, album name, album length, and number of songs
struct Album {
	map<int, Song> songs;
	string name;
	int time = 0;

};
// has map of albums, total time, artist name, and number of songs
struct Artist {
	map<string, Album> albums;
	string name;
	int time = 0;
	int nsongs = 0;
};

// "Dave_Matthews" --> "Dave Matthews"
void underscores_to_spaces(string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		if(s[i] == '_') {
			s[i] = ' ';
		}
	}
}

// converts time from mins:secs to number of seconds and returns it
// this function makes the assumption that mins < 10 for a song (m:ss) (mm:ss) will not work
int convertTime(string time) {  // chage it to stdoi
	int pos = time.find(':');
	int min = stoi(time.substr(0, pos));
	int sec = stoi(time.substr(pos + 1));
	return min*60 + sec;
}



// converts total time in seconds to mins:secs
string to_mmss(int total){
	string sec = to_string(total % 60);
	if (sec.size() == 1) sec = "0" + sec;
	return to_string(total/ 60) + ":" +sec;
}


int main(int argc, char const *argv[])
{
	/* code */
	if (argc != 2)
	{
		cerr << "usage: lib_info file\n";
		return 1;
	}

	ifstream musicFile(argv[1]);
	if (!musicFile.is_open())
	{		cerr << "Cannot open " << argv[1] << "\n";
		return 1;
	}

	map<string, Artist> artists;

	string title, time, artist, album, genre;
	int track;  // numbers value matters to sort correctly that why we can use string for tracks.
    // loop to read in music library
	while (musicFile >> title >> time >> artist >> album >> genre >> track) {

		underscores_to_spaces(title);
		underscores_to_spaces(artist);
		underscores_to_spaces(album);

		int seconds = convertTime(time);

		Artist &ar = artists[artist];
		ar.name = artist;

		Album &al = ar.albums[album];
		al.name = album;

		al.songs[track].title = title;
		al.songs[track].time = seconds;

		al.time += seconds;
		ar.time += seconds;
		ar.nsongs++;

	}
	musicFile.close();
    // outputs in the correct format

	for (map<string, Artist>::iterator it = artists.begin(); it != artists.end(); ++it) {
		Artist &ar = it->second;
		cout << it->first << ": " << ar.nsongs << ", " << to_mmss(ar.time) << endl;

		for (map<string, Album>::iterator it2 = ar.albums.begin(); it2 != ar.albums.end(); ++it2) {
			Album &al = it2->second;
			cout << "        " << it2->first << ": " << al.songs.size()
				<< ", " << to_mmss(al.time) << endl;

			for (map<int, Song>::iterator it3 = al.songs.begin(); it3 != al.songs.end(); ++it3) {

				int trackNo = it3->first;
				Song &sg = it3->second;
				cout << "                " << trackNo << ". " << sg.title
					<< ": " << to_mmss(sg.time) << endl;
			}
		}
	}
	return 0;
}
