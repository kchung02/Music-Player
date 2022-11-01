#include "Song.h"
#include <iostream>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

Song::Song() : title(""), artist(""), duration(0.0) {

}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

double Song::getDuration() const {
    return duration;
}

void Song::setTitle(string title) {
    this->title = title;
}

void Song::setArtist(string artist) {
    this->artist = artist;
}

void Song::setDuration(double duration) {
    this->duration = duration;
}

ostream& operator << (ostream& outs, const Song& s) {
    if (s.title == "" || s.artist == "" || s.duration == 0.0) {
        outs << "";
    }
    else {
        outs << s.title << " by " << s.artist << " " << s.duration << " minutes";
    }
    return outs;
}

ostream& operator << (ostream& outs, const optional<Song>& s) {
    if (s == nullopt || s->title == "" || s->artist == "" || s->duration == 0.0) {
        outs << "";
    }
    else {
        outs << s->title << " by " << s->artist << " " << s->duration << " minutes";
    }
    return outs;
}
