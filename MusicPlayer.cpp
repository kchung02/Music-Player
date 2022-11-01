#include "MusicPlayer.h"
#include "Playlist.h"
#include "Song.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void MusicPlayer::readAlbumFromFile(string filename) {
    // Open the file
    ifstream inFile("../" + filename);

    // Read in the number of albums
    int numAlbums = 0;
    string newline;
    if (inFile) {
        inFile >> numAlbums;
        getline(inFile, newline);
    }

    // Read in the questions
    int currAlbum = 0;
    Album a;
    Song s;
    string title = "";
    string artist = "";
    int year = 0;
    int number = 0;
    double duration = 0.0;
    while (inFile && currAlbum < numAlbums) {
        // Reset album duration
        a.setDuration(0.0);

        // Album title
        getline(inFile, title);
        a.setTitle(title);

        // Album artist
        getline(inFile, artist);
        a.setArtist(artist);

        // Year album was released
        inFile >> year;
        a.setYearReleased(year);

        // Clear Songs
        a.clearSongs();

        // Number of songs
        inFile >> number;
        getline(inFile, newline);

        // Songs
        for (int i = 0; i < number; ++i) {
            // Read title
            getline(inFile, title);
            s.setTitle(title);
            // Read artist
            getline(inFile, artist);
            s.setArtist(artist);
            // Read duration
            inFile >> duration;
            s.setDuration(duration);
            getline(inFile, newline);
            // Add answer to question
            a.addSong(s);
        }

        // Add the Album to vector field
        musicLibrary.push_back(a);

        // Increment album number
        ++currAlbum;
    }
    inFile.close();
}

MusicPlayer::MusicPlayer(string filename) : play(false), currentSong(Song()) {
    musicLibrary.clear();
    readAlbumFromFile(filename);
    queue.clear();
    playlists.clear();
}

Song MusicPlayer::getCurrentSong() const {
    return currentSong;
}

bool MusicPlayer::getPlay() const {
    return play;
}

Song MusicPlayer::getSongFromLibrary(string title, string artist) const {
    for (Album a : musicLibrary) {
        for (Song s : a.getSongs()) {
            if (s.getTitle() == title && s.getArtist() == artist) {
                return s;
            }
        }
    }
}

Song MusicPlayer::getSongFromQueue(int index) const {
    if (index >= 0 && index < queue.size()) {
        return queue[index];
    }
}

int MusicPlayer::getNumSongs() const {
    return queue.size();
}

int MusicPlayer::getNumPlaylists() const {
    return playlists.size();
}

optional<Playlist> MusicPlayer::getPlaylist(int index) const {
    if (index < 0 || index >= playlists.size()) {
        return nullopt;
    }
    else {
        return playlists[index];
    }
}

optional<Playlist> MusicPlayer::getPlaylist(string title) const {
    for (Playlist p : playlists) {
        if (p.getTitle() == title) {
            return p;
        }
    }
    return nullopt;
}

void MusicPlayer::setCurrentSong(Song currentSong) {
    this->currentSong = currentSong;
}

void MusicPlayer::setPlay(bool play) {
    this->play = play;
}

void MusicPlayer::addSongToQueue(Song newSong) {
    queue.push_back(newSong);
}

void MusicPlayer::addSongToPlaylist(Song s, optional<Playlist> p) {
    p->addSong(s);
}

bool MusicPlayer::removeSong(int index) {
    if (index < 0 || index >= queue.size()) {
        return false;
    }
    queue.erase(queue.begin() + index);
    return true;
}

void MusicPlayer::addPlaylist(Playlist newPlaylist) {
    playlists.push_back(newPlaylist);
}

bool MusicPlayer::removePlaylist(int index) {
    if (index < 0 || index >= playlists.size()) {
        return false;
    }
    playlists.erase(playlists.begin() + index);
    return true;
}

bool MusicPlayer::removePlaylist(string title) {
    bool removed = false;
    for (int i = 0; i < playlists.size(); ++i) {
        if (playlists[i].getTitle() == title) {
            playlists.erase(playlists.begin() + i);
            --i;
            removed = true;
        }
    }
    return removed;
}

void MusicPlayer::printMusicLibrary() {
    cout << "Music Library" << endl;
    for (Album a : musicLibrary) {
        cout << a << endl;
    }
}

void MusicPlayer::printQueue() {
    cout << "Queue" << endl;
    if (queue.empty()) {
        cout << endl;
    }
    else {
        for (Song s : queue) {
            cout << s << endl;
        }
    }
    cout << endl;
}

void MusicPlayer::printPlaylists() {
    cout << "My Playlists" << endl;
    if (playlists.empty()) {
        cout << endl;
    }
    else {
        for (Playlist p : playlists) {
            cout << p << endl;
        }
    }
}

bool MusicPlayer::isInLibrary(string title, string artist) {
    for (Album a : musicLibrary) {
        for (Song s : a.getSongs()) {
            if (s.getTitle() == title && s.getArtist() == artist) {
                return true;
            }
        }
    }
    return false;
}

bool MusicPlayer::isInPlaylists(string title) {
    for (Playlist p : playlists) {
        if (p.getTitle() == title) {
            return true;
        }
    }
    return false;
}

//Song MusicPlayer::next() {
//
//}
//
//Song MusicPlayer::previous() {
//
//}
//
//bool MusicPlayer::shuffle() {
//
//}
//
//bool MusicPlayer::repeat() {
//
//}
//
//bool MusicPlayer::repeatOne() {
//
//}
