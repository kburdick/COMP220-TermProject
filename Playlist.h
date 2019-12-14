//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_PLAYLIST_H
#define COMP220_TERMPROJECT_PLAYLIST_H

#include "List.h"
#include "LinkedList.h"

class Playlist {
private:
    int capacity;
    int currCount;
    LinkedList* playlists;




public:
    /**
     * Constructor
     */

    Playlist();

    Playlist(const Playlist &playlistToCopy);

    Playlist &operator=(const Playlist &playlistToCopy);

    //destructor
    ~Playlist();

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
     * calls write file on each of the proper linked lists files
     * @param fileName
     */
    void writeFile(std::string fileName);

    /**
     * Create new Playlist
     * @param the name of the list
     * @post adds list to playlists array
     */
     void newPlaylist(std::string name);

    /**
    * returns pointer to playlist based on name
    * @param the name of the list
    * @return pointer to playlist based on name
    */
    LinkedList* getPlaylist(std::string name);

    /**
     * gets the playlist name by passing an index
     * @param index
     * @return the name of the playlist
     */
    std::string getPlaylistName(int index);

    /**
     * gets the count of the items of linked lists that are in the playlists holder
     * @return the currCount
     */
    int getCurrCount();
};


#endif //COMP220_TERMPROJECT_PLAYLIST_H
