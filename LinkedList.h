//
// Created by Kurt Burdick on 12/2/19.
//

#ifndef LAB8SOLN_LINKEDLIST_H
#define LAB8SOLN_LINKEDLIST_H


#include "List.h"
#include "LinkedNode.h"
#include "MusicLibrary.h"

class LinkedList : public List{
private:
    std::string name;
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
     * Writes a playlist or library to fileName
     * @param fileName
     */
    void WriteFile(std::string fileName);

    /**
    * get the song duration
    * @param songIn input parameter
    */
    int getDuration(Song songIn);


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
    * @return Song -1 if the song is not present
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
     * determines the total amount of items within the list
     * @param none
     * @return the total amount of items within the list
     */
     int getCurrentItemCount();

    /**
    * gets a value from the list
    * @param index the location from which to get the value
    * @return a copy of the item at index
    * @throws out_of_range exception if index is invalid
    */
    Song getValueAt(int index);

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
    * Searches a song array for a certain song
    * @return the index of the list that contains the song
    */
    int findSongIndex(Song songToFind);

    /**
    * uses add song, new playlist, and sumDuration
    * Creates a new playlist and adds songs at random without going over the duration specified by the user
    * Note: Songs do not repeat
    * @param the name of the song
    * @param the total duration of the playlist
    * @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
    */
    void newRandomPlaylist(std::string name, int totalDuration, MusicLibrary* library);

    /**
   * sums the total duration of the playlist
   * @post the total duration in seconds of the playlist
   */
    void sumDuration();

    /**
   * Prints information about the next song in the playlist
   * Removes the desired song from the playlist
   * Adds one to the play count of that song in the library
   * If the playlist is empty, then remove the playlist
   * @param the name of the song
   * @post all of the information about the song is displayed to the user
   */
    void playNext(MusicLibrary* library);
};


#endif //LAB8SOLN_LINKEDLIST_H
