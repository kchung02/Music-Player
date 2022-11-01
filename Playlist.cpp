#include "Playlist.h"
#include <iostream>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

Playlist::Playlist() : title(""), duration(0.0) {
    songs.clear();
}

string Playlist::getTitle() const {
    return title;
}

double Playlist::getDuration() const{
    return duration;
}

int Playlist::getNumSongs() const {
    return songs.size();
}

optional<Song> Playlist::getSong(int index) const {
    if (index < 0 || index >= songs.size()) {
        return nullopt;
    }
    else {
        return songs[index];
    }
}

optional<Song> Playlist::getSong(string title, string artist) const {
    for (Song s : songs) {
        if (s.getTitle() == title && s.getArtist() == artist) {
            return s;
        }
    }
    return nullopt;
}

vector<Song> Playlist::getSongs() {
    return songs;
}

void Playlist::setTitle(string title) {
    this->title = title;
}

void Playlist::setDuration(double duration) {
    this->duration = duration;
}

bool Playlist::addSong(Song newSong) {
    for (Song s : songs) {
        if (newSong.getTitle() == s.getTitle() && newSong.getArtist() == s.getArtist()) {
            return false;
        }
    }
    songs.push_back(newSong);
    duration += newSong.getDuration();
    return true;
}

bool Playlist::removeSong(int index) {
    if (index < 0 || index >= songs.size()) {
        return false;
    }
    duration -= songs[index].getDuration();
    songs.erase(songs.begin() + index);
    return true;
}

bool Playlist::removeSong(string title, string artist) {
    bool removed = false;
    for (int i = 0; i < songs.size(); ++i) {
        if (songs[i].getTitle() == title && songs[i].getArtist() == artist) {
            duration -= songs[i].getDuration();
            songs.erase(songs.begin() + i);
            --i;
            removed = true;
        }
    }
    return removed;
}

void Playlist::clearSongs() {
    songs.clear();
}

ostream& operator << (ostream& outs, const Playlist& p) {
    outs << p.title << endl;
    outs << p.getNumSongs() << " songs, " << p.duration << " minutes" << endl;
    for (Song s : p.songs) {
        outs << s << endl;
    }
    return outs;
}

ostream& operator << (ostream& outs, const optional<Playlist>& p) {
    if (p == nullopt) {
        outs << "";
    }
    else {
        outs << p->title << endl;
        outs << p->getNumSongs() << " songs, " << p->duration << " minutes" << endl;
        for (Song s : p->songs) {
            outs << s << endl;
        }
    }
    return outs;
}
