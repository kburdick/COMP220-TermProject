//
// Created by Kurt Burdick on 12/3/19.
//

#include <string>

//TODO DEFINE ALL FUNCTIONS IN THIS FILE TO WORK WITH THE INTERFACE

/**
 * provides a summary of all available commands
 * @post prints all possible commands to the console
 */
void help(){

}

/**
 * displays all songs in alphabetical order by artist
 * (within artist alphabetical by song)
 * @post prints all songs in order to console
 */
void library(){

}

/**
 * display all songs for a given artist
 * @param artistIn
 * @post prints all songs for that artist to console
 */
void artist(std::string artistIn){

}


/**
 * display all information for a given song
 * @param songIn
 * @post prints all song info to the console
 */
void songInfo(std::string songIn, std::string titleIn){

}

/**
 * add all songs from the given file to the library
 * @param fileNameIn
 * @post new songs are in the library file
 * @return print songs that already existed (to avoid duplicates)
 */
std::string import(std::string fileNameIn){

}

/**
 * remove all songs in a given file from the library
 * Also remove songs that occur in any playlist
 * @param fileNameIn
 * @post songs are removed from library and any playlists that they occur in
 * @return print songs that could not be removed
 */
std::string discontinue(std::string fileNameIn){

}

/**
 * display the names of all playlists and their duration
 * @post prints all playlists with respective duration to the console
 */
void playlists(){

}

/**
 * display all songs left in a given playlist
 * @param playlistIn
 * @post print songs in playlist to console
 */
void playlist(std::string playlistIn){

}

/**
 * make a new empty playlist with the given name
 * @param playlistNameIn desired name for the playlist
 * @post a new empty playlist is created and saved
 */
void newPlaylist(std::string playlistNameIn){

}

/**
 * add the given song to the end of of the playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 * @param duration length of the song in seconds
 */
//TODO do we need to check if song already exists?
void add(std::string nameIn, std::string artistIn, std::string titleIn, int duration){

}

/**
 * remove the given song from the requested playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 */
//TODO do we need to check if song does not exist?
void remove(std::string nameIn, std::string artistIn, std::string titleIn){

}

/**
 * plays the next song in the playlist and removes it
 * (if playlist is empty remove that too)
 * @param playlistIn
 * @post print to console all song information
 */
void playNext(std::string playlistIn){

}

/**
 * makes a new playlist that does not exceed requested duration
 * songs are in shuffled order and do not repeat
 * @param playlistNameIn
 * @param maxDurationIn
 */
void newRandom(std::string playlistNameIn, int maxDurationIn){

}

/**
 * save the library and the playlist files
 * (write output to text files)
 * @post terminate execution of the program.
 */
void quit(){

}
