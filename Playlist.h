//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_PLAYLIST_H
#define COMP220_TERMPROJECT_PLAYLIST_H

#include "List.h"
#include "LinkedList.h"

class Playlist {
private:
    //TODO: fill in the data here
    LinkedList* playlist;
    int totalDuration;

    //TODO check for the implementation of these methods (yes or no)

    //Private to disable copying and assigning from outside of class

    Playlist(const Playlist &playlistToCopy);
    Playlist &operator=(const Playlist &playlistToCopy);

public:
    /**
     * Constructor
     */
    //TODO fill in functions that are specific to the playlist (can inherit some functions from the library class)

    //default constructor TODO check if we even want this to be possible
    Playlist();

    //destructor
    ~Playlist();

    /**
    * uses add song, new playlist, and sumDuration
    * Creates a new playlist and adds songs at random without going over the duration specified by the user
    * Note: Songs do not repeat
    * @param the name of the song
    * @param the total duration of the playlist
    * @post generates a new playlist that is populated with random songs that don't repeat and overall less than the duration
    */
    void newRandomPlaylist(std::string songName, int totalDuration);

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
   void playNext(std::string songName);

};


#endif //COMP220_TERMPROJECT_PLAYLIST_H
