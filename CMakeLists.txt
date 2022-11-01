cmake_minimum_required(VERSION 3.21)
project(M2OEP_kkchung)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp MusicPlayer.h MusicPlayer.cpp Playlist.h Playlist.cpp Album.h Album.cpp Song.h Song.cpp)

add_executable(test testing.cpp MusicPlayer.h MusicPlayer.cpp Playlist.h Playlist.cpp Album.h Album.cpp Song.h Song.cpp)