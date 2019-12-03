//
// Created by Kurt Burdick on 11/20/19.
//

#include "Song.h"
#include "MusicLibrary.h"

//default constructor
MusicLibrary::MusicLibrary() {
    this->title = "";
    this->artist = "";
    this->fileName= "";
}


MusicLibrary::~MusicLibrary() {

}
/**
 * calls the file read in method
         * @post generates a music library and prints out any songs that are already in the playlist
         */
void MusicLibrary::fileReadIn(std::string fileName){}


/**
   * Removes all songs from the music library and any occurrences of those songs within the valid playlists
   * Prints out a message of any songs that do not occur within the library or the playlist
   * @post a library and playlists without the songs given in the file
   */
void MusicLibrary::removeSongs(std::string fileName){}

/**
  * displays all songs within the music library
  * @post a list of all the songs within the music library printed to the user
  */
void MusicLibrary::displayAllSongs(){}

/**
  * takes in an artist from the user
  * @post a list of all the songs from the given artist is displayed to the user
  */
void MusicLibrary::displayArtist(std::string artist){}

/**
  * displays all information of the song given an artist and a title
  * @post a list of information about the song is displayed to the user
  */
void MusicLibrary::displaySongInfo(std::string artist,std::string title){}



