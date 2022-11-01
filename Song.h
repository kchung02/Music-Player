#ifndef M2OEP_KKCHUNG_SONG_H
#define M2OEP_KKCHUNG_SONG_H

#include <iostream>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

class Song {
private:
    string title;
    string artist;
    double duration;

public:
    /* Constructor */
    Song();

    /* Getters */
    string getTitle() const;
    string getArtist() const;
    double getDuration() const;

    /* Setters */
    void setTitle(string title);
    void setArtist(string artist);
    void setDuration(double duration);

    /* Overloaded Output Operator */
    friend ostream& operator << (ostream& outs, const Song& s);
    friend ostream& operator << (ostream& outs, const optional<Song>& s);

};

#endif //M2OEP_KKCHUNG_SONG_H
