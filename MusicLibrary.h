//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_MUSICLIBRARY_H
#define COMP220_TERMPROJECT_MUSICLIBRARY_H

#include <string>

//can the music library be created using a template based linked list class
//either way we need to make the linked list code accept classes of type song at the very least
//also need to make the music library write out and read in from files to keep songs up to date
//the playlist needs to be called the same text file as is read in, and each playlist needs to be kept
//in a different text file to keep track of the songs

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

#endif //COMP220_TERMPROJECT_MUSICLIBRARY_H
