//
// Created by Kurt Burdick on 11/20/19.
//

#include "Playlist.h"

Playlist::Playlist() {
    this->totalDuration = 0;
    this->songName = "";
}

//destructor
Playlist::~Playlist() {

}

/**
    * uses add song, new playlist, and sumDuration
    * Creates a new playlist and adds songs at random without going over the duration specified by the user
    * Note: Songs do not repeat
    * @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
    */
void Playlist::newRandomPlaylist(std::string songName, int totalDuration){}

/**
* sums the total duration of the playlist
* @post the total duration in seconds of the playlist
*/
void Playlist::sumDuration(){}

/**
* Prints information about the next song in the playlist
* Removes the desired song from the playlist
* Adds one to the play count of that song in the library
* If the playlist is empty, then remove the playlist
* @post all of the information about the song is displayed to the user
*/
void Playlist::playNext(std::string songName){}

