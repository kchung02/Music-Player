#include "MusicPlayer.h"
#include <iostream>
#include <iomanip>
//#include <Time.h>
using namespace std;

int main() {
    cout << setprecision(2) << fixed;
    // srand(time(0));

    // create music player
    MusicPlayer m = MusicPlayer("AlbumData.txt");
    cout << "Welcome to Music Player" << endl << endl;

    bool exit = false;
    while (!exit) {
        // song is not playing or is paused
        if (!m.getPlay()) {
            // print options and get user input
            // if queue is empty and there are no playlists
            if (m.getNumSongs() == 0 && m.getNumPlaylists() == 0) {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Exit" << endl;
            }
            // if the queue is empty but there is at least one playlist
            else if (m.getNumSongs() == 0) {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Add to Playlist" << endl;
                cout << "Exit" << endl;
            }
            // if the queue is not empty but there are no playlists
            else if (m.getNumPlaylists() == 0) {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Play" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Exit" << endl;
            }
            // if the queue is not empty and there is at least one playlist
            else {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Play" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Add to Playlist" << endl;
                cout << "Exit" << endl;
            }
            cout << "Enter a command: ";
            string input;
            getline(cin, input);
            for (char& c : input) {
                c = tolower(c);
            }
            // input validation
            // if the queue is empty and there are no playlists
            if (m.getNumSongs() == 0 && m.getNumPlaylists() == 0) {
                while (input != "search library"
                    && input != "search queue"
                    && input != "search playlists"
                    && input != "change song"
                    && input != "add to queue"
                    && input != "make playlist"
                    && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // if the queue is empty and there is at least one playlist
            else if (m.getNumSongs() == 0) {
                while (input != "search library"
                       && input != "search queue"
                       && input != "search playlists"
                       && input != "change song"
                       && input != "add to queue"
                       && input != "make playlist"
                       && input != "add to playlist"
                       && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // if the queue is not empty and there are no playlists
            else if (m.getNumPlaylists() == 0) {
                while (input != "search library"
                       && input != "search queue"
                       && input != "search playlists"
                       && input != "play"
                       && input != "change song"
                       && input != "add to queue"
                       && input != "make playlist"
                       && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // if the queue is not empty and there is at least one playlist
            else {
                while (input != "search library"
                    && input != "search queue"
                    && input != "search playlists"
                    && input != "play"
                    && input != "change song"
                    && input != "add to queue"
                    && input != "make playlist"
                    && input != "add to playlist"
                    && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // search library prints the music library
            if (input == "search library") {
                cout << endl;
                m.printMusicLibrary();
            }
            // search queue prints the queue
            else if (input == "search queue") {
                cout << endl;
                m.printQueue();
            }
            // search playlists prints all playlists made
            else if (input == "search playlists") {
                cout << endl;
                m.printPlaylists();
            }
            // play current continues the current song
            else if (input == "play") {
                m.setCurrentSong(m.getSongFromQueue(0));
                m.setPlay(true);
                cout << endl;
                cout << "Playing: " << m.getCurrentSong() << endl << endl;
            }
            // play different plays a different song
            else if (input == "change song") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // checks if song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // checks if song is already playing
                    // song is not already playing
                    if (m.getSongFromLibrary(title, artist).getTitle() != m.getCurrentSong().getTitle()
                        && m.getSongFromLibrary(title, artist).getArtist() != m.getCurrentSong().getArtist()) {
                        // add song to queue
                        m.addSongToQueue(m.getSongFromLibrary(title, artist));
                        // change current song to new song
                        m.setCurrentSong(m.getSongFromLibrary(title, artist));
                        // set play to true
                        m.setPlay(true);
                        // print new current song
                        cout << endl;
                        cout << "Playing: " << m.getCurrentSong() << endl << endl;
                    }
                    else {
                        // song is already playing
                        cout << endl;
                        cout << "Song is already playing." << endl << endl;
                    }
                }
                // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // add to queue adds a song to the queue
            else if (input == "add to queue") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // checks if song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // add song to queue
                    m.addSongToQueue(m.getSongFromLibrary(title, artist));
                    // print added song
                    cout << endl;
                    cout << "Added " << m.getSongFromLibrary(title, artist).getTitle();
                    cout << " by " << m.getSongFromLibrary(title, artist).getArtist();
                    cout << " to queue" << endl << endl;
                }
                // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // make playlist creates a playlist and adds it to playlists
            else if (input == "make playlist") {
                // make playlist
                Playlist p;
                // user input for playlist title
                cout << "Playlist Name: ";
                string name;
                getline(cin, name);
                // check if there is already a playlist with that title
                while (m.getPlaylist(name) != nullopt) {
                    cout << "Name is taken. Playlist Name: ";
                    getline(cin, name);
                }
                // if title is empty, set title to 'My Playlist #' + playlist number
                if (name.length() == 0) {
                    p.setTitle("My Playlist #" + to_string(m.getNumPlaylists()+1));
                }
                // title is valid
                else {
                    p.setTitle(name);
                }
                // add playlist to playlists
                m.addPlaylist(p);
                // print the new playlist
                cout << endl;
                cout << "New playlist made:" << endl;
                cout << p << endl;
            }
            // add to playlist adds a song to specified playlist
            else if (input == "add to playlist") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // check is song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // user input for what playlist
                    cout << "Playlist Name: ";
                    string name;
                    getline(cin, name);
                    // check if playlist exists
                    // playlists exists
                    if (m.isInPlaylists(name)) {
                        m.addSongToPlaylist(m.getSongFromLibrary(title, artist), m.getPlaylist(name));
                        cout << endl;
                        cout << "Added " << m.getSongFromLibrary(title, artist).getTitle();
                        cout << " by " << m.getSongFromLibrary(title, artist).getArtist();
                        cout << " to " << m.getPlaylist(name)->getTitle() << endl << endl;
                    }
                    // playlist does not exist
                    else {
                        cout << endl;
                        cout << "Playlist not found." << endl << endl;
                    }
                }
                // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // exit ends the music player
            else {
                exit = true;
                cout << endl;
                cout << "Exiting Music Player" << endl;
            }
        }

        // song is playing
        else {
            // print options and get user input
            // if there are no playlists
            if (m.getNumPlaylists() == 0) {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Pause" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Exit" << endl;
            }
            // if there is at least one playlist
            else {
                cout << "Search Library" << endl;
                cout << "Search Queue" << endl;
                cout << "Search Playlists" << endl;
                cout << "Pause" << endl;
                cout << "Change Song" << endl;
                cout << "Add to Queue" << endl;
                cout << "Make Playlist" << endl;
                cout << "Add to Playlist" << endl;
                cout << "Exit" << endl;
            }
            cout << "Enter a command: ";
            string input;
            getline(cin, input);
            for (char& c : input) {
                c = tolower(c);
            }
            // input validation
            // if there are no playlists
            if (m.getNumPlaylists() == 0) {
                while (input != "search library"
                       && input != "search queue"
                       && input != "search playlists"
                       && input != "pause"
                       && input != "change song"
                       && input != "add to queue"
                       && input != "make playlist"
                       && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // if there is at least one playlist
            else {
                while (input != "search library"
                       && input != "search queue"
                       && input != "search playlists"
                       && input != "pause"
                       && input != "change song"
                       && input != "add to queue"
                       && input != "make playlist"
                       && input != "add to playlist"
                       && input != "exit") {
                    cout << "Invalid input. Enter a command: ";
                    getline(cin, input);
                }
            }
            // search library prints the music library
            if (input == "search library") {
                cout << endl;
                m.printMusicLibrary();
            }
            // search queue prints the queue
            else if (input == "search queue") {
                cout << endl;
                m.printQueue();
            }
            // search playlists prints all playlists made
            else if (input == "search playlists") {
                cout << endl;
                m.printPlaylists();
            }
            // plays a song
            else if (input == "change song") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // checks if song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // checks if song is already playing
                    // song is not already playing
                    if (m.getSongFromLibrary(title, artist).getTitle() != m.getCurrentSong().getTitle()
                        && m.getSongFromLibrary(title, artist).getArtist() != m.getCurrentSong().getArtist()) {
                        // add song to queue
                        m.addSongToQueue(m.getSongFromLibrary(title, artist));
                        // change current song to new song
                        m.setCurrentSong(m.getSongFromLibrary(title, artist));
                        // set play to true
                        m.setPlay(true);
                        // print new current song
                        cout << endl;
                        cout << "Playing: " << m.getCurrentSong() << endl << endl;
                    }
                    else {
                        // song is already playing
                        cout << endl;
                        cout << "Song is already playing." << endl << endl;
                    }
                }
                // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // pause sets play to false and pauses the current song
            else if (input == "pause") {
                m.setPlay(false);
                cout << endl;
                cout << "Paused: " << m.getCurrentSong() << endl << endl;
            }
            // add to queue adds a song to the queue
            else if (input == "add to queue") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // checks if song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // add song to queue
                    m.addSongToQueue(m.getSongFromLibrary(title, artist));
                    // print added song
                    cout << endl;
                    cout << "Added " << m.getSongFromLibrary(title, artist).getTitle();
                    cout << " by " << m.getSongFromLibrary(title, artist).getArtist();
                    cout << " to queue" << endl << endl;
                }
                // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // make playlist creates a playlist and adds it to playlists
            else if (input == "make playlist") {
                // make playlist
                Playlist p;
                // user input for playlist title
                cout << "Playlist Name: ";
                string title;
                getline(cin, title);
                // check if there is already a playlist with that title
                while (m.getPlaylist(title) != nullopt) {
                    cout << "Name is taken. Playlist Name: ";
                    getline(cin, title);
                }
                // if title is empty, set title to 'My Playlist #' + playlist number
                if (title.length() == 0) {
                    p.setTitle("My Playlist #" + to_string(m.getNumPlaylists()+1));
                }
                // title is valid
                else {
                    p.setTitle(title);
                }
                // add playlist to playlists
                m.addPlaylist(p);
                // print the new playlist
                cout << endl;
                cout << "New playlist made:" << endl;
                cout << p << endl;
            }
            // add to playlist adds a song to specified playlist
            else if (input == "add to playlist") {
                // user input for what song
                cout << "Title: ";
                string title;
                getline(cin, title);
                cout << "Artist: ";
                string artist;
                getline(cin, artist);
                // check is song is in library
                // song is in library
                if (m.isInLibrary(title, artist)) {
                    // user input for what playlist
                    cout << "Playlist Name: ";
                    string name;
                    getline(cin, name);
                    // check if playlist exists
                    // playlists exists
                    if (m.isInPlaylists(name)) {
                        m.addSongToPlaylist(m.getSongFromLibrary(title, artist), m.getPlaylist(name));
                        cout << endl;
                        cout << "Added " << m.getSongFromLibrary(title, artist).getTitle();
                        cout << " by " << m.getSongFromLibrary(title, artist).getArtist();
                        cout << " to " << m.getPlaylist(name)->getTitle() << endl << endl;
                    }
                        // playlist does not exist
                    else {
                        cout << endl;
                        cout << "Playlist not found." << endl << endl;
                    }
                }
                    // song is not in library
                else {
                    cout << endl;
                    cout << "Song not found." << endl << endl;
                }
            }
            // exit ends the music player
            else {
                exit = true;
                cout << endl;
                cout << "Exiting Music Player" << endl;
            }
        }
    }

    return 0;
}
