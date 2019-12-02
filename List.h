//
// Created by Toby Dragon on 9/30/16.
//

#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>
#include "Song.h"

class List {
private:
    //Private to disable copying and assigning from outside class, don't implement these methods
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);

public:
    //constructor
    List() {}

    //Destructor
    virtual ~List() {}

    /**
     * appends the new song to the end of the list
     * @post the list has an additional song in it, at the end
     */
    virtual void insertAtEnd(Song songToAdd)=0;


    /**
     * gives a string representation of the current list
     * @returns a string representing the song using the song class methods
     */
    virtual std::string toString()=0;

    /**
     * checks if there are any valid songs in the list
     * @return true if there are no valid songs in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * makes the list empty of valid songs
     * @post the list is empty, such that isEmpty() == true
     */
    virtual void clearList()=0;

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    virtual bool findSong(Song songToFind)=0;

    /**
     * removes the song from the list, and returns a copy of that song
     * @param the song from which to remove the song
     * @post the song is removed from the list if found, everything else is shifted down one
     * @return a copy of the song at index
     * @throws out_of_range exception if song is invalid, prints the song it could not find
     */
    virtual Song removeSong(Song songToRemove)=0;

    /**
     * sorts the list for alphabetical order of artists and then songs
     * @param none
     * @post the songs in the list are sorted alphabetically
     * @return none
     */
     virtual void sortList()=0;

     /**
      * shuffles the list to be in random order
      * @param none
      * @post the list is shuffled out of order
      */
     virtual void shuffle()=0;
};


#endif //COMP220_LIST_H
