//
// Created by Kurt Burdick on 12/2/19.
//

#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>
#include "Song.h"
#include <fstream>

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
     * Writes a playlist or library to fileName
     * @param fileName
     */
    virtual void WriteFile(std::string fileName)=0;

    /**
     * get the song duration
     * @param songIn input parameter
     */
    virtual int getDuration(Song songIn)=0;

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
    * determines the total amount of items within the list
    * @param none
    * @return the total amount of items within the list
    */
    virtual int getCurrentItemCount()=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual Song getValueAt(int index)=0;

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    virtual void insertAtFront(Song songToAdd)=0;

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    virtual void insertAt(Song songToAdd, int index)=0;


    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    virtual Song removeSongAtEnd()=0;

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    virtual Song removeSongAtFront()=0;

    /**
    * Searches a song array for a certain song
    * @return the index of the list that contains the song
    */
    virtual int findSongIndex(Song songToFind)=0;
};


#endif //COMP220_LIST_H
