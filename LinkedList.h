//
// Created by Kurt Burdick on 12/2/19.
//

#ifndef LAB8SOLN_LINKEDLIST_H
#define LAB8SOLN_LINKEDLIST_H


#include "List.h"
#include "LinkedNode.h"

class LinkedList : public List{
private:
    //TODO: Your data here
    LinkedNode* head;
    LinkedNode* tail;
    int currItemCount;


    //Private to disable copying and assigning from outside class, don't implement these methods
    LinkedList(const LinkedList& arrayListToCopy);
    LinkedList& operator=(const LinkedList& arrayListToCopy);
public:
    /**
     * Constructor
     */
    LinkedList();

    //Destructor
    ~LinkedList();

    /**
      * appends the new song to the end of the list
      * @post the list has an additional song in it, at the end
      * @param songToAdd song to add to the list
      */
    void insertAtEnd(Song songToAdd);

    /**
     * adds a new song to the list in alphabetical order by artist and then by song
     * @param songToAdd song to add to the list
     * @post song is added in order and the library will be sorted for lookup
     */
    void insertInOrder(Song songToAdd);

    /**
     * gives a string representation of the current list
     * @returns null
     * @post displays all songs to the current console
     */
    void toString();

    /**
     * Writes a playlist or library to fileName
     * @param fileName
     */
    void WriteFile(std::string fileName);


    /**
     * checks if there are any valid songs in the list
     * @return true if there are no valid songs in the list, false otherwise
     */
    bool isEmpty();

    /**
     * makes the list empty of valid songs
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * Searches a song list for a certain song
     * @return true or false if the song is present or not
     */
    bool findSong(Song songToFind);

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
     * removes the song from the list, and returns a copy of that song
     * @param the song from which to remove the song
     * @post the song is removed from the list if found, everything else is shifted down one
     * @return a copy of the song at index
     * @throws out_of_range exception if song is invalid, prints the song it could not find
     */
    Song removeSong(Song songToRemove);

    /**
     * shuffles the list to be in random order
     * @param none
     * @post the list is shuffled out of order
     */
    int ranNumGenerator(int max);

    /**
     * determines the total amount of items within the list
     * @param none
     * @return the total amount of items within the list
     */
     int getCurrentItemCount();
};


#endif //LAB8SOLN_LINKEDLIST_H
