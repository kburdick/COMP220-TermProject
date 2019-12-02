//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_PLAYLIST_H
#define COMP220_TERMPROJECT_PLAYLIST_H

#include "MusicLibrary.h"

class Playlist : public MusicLibrary {
private:
    //TODO: fill in the data here

    //TODO check for the implementation of these methods (yes or no)
    //Private to disable copying and assigning from outside of class
    Playlist(const Playlist &playlistToCopy);
    Playlist &operator=(const Playlist &playlistToCopy);

public:
    /**
     * Constructor
     */
    //TODO fill in functions that are specific to the playlist (can inherit some functions from the library class)
    //default constructor TODO check if we even want this to be possible
    Playlist();

    //destructor
    ~Playlist();


};


#endif //COMP220_TERMPROJECT_PLAYLIST_H
