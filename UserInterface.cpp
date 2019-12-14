//
// Created by Kurt Burdick on 12/3/19.
//

#include <iostream>
#include "UserInterface.h"
#include "MusicLibrary.h"
#include "Playlist.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "FileIO.h"
#include "Song.h"

/**
 * provides a summary of all available commands
 * @post prints all possible commands to the console
 */
void help(){
    std::cout << "\n####################" << std::endl;
    std::cout << "### Command Keys ###" << std::endl;
    std::cout << "####################\n" << std::endl;

    std::cout << "A list of available commands: " << std::endl;
    std::cout << "(NOTE: enter desired functionality in prompt after entering command, ex: artist, Please Enter an Artist: The Beatles)\n" << std::endl;

    std::cout << " Command: " << "     " << "\t\t\t\t\tDescription: \n" << std::endl;

    std::cout << " 'help' " << "\t\t\t\t\t\t-Provides a summary of all available commands\n" << std::endl;

    std::cout << " 'library' " << "\t\t\t\t\t\t-Display all the songs in the current music library\n" << std::endl;

    std::cout << " 'artist'         " << "\t\t\t\t-Display all songs for the given artist\n" << std::endl;

    std::cout << " 'song'                  " << "\t\t-Display all the information for a given song\n" << std::endl;

    std::cout << " 'import'           " << "\t\t\t-Add songs from a given file to the library\n" << std::endl;

    std::cout << " 'discontinue'           " << "\t\t-Remove songs from the library in a given file\n" << std::endl;

    std::cout << " 'playlists' " << "\t\t\t\t\t-Display the names of all the playlists and their durations\n" << std::endl;

    std::cout << " 'playlist'       " << "\t\t\t\t-Display songs left in the playlist, and remaining playtime\n" << std::endl;

    std::cout << " 'new'       " << "\t\t\t\t\t-Make a new empty playlist with the given name\n" << std::endl;

    std::cout << " 'add'                      " << "\t-Add the given song to the desired playlist\n" << std::endl;

    std::cout << " 'remove'                      " << "\t-Remove the given song from the desired playlist\n" << std::endl;

    std::cout << " 'playnext'       " << "\t\t\t\t-Play the next song in the playlist, and display that songs information\n" << std::endl;

    std::cout << " 'newrandom'                 " << "\t-Make a new random playlist with a given name, and duration limit\n" << std::endl;

    std::cout << " 'quit' " << "\t\t\t\t\t\t-Save the library, all playlists, and terminate program execution\n" << std::endl;

    std::cout << "####################\n" << std::endl;
}

/**
 * displays all songs in alphabetical order by artist
 * (within artist alphabetical by song)
 * @post prints all songs in order to console
 */
void library(MusicLibrary* musicLibraryIn){
    musicLibraryIn->displayAllSongs();
}

/**
 * display all songs for a given artist
 * @param artistIn
 * @post prints all songs for that artist to console
 */
void artist(std::string artistIn, MusicLibrary* musicLibraryIn){
    musicLibraryIn->displayArtist(artistIn);
}

/**
 * display all information for a given song
 * @param songIn
 * @post prints all song info to the console
 */
void songInfo(std::string artistIn, std::string titleIn, MusicLibrary* musicLibraryIn){
    //TODO make calls to display all song info (find and toString on that object)
    musicLibraryIn->displaySongInfo(artistIn,titleIn);




    std::string song = musicLibraryIn->displaySongInfo(artistIn, titleIn);
    std::cout << song << std::endl;

}

/**
 * add all songs from the given file to the library
 * @param fileNameIn
 * @post new songs are in the library file
 * @return print songs that already existed (to avoid duplicates)
 */
MusicLibrary* import(std::string fileNameIn, MusicLibrary* musicLibraryIn){
    musicLibraryIn->fileReadIn(fileNameIn);
    return musicLibraryIn;
    //TODO overwrites the text file
}

/**
 * remove all songs in a given file from the library
 * Also remove songs that occur in any playlist
 * @param fileNameIn
 * @post songs are removed from library and any playlists that they occur in
 * print songs that could not be removed aka that do not exist
 */
void discontinue(std::string fileNameIn, MusicLibrary* musicLibraryIn){

    musicLibraryIn->removeSongs(fileNameIn);

}

/**
 * display the names of all playlists and their duration
 * @post prints all playlists with respective duration to the console
 */
void playlists(Playlist* listOfPlaylistsIn){
    //TODO makes calls to have a toString method that prints the names of all current linked list based playlists
    int size = listOfPlaylistsIn->getCurrCount();
    std::string nameOfPlaylist;

    for(int i = 0; i < size; i++) {
        nameOfPlaylist = listOfPlaylistsIn[i].getPlaylistName(i);
        std::cout << nameOfPlaylist << std::endl;
    }
}

/**
 * display all songs left in a given playlist
 * @param playlistIn
 * @post print songs in playlist to console
 */
void playlist(Playlist* listOfPlaylistsIn, std::string nameIn){
    int size = listOfPlaylistsIn->getCurrCount();

    for(int i = 0; i < size; i++){

        if(listOfPlaylistsIn->getPlaylistName(i) == nameIn){
            LinkedList* temp = listOfPlaylistsIn->getPlaylist(nameIn);

            temp->toString();
        }
    }
}

/**
 * make a new empty playlist with the given name
 * @param playlistNameIn desired name for the playlist
 * @post a new empty playlist is created and saved
 */
Playlist* newPlaylist(Playlist* listOfPlaylistsIn, std::string nameIn){
    listOfPlaylistsIn->newPlaylist(nameIn);
    return listOfPlaylistsIn;
}

/**
 * add the given song to the end of of the playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 * @param duration length of the song in seconds
 */
std::string add(std::string nameIn, std::string artistIn, std::string titleIn, int duration, Playlist* listOfPlaylistsIn){
    //TODO make calls to add song to proper linked list
    Song temp = Song(titleIn, artistIn, duration);
    std::string songString;

    LinkedList* listToUse = listOfPlaylistsIn->getPlaylist(nameIn);

    int foundSong = listToUse->findSongByTitle(titleIn);

    if(foundSong == -1){
        listToUse->insertAtEnd(temp);
    }
    else {
        songString = temp.toString();
        return songString;
    }
    return songString;
}

/**
 * remove the given song from the requested playlist
 * @param nameIn name of the playlist desired
 * @param artistIn name of artist
 * @param titleIn title of the song
 */
void remove(std::string nameIn, std::string artistIn, std::string titleIn, Playlist* listOfPlaylistsIn){
    //TODO make calls to remove song from proper linked list

}

/**
 * plays the next song in the playlist and removes it
 * (if playlist is empty remove that too)
 * @param playlistIn
 * @post print to console all song information
 */
void playNext(std::string nameIn){
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
void quit(Playlist* listOfPlaylistsIn, MusicLibrary* musicLibraryIn){
    //TODO make calls to save/write out files here?

    std::cout << "\nSaving files and exiting...\n" << std::endl;

    musicLibraryIn->WriteFile();

    int size = listOfPlaylistsIn->getCurrCount();

    //TODO test
    for(int i = 0; i < size; i++) {
        listOfPlaylistsIn->writeFile("TestFile.csv");
    }
}
