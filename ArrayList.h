//
// Created by Toby Dragon on 9/30/16.
// modified by Kurt Burdick on 12/10/19
//

#ifndef COMP220_ARRAYLIST_H
#define COMP220_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "Song.h"

class ArrayList : public List {
private:
    //pointer to the start of the array
    Song* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

public:
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    ArrayList(int initialCapacity);

    //Copy Constructor
    ArrayList(const ArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    ArrayList& operator=(const ArrayList& arrayListToCopy);

    //Destructor
    ~ArrayList();

    //file io stuff
    //TODO write function description
    void WriteFile(std::string fileName);

    /**
     * get the song duration
     * @param songIn input parameter
     */
    int getDuration(Song songIn);

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(Song itemToAdd);

    /**
     * adds a new song to the list in alphabetical order by artist and then by song
     * @param songToAdd song to add to the list
     * @post song is added in order and the library will be sorted for lookup
     */
    void insertInOrder(Song songToAdd);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song getValueAt(int index);

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    void toString();

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int getCurrentItemCount();

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * Searches a song array for a certain song
     * @return if the song exists or not
     */
    bool findSong(Song songToFind);

    /**
     * Searches a song array for a certain song
     * @return the index of the list that contains the song
     */
    int findSongIndex(Song songToFind);

    /**
   * Searches a song list for a certain song
   * @return index of the song in the list, -1 if the song is not present
   */
    int findSongByArtist(std::string artistIn);

    /**
    * Searches a song list for a certain song
    * @return index of the song in the list, -1 if the song is not present
    */
    int findSongByTitle(std::string titleIn);

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(Song songToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(Song songToAdd, int index);

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeSongAtEnd();

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeSongAtFront();

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    void removeSongAt(int index);

};


#endif //COMP220_ARRAYLIST_H
