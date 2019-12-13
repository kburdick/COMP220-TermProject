//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "Playlist.h"
#include "LinkedList.h"

Playlist::Playlist() {
    this->playlist = new LinkedList();
    this->totalDuration = 0;
}

//destructor
Playlist::~Playlist() {
    delete playlist; //does this call the actual destructor for the linked list?
}

/**
    * uses add song, new playlist, and sumDuration
    * Creates a new playlist and adds songs at random without going over the duration specified by the user
    * Note: Songs do not repeat
    * @param the name of the song
    * @param the total duration of the playlist
    * @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
    */
void Playlist::newRandomPlaylist(std::string songName, int totalDuration){}

/**
* sums the total duration of the playlist
* @post the total duration in seconds of the playlist
*/
void Playlist::sumDuration(){


}

/**
* Prints information about the next song in the playlist
* Removes the desired song from the playlist
* Adds one to the play count of that song in the library
* If the playlist is empty, then remove the playlist
* @param the name of the song
* @post all of the information about the song is displayed to the user
*/
void Playlist::playNext(std::string songName){}

