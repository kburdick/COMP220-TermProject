//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "MusicLibrary.h"
#include "FileIO.h"
#include "Song.h"

//default constructor creates an empty music library
MusicLibrary::MusicLibrary() {
    this->arrayOfSongs = new ArrayList(10);
    this->totalSongCount = -1;
}

MusicLibrary::MusicLibrary(ArrayList* listOfSongs) {
    this->arrayOfSongs = listOfSongs;
    this->totalSongCount = listOfSongs->getCurrentItemCount();
}

//destructor
MusicLibrary::~MusicLibrary() {
    delete [] arrayOfSongs;
}
/**
 * calls the file read in method
 * @param the name of the file in which to read in
 * @post generates a music library and prints out any songs that are already in the playlist
 */
void MusicLibrary::fileReadIn(std::string fileName){
    this->arrayOfSongs = readLibrary(fileName);
    this->totalSongCount = arrayOfSongs->getCurrentItemCount();
}

int MusicLibrary::getTotalSongCount(){
    return totalSongCount;
}


/**
   * Removes all songs from the music library and any occurrences of those songs within the valid playlists
   * Prints out a message of any songs that do not occur within the library or the playlist
   * @param the name of the file containing all of the songs that should be removed from the library and playlists
   * @post a library and playlists without the songs given in the file
   */
void MusicLibrary::removeSongs(std::string fileName){

}

/**
  * displays all songs within the music library
  * @post a list of all the songs within the music library printed to the user
  */
void MusicLibrary::displayAllSongs(){
    arrayOfSongs->toString();
}

/**
  * takes in an artist from the user
  * @param the name of the artist
  * @post a list of all the songs from the given artist is displayed to the user
  */
void MusicLibrary::displayArtist(std::string artist){
    //TODO

}

/**
  * displays all information of the song given an artist and a title
  * @param the name of the artist
  * @param the title of the song
  * @post a list of information about the song is displayed to the user
  */
void MusicLibrary::displaySongInfo(std::string artist, std::string title){

    int count = arrayOfSongs->getCurrentItemCount();

    for(int i = 0; i < count; i++) {
        int artistPosition = arrayOfSongs->findSongByArtist(artist);
        int titlePosition = arrayOfSongs->findSongByTitle(title);

        if(artistPosition == titlePosition) {
            arrayOfSongs[i].toString();
        }
    }
}


int MusicLibrary::sumDuration(){
    int size = arrayOfSongs->getCurrentItemCount();
    int duration = 0;

    for(int i = 0; i < size; i++) {
        Song temp = arrayOfSongs->getValueAt(i);

        duration = duration + temp.getSongDuration();
    }

    return duration; //TODO check function this currently returns seconds!
}


