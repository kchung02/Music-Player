#ifndef M2OEP_KKCHUNG_PLAYLIST_H
#define M2OEP_KKCHUNG_PLAYLIST_H

#include "Song.h"
#include <iostream>
#include <vector>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

class Playlist {
protected:
    string title;
    double duration;
    vector<Song> songs;

public:
    /* Constructor */
    Playlist();

    /* Getters */
    string getTitle() const;
    double getDuration() const;
    int getNumSongs() const;
    optional<Song> getSong(int index) const;
    optional<Song> getSong(string title, string artist) const;
    vector<Song> getSongs();

    /* Setters */
    void setTitle(string title);
    void setDuration(double duration);

    /* Add Song to Playlist */
    bool addSong(Song newSong);

    /* Remove Song by index or title and artist */
    bool removeSong(int index);
    bool removeSong(string title, string artist);

    /* Removes all Songs */
    void clearSongs();

    /* Overloaded Output Operator */
    friend ostream& operator << (ostream& outs, const Playlist& p);
    friend ostream& operator << (ostream& outs, const optional<Playlist>& p);

};

#endif //M2OEP_KKCHUNG_PLAYLIST_H
