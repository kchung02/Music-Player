#ifndef M2OEP_KKCHUNG_ALBUM_H
#define M2OEP_KKCHUNG_ALBUM_H

#include "Playlist.h"
#include <iostream>
#include <optional>
using namespace std;
using std::optional;
using std::nullopt;

class Album : public Playlist {
private:
    string artist;
    int yearReleased;

public:
    /* Constructor */
    Album();

    /* Getters */
    string getArtist() const;
    int getYearReleased() const;

    /* Add Song to Album */
    bool addSong(Song newSong);

    /* Setters */
    void setArtist(string artist);
    void setYearReleased(int yearReleased);

    /* Overloaded Output Operator */
    friend ostream& operator << (ostream& outs, const Album& a);

};

#endif //M2OEP_KKCHUNG_ALBUM_H
