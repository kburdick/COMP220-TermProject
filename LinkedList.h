//
// Created by Toby Dragon on 10/30/18.
//
//TODO :
// we need to implement a template version of the linked node class, to store any type of data (aka song objects)
// and also a template version of the linkedlist class, which will have functions that handle templates.
// the library and playlist can be based on the linkedlist class, but also need to have their own functionality and
// fewer functions than the integer type classes that we have written in the past...I think this is the best way to do this.////
// end.

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
      */
    void insertAtEnd(Song songToAdd);


    /**
     * gives a string representation of the current list
     * @returns a string representing the song using the song class methods
     */
    std::string toString();

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
     * Searches a song array for a certain song
     * @return true or false if the song is present or not
     */
    bool findSong(Song songToFind);

    /**
     * removes the song from the list, and returns a copy of that song
     * @param the song from which to remove the song
     * @post the song is removed from the list if found, everything else is shifted down one
     * @return a copy of the song at index
     * @throws out_of_range exception if song is invalid, prints the song it could not find
     */
    Song removeSong(Song songToRemove);

    /**
     * sorts the list for alphabetical order of artists and then songs
     * @param none
     * @post the songs in the list are sorted alphabetically
     * @return none
     */
    void sortList();

    /**
     * shuffles the list to be in random order
     * @param none
     * @post the list is shuffled out of order
     */
    void shuffle();
};


#endif //LAB8SOLN_LINKEDLIST_H
