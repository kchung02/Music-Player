#ifndef M2OEP_KKCHUNG_MUSICPLAYER_H
#define M2OEP_KKCHUNG_MUSICPLAYER_H

#include "Playlist.h"
#include "Song.h"
#include "Album.h"
#include <iostream>
using namespace std;

class MusicPlayer {
private:
    bool play;
    Song currentSong;
    vector<Album> musicLibrary;
    vector<Song> queue;
    vector<Playlist> playlists;

    /* Helper function to read Album data from a file */
    void readAlbumFromFile(string filename);

public:
    /* Constructor */
    explicit MusicPlayer(string filename);

    /* Getters */
    Song getCurrentSong() const;
    bool getPlay() const;
    Song getSongFromLibrary(string title, string artist) const;
    Song getSongFromQueue(int index) const;
    int getNumSongs() const;
    int getNumPlaylists() const;
    optional<Playlist> getPlaylist(int index) const;
    optional<Playlist> getPlaylist(string title) const;

    /* Setters */
    void setCurrentSong(Song currentSong);
    void setPlay(bool play);

    /* Add Song to queue */
    void addSongToQueue(Song s);

    /* Add Song to playlist */
    void addSongToPlaylist(Song s, optional<Playlist> p);

    /* Remove Song from queue by index */
    bool removeSong(int index);

    /* Adds playlist to playlists */
    void addPlaylist(Playlist p);

    /* Remove Playlist from playlists by index or title*/
    bool removePlaylist(int index);
    bool removePlaylist(string title);

    /* Print Music Library */
    void printMusicLibrary();

    /* Print Music Library */
    void printQueue();

    /* Print playlists */
    void printPlaylists();

    /* Check if song is in library */
    bool isInLibrary(string title, string artist);

    /* Check if Playlist is in playlists */
    bool isInPlaylists(string title);

//    Song next();
//    Song previous();
//    bool shuffle();
//    bool repeat();
//    bool repeatOne();

};

#endif //M2OEP_KKCHUNG_MUSICPLAYER_H
