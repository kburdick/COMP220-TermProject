//
// Created by Robert on 12/13/19.
//

#ifndef COMP220_TERMPROJECT_PLAYLISTLIST_H
#define COMP220_TERMPROJECT_PLAYLISTLIST_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "Song.h"
#include "LinkedList.h"


class PlaylistList{
private:
    //pointer to the start of the array
    LinkedList* array;
    //count of the number of valid items currently stored in the array
    int numPlaylists;
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
     */
    PlaylistList();

    //Copy Constructor
    PlaylistList(const PlaylistList& PlaylistListToCopy);

    //Overloaded Assignment Operator
    PlaylistList& operator=(const PlaylistList& PlaylistListToCopy);

    //Destructor
    ~PlaylistList();

    //file io stuff
    /**
     * Writes contents to file
     * @param fileName
     */
    void WriteFile(std::string fileName);

    /**
     * get the song duration
     * @param songIn input parameter
     */
    int getPlaylistByIndex(int index);

    /**
     * get the song duration
     * @param songIn input parameter
     */
    int getPlaylistByName(std::string name);

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
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    LinkedList* removePlaylistAtEnd();

    /**
    * uses add song, new playlist, and sumDuration
    * Creates a new playlist and adds songs at random without going over the duration specified by the user
    * Note: Songs do not repeat
    * @param the name of the list
    * @param the total duration of the playlist
    * @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
    * @post adds list to playlists array
    */
    void newRandomPlaylist(std::string name, int totalDuration, MusicLibrary* library);

    /**
     * Create new Playlist
     * @param the name of the list
     * @post adds list to playlists array
     */
    void newPlaylist(std::string name);

};
#endif //COMP220_TERMPROJECT_PLAYLISTLIST_H
