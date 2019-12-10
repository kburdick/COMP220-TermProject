//
// Created by Kurt Burdick on 12/3/19.
//

#include <iostream>
#include "UserInterface.h"

//TODO DEFINE ALL FUNCTIONS IN THIS FILE TO WORK WITH THE INTERFACED CLASSES

/**
 * provides a summary of all available commands
 * @post prints all possible commands to the console
 */
void help(){
    std::cout << "\n####################" << std::endl;
    std::cout << "### Command Keys ###" << std::endl;
    std::cout << "####################\n" << std::endl;

    std::cout << "A list of available commands with syntax: " << std::endl;
    std::cout << "(NOTE: enter desired functionality in brackets, ex: artist<The Beatles>)\n" << std::endl;

    std::cout << " Command: " << "     " << "\t\t\t\t\tDescription: \n" << std::endl;

    std::cout << " 'help' " << "\t\t\t\t\t\t-Provides a summary of all available commands\n" << std::endl;

    std::cout << " 'library' " << "\t\t\t\t\t\t-Display all the songs in the current music library\n" << std::endl;

    std::cout << " 'artist<artist>' " << "\t\t\t\t-Display all songs for the given artist\n" << std::endl;

    std::cout << " 'song'<artist, title>' " << "\t\t-Display all the information for a given song\n" << std::endl;

    std::cout << " 'import<filename>' " << "\t\t\t-Add songs from a given file to the library\n" << std::endl;

    std::cout << " 'discontinue<filename>' " << "\t\t-Remove songs from the library in a given file\n" << std::endl;

    std::cout << " 'playlists' " << "\t\t\t\t\t-Display the names of all the playlists and their durations\n" << std::endl;

    std::cout << " 'playlist<name>' " << "\t\t\t\t-Display songs left in the playlist, and remaining playtime\n" << std::endl;

    std::cout << " 'new<name>' " << "\t\t\t\t\t-Make a new empty playlist with the given name\n" << std::endl;

    std::cout << " 'add<name, artist, title>' " << "\t-Add the given song to the desired playlist\n" << std::endl;

    std::cout << " 'remove<name, artist, title>' " << "\t-Remove the given song from the desired playlist\n" << std::endl;

    std::cout << " 'playnext<name>' " << "\t\t\t\t-Play the next song in the playlist, and display that songs information\n" << std::endl;

    std::cout << " 'newrandom<name, duration>' " << "\t-Make a new random playlist with a given name, and duration limit\n" << std::endl;

    std::cout << " 'quit' " << "\t\t\t\t\t\t-Save the library, all playlists, and terminate program execution\n" << std::endl;

    std::cout << "####################\n" << std::endl;
}

/**
 * displays all songs in alphabetical order by artist
 * (within artist alphabetical by song)
 * @post prints all songs in order to console
 */
void library(){
    //TODO make calls to display (toString) all library music in alphabetical order (sort while importing

}

/**
 * display all songs for a given artist
 * @param artistIn
 * @post prints all songs for that artist to console
 */
void artist(std::string artistIn){
    //TODO make calls to display all songs for the given artist
    //(find and toString on all objects with that artist) findByArtist function?

}


/**
 * display all information for a given song
 * @param songIn
 * @post prints all song info to the console
 */
void songInfo(std::string songIn, std::string titleIn){
    //TODO make calls to display all song info (find and toString on that object)

}

/**
 * add all songs from the given file to the library
 * @param fileNameIn
 * @post new songs are in the library file
 * @return print songs that already existed (to avoid duplicates)
 */
std::string import(std::string fileNameIn){
    //TODO make call to fileIO functions to create a new library that holds the songs from the file
    //readIn function (automatically add to library)

}

/**
 * remove all songs in a given file from the library
 * Also remove songs that occur in any playlist
 * @param fileNameIn
 * @post songs are removed from library and any playlists that they occur in
 * @return print songs that could not be removed
 */
std::string discontinue(std::string fileNameIn){
    //TODO make calls to fileIO functions to remove all songs in the library from the list


}

/**
 * display the names of all playlists and their duration
 * @post prints all playlists with respective duration to the console
 */
void playlists(){
    //TODO makes calls to have a toString method that prints the names of all current linked list based playlists

}

/**
 * display all songs left in a given playlist
 * @param playlistIn
 * @post print songs in playlist to console
 */
void playlist(std::string playlistIn){
    //TODO make calls to display (toString again) all songs in a playlist

}

/**
 * make a new empty playlist with the given name
 * @param playlistNameIn desired name for the playlist
 * @post a new empty playlist is created and saved
 */
void newPlaylist(std::string playlistNameIn){
    //TODO make calls to create a new playlist
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
    //TODO make calls to add song to proper linked list
}

/**
 * remove the given song from the requested playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 */
//TODO do we need to check if song does not exist?
void remove(std::string nameIn, std::string artistIn, std::string titleIn){
    //TODO make calls to remove song from proper linked list

}

/**
 * plays the next song in the playlist and removes it
 * (if playlist is empty remove that too)
 * @param playlistIn
 * @post print to console all song information
 */
void playNext(std::string playlistIn){
    //TODO make calls to play song and display it to the screen

}

/**
 * makes a new playlist that does not exceed requested duration
 * songs are in shuffled order and do not repeat
 * @param playlistNameIn
 * @param maxDurationIn
 */
void newRandom(std::string playlistNameIn, int maxDurationIn){
    //TODO make calls to random playlist generation functions

}

/**
 * save the library and the playlist files
 * (write output to text files)
 * @post terminate execution of the program.
 */
void quit(){

    //TODO make calls to save/write out files here?

    std::cout << "\nSaving files and exiting...\n" << std::endl;

}
