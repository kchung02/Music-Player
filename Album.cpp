#include "Album.h"
#include <iostream>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

Album::Album() : Playlist(), artist(""), yearReleased(0) {

}

string Album::getArtist() const {
    return artist;
}

int Album::getYearReleased() const {
    return yearReleased;
}

bool Album::addSong(Song newSong) {
    if (newSong.getArtist() != artist) {
        return false;
    }
    for (Song s : songs) {
        if (newSong.getTitle() == s.getTitle()) {
            return false;
        }
    }
    songs.push_back(newSong);
    duration += newSong.getDuration();
    return true;
}

void Album::setArtist(string artist) {
    this->artist = artist;
}

void Album::setYearReleased(int yearReleased) {
    this->yearReleased = yearReleased;
}

ostream& operator << (ostream& outs, const Album& a) {
    outs << a.title << endl;
    outs << a.artist << " * " << a.yearReleased << " * " << a.getNumSongs() << " songs, " << a.duration << " minutes" << endl;
    for (Song s : a.songs) {
        outs << s << endl;
    }
    return outs;
}
