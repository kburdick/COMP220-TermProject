//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "Playlist.h"
#include "LinkedList.h"
#include "ArrayLib.h"

Playlist::Playlist(){
    capacity = 50;
    currCount = 0;
    playlists[capacity];
}

//destructor
Playlist::~Playlist() {
     for(int i = 0; i < capacity; i++){
         delete playlists[i];
     }
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
void Playlist::newRandomPlaylist(std::string name, int totalDuration, MusicLibrary* library){
    LinkedList randomList = LinkedList(name);
    int maxSongCount = library->getItemCount();
    int songsToAdd[maxSongCount];
    int currDuration = 0;
    for(int i=0; i<maxSongCount; i++){
        songsToAdd[i]=i;
    }
    for(int i=0; i<maxSongCount; i++){
        int swapIndex = genRandInt(0,maxSongCount);
        int temp = songsToAdd[i];
        songsToAdd[i] = swapIndex;
        songsToAdd[swapIndex] = temp;
    }
    for(int i=0; i<maxSongCount; i++){
        if (currDuration + library->findSongAtIndex(songsToAdd[i]).getSongDuration() < totalDuration){
            randomList.insertAtEnd(library->findSongAtIndex(songsToAdd[i]));
            currDuration += library->findSongAtIndex(songsToAdd[i]).getSongDuration();
        }
    }
    playlists[currCount] = &randomList;
    currCount ++;
}

/**
     * Create new Playlist
     * @param the name of the list
     * @post adds list to playlists array
     */
void Playlist::newPlaylist(std::string name){
    LinkedList temp = LinkedList(name);
    playlists[currCount] = &temp;
    currCount++;
}

    /**
    * returns pointer to playlist based on name
    * @param the name of the list
    * @return pointer to playlist based on name
    * @throw "playlist not found"
    */
LinkedList* Playlist::getPlaylist(std::string name){
    for(int i=0; i<currCount; i++){
        if (name == playlists[currCount]->getName()){
            return playlists[currCount];
        }
    }
    throw("Playlist not found");
}
