//
// Created by Kurt Burdick on 12/3/19.
//

#ifndef COMP220_TERMPROJECT_USERINTERFACE_H
#define COMP220_TERMPROJECT_USERINTERFACE_H

#include <string>
#include "MusicLibrary.h"
#include "Playlist.h"

/**
 * provides a summary of all available commands
 * @post prints all possible commands to the console
 */
void help();

/**
 * displays all songs in alphabetical order by artist
 * (within artist alphabetical by song)
 * @param musicLibraryIn
 * @post prints all songs in order to console
 */
void library(MusicLibrary* musicLibraryIn);

/**
 * display all songs for a given artist
 * @param artistIn
 * @param musicLibraryIn
 * @post prints all songs for that artist to console
 */
void artist(std::string artistIn, MusicLibrary* musicLibraryIn);


/**
 * display all information for a given song
 * @param songIn
 * @post prints all song info to the console
 */
void songInfo(std::string artistIn, std::string titleIn, MusicLibrary* musicLibraryIn);

/**
 * add all songs from the given file to the library
 * @param fileNameIn
 * @post new songs are in the library file
 * @return print songs that already existed (to avoid duplicates)
 */
MusicLibrary* import(std::string fileNameIn, MusicLibrary* musicLibrary);

/**
 * remove all songs in a given file from the library
 * Also remove songs that occur in any playlist
 * @param fileNameIn
 * @post songs are removed from library and any playlists that they occur in
 * @return print songs that could not be removed
 */
void discontinue(std::string fileNameIn, MusicLibrary* musicLibraryIn);

/**
 * display the names of all playlists and their duration
 * @post prints all playlists with respective duration to the console
 */
void playlists(Playlist* listOfPlaylistsIn);

/**
 * display all songs left in a given playlist
 * @param playlistIn
 * @post print songs in playlist to console
 */
void playlist(Playlist* listOfPlaylistsIn, std::string playlistIn);

/**
 * make a new empty playlist with the given name
 * @param playlistNameIn desired name for the playlist
 * @post a new empty playlist is created and saved
 */
Playlist* newPlaylist(Playlist* listOfPlaylistsIn, std::string nameIn);

/**
 * add the given song to the end of of the playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 * @param duration length of the song in seconds
 */
 std::string add(std::string nameIn, std::string artistIn, std::string titleIn, int duration, Playlist* listOfPlaylistsIn);

/**
 * remove the given song from the requested playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 */
 void remove(std::string nameIn, std::string artistIn, std::string titleIn, Playlist* listOfPlaylistsIn);

/**
 * plays the next song in the playlist and removes it
 * (if playlist is empty remove that too)
 * @param playlistIn
 * @post print to console all song information
 */
void playNext(Playlist* listOfPlaylistsIn, std::string nameIn, MusicLibrary* musicLibrary);

/**
 * makes a new playlist that does not exceed requested duration
 * songs are in shuffled order and do not repeat
 * @param playlistNameIn
 * @param maxDurationIn
 */
void newRandom(std::string playlistNameIn, int maxDurationIn, Playlist* listOfPlayListsIn, MusicLibrary* musicLibraryIn);

/**
 * saves (writes out files) all playlists and library
 * @param playlistArray
 * @param musicLibraryIn
 */
void quit(Playlist* listOfPlaylistsIn, MusicLibrary* musicLibraryIn, std::string fileNameIn);



#endif //COMP220_TERMPROJECT_USERINTERFACE_H
