//
// Created by Kurt Burdick on 12/2/19.
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
     * adds a new song to the list in alphabetical order by artist and then by song
     * @param songToAdd song to add to the list
     * @post song is added in order and the library will be sorted for lookup
     */
    virtual void insertInOrder(Song songToAdd)=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the song using the song class methods
     */
    virtual void toString()=0;

    virtual void WriteFile(std::string fileName)=0;

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
    * Searches a song list for a certain song
    * @return index of the song in the list, -1 if the song is not present
    */
    virtual int findSongByArtist(std::string artistIn)=0;

    /**
    * Searches a song list for a certain song
    * @return index of the song in the list, -1 if the song is not present
    */
    virtual int findSongByTitle(std::string titleIn)=0;

    /**
     * removes the song from the list, and returns a copy of that song
     * @param the song from which to remove the song
     * @post the song is removed from the list if found, everything else is shifted down one
     * @return a copy of the song at index
     * @throws out_of_range exception if song is invalid, prints the song it could not find
     */
    virtual Song removeSong(Song songToRemove)=0;


     /**
      * generates a random number
      * @param
      * @post the list is shuffled out of order
      */
     virtual int ranNumGenerator(int max)=0;

    /**
    * determines the total amount of items within the list
    * @param none
    * @return the total amount of items within the list
    */
    virtual int getCurrentItemCount()=0;

};


#endif //COMP220_LIST_H
