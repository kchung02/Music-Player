#include "MusicPlayer.h"
#include <iostream>
#include <iomanip>
//#include <Time.h>
using namespace std;

int main() {
//    srand(time(0));
    cout << setprecision(2) << fixed;

    cout << "Song Object" << endl << endl;
    Song s1;

    cout << "Getters" << endl;
    cout << "Title: " << s1.getTitle() << endl;
    cout << "Artist: " << s1.getArtist() << endl;

    cout << "Setters" << endl;
    s1.setTitle("Song 1");
    cout << "Title: " << s1.getTitle() << endl;
    s1.setArtist("Someone");
    cout << "Artist: " << s1.getArtist() << endl;
    s1.setDuration(3.5);
    cout << "Song Duration: " << s1.getDuration() << " minutes" << endl << endl;

    cout << "Overloaded Operators" << endl;
    cout << s1 << endl << endl << endl;


    cout << "Playlist Object" << endl << endl;
    Playlist p;

    cout << "Getters" << endl;
    cout << "Title: " << p.getTitle() << endl;
    cout << "Playlist Duration: " << p.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << p.getNumSongs() << endl;
    cout << "Get song by index: " << p.getSong(0) << endl;
    cout << "Get song by title and artist: " << p.getSong("", "") << endl << endl;

    cout << "Setters" << endl;
    p.setTitle("This is a Title");
    cout << "Title: " << p.getTitle() << endl;
    p.addSong(s1);
    cout << "Added one song" << endl;
    cout << "Playlist Duration: " << p.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << p.getNumSongs() << endl;
    cout << "Get song by index: " << p.getSong(0) << endl;
    Song s2;
    s2.setTitle("Song 2");
    s2.setArtist("Someone Else");
    s2.setDuration(4.0);
    p.addSong(s2);
    cout << "Added one song" << endl;
    cout << "Playlist Duration: " << p.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << p.getNumSongs() << endl;
    cout << "Get song by title and artist: " << p.getSong("Song 2", "Someone Else") << endl << endl;

    cout << "Remove Song" << endl;
    p.removeSong(0);
    cout << "Removed song by index" << endl;
    cout << "Playlist Duration: " << p.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << p.getNumSongs() << endl;
    p.removeSong("Song 2", "Someone Else");
    cout << "Removed song by title and artist" << endl;
    cout << "Playlist Duration: " << p.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << p.getNumSongs() << endl << endl;

    cout << "Overloaded Operators" << endl;
    Song s3;
    s3.setTitle("Song 2");
    s3.setArtist("Someone");
    s3.setDuration(3.0);
    p.addSong(s3);
    Song s4;
    s4.setTitle("Song 3");
    s4.setArtist("Someone Else");
    s4.setDuration(3.25);
    p.addSong(s4);
    cout << "Added two songs" << endl;
    cout << p << endl << endl;


    cout << "Album Object" << endl << endl;
    Album a;

    cout << "Getters" << endl;
    cout << "Title: " << a.getTitle() << endl;
    cout << "Artist: " << a.getArtist() << endl;
    cout << "Year Released: " << a.getYearReleased() << endl;
    cout << "Album Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl;
    cout << "Get song by index: " << a.getSong(0) << endl;
    cout << "Get song by title and artist: " << a.getSong("", "") << endl << endl;

    cout << "Setters" << endl;
    a.setTitle("This is a Title");
    cout << "Title: " << a.getTitle() << endl;
    a.setArtist("Someone");
    cout << "Artist: " << a.getArtist() << endl;
    a.setYearReleased(2022);
    cout << "Year Released: " << a.getYearReleased() << endl;
    a.addSong(s1);
    cout << "Added one song" << endl;
    cout << "Album Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl;
    cout << "Get song by index: " << a.getSong(0) << endl;
    a.addSong(s2);
    cout << "Added one song" << endl;
    cout << "Album Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl;
    cout << "Get song by title and artist: " << a.getSong("Song 2", "Someone Else") << endl;
    a.addSong(s3);
    cout << "Added one song" << endl;
    cout << "Album Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl;
    cout << "Get song by title and artist: " << a.getSong("Song 2", "Someone") << endl << endl;

    cout << "Remove Song" << endl;
    a.removeSong(0);
    cout << "Removed song by index" << endl;
    cout << "Playlist Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl;
    a.removeSong("Song 2", "Someone");
    cout << "Removed song by title and artist" << endl;
    cout << "Playlist Duration: " << a.getDuration() << " minutes" << endl;
    cout << "Number of songs: " << a.getNumSongs() << endl << endl;

    cout << "Overloaded Operators" << endl;
    a.setArtist("Someone Else");
    cout << "Set album artist to 'Someone Else'" << endl;
    a.addSong(s2);
    a.addSong(s4);
    cout << "Added two songs" << endl;
    cout << a << endl;

    return 0;
}
