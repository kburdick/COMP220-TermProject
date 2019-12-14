//
// Created by Robert on 12/13/19.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include "ArrayList.h"
#include "ArrayLib.h"
#include "PlaylistList.h"
#include "LinkedNode.h"
#include "LinkedList.h"

/**
* Constructor
*/
PlaylistList::PlaylistList(){
    currCapacity = 50;
    array = new LinkedList[currCapacity];
    numPlaylists = 0;
}

//Copy Constructor
PlaylistList::PlaylistList(const PlaylistList& PlaylistListToCopy){
    currCapacity = PlaylistListToCopy.currCapacity;
    numPlaylists = PlaylistListToCopy.numPlaylists;
    array = new LinkedList[currCapacity];
    for(int i = 0; i < numPlaylists; i++) {
        array[i] = PlaylistListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
PlaylistList& PlaylistList::operator=(const PlaylistList& PlaylistListToCopy){
    if (this == &PlaylistListToCopy){
        return *this;
    }
    currCapacity = PlaylistListToCopy.currCapacity;
    numPlaylists = PlaylistListToCopy.numPlaylists;
    delete[] array;
    array = new LinkedList[currCapacity];
    for (int i = 0; i<numPlaylists; i++){
        array[i] = PlaylistListToCopy.array[i];
    }
    return *this;
}

//Destructor
PlaylistList::~PlaylistList(){
    delete [] array;
}

//file io stuff
/**
 * Writes contents to file
 * @param fileName
 */
void PlaylistList::WriteFile(std::string fileName){

}

/**
 * get the song duration
 * @param songIn input parameter
 */
int PlaylistList::getPlaylistByIndex(int index){

}

/**
 * get the song duration
 * @param songIn input parameter
 */
int PlaylistList::getPlaylistByName(std::string name){

}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
void PlaylistList::toString(){

}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool PlaylistList::isEmpty(){

}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int PlaylistList::getCurrentItemCount(){

}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
LinkedList* PlaylistList::removePlaylistAtEnd(){

}

/**
* uses add song, new playlist, and sumDuration
* Creates a new playlist and adds songs at random without going over the duration specified by the user
* Note: Songs do not repeat
* @param the name of the list
* @param the total duration of the playlist
* @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
* @post adds list to playlists array
*/
void PlaylistList::newRandomPlaylist(std::string name, int totalDuration, MusicLibrary* library){

}

/**
 * Create new Playlist
 * @param the name of the list
 * @post adds list to playlists array
 */
void PlaylistList::newPlaylist(std::string name){

}