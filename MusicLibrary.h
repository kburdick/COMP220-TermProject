//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_MUSICLIBRARY_H
#define COMP220_TERMPROJECT_MUSICLIBRARY_H

#include "LinkedList.h"


class MusicLibrary {
private:
    //TODO fill in data for the library here


    //TODO determine if these methods should be implemented (yes or no)
    MusicLibrary(const MusicLibrary& libraryToCopy);
    MusicLibrary& operator=(const MusicLibrary& libraryToCopy);

public:
    //TODO fill in functions for the library here
    MusicLibrary(); //check if we want default methods to be possible
    ~MusicLibrary();


};

// we need to add and remove songs from the library


#endif //COMP220_TERMPROJECT_MUSICLIBRARY_H
