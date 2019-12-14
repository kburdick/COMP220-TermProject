//
// Created by Kurt Burdick on 11/20/19.
//

#ifndef COMP220_TERMPROJECT_MUSICLIBRARY_H
#define COMP220_TERMPROJECT_MUSICLIBRARY_H

#include "List.h"
#include "ArrayList.h"

class MusicLibrary {
private:
    ArrayList* arrayOfSongs;
    std::string name;
    int totalSongCount;


    MusicLibrary& operator=(const MusicLibrary& libraryToCopy);

public:

    MusicLibrary(); //check if we want default methods to be possible
    MusicLibrary(ArrayList* listOfSongs);
    ~MusicLibrary();
    /**
         * calls the file read in method
         * @param the name of the file in which to read in
         * @post generates a music library and prints out any songs that are already in the playlist
         */
    void fileReadIn(std::string fileName);

    /**
     * Writes a playlist or library to a file (saves it to the most recent file loaded
     */
    void WriteFile();

    /**
     * Removes all songs from the music library and any occurrences of those songs within the valid playlists
     * Prints out a message of any songs that do not occur within the library or the playlist
     * @param the name of the file containing all of the songs that should be removed from the library and playlists
     * @post a library and playlists without the songs given in the file
     */
    void removeSongs(std::string fileName);

    /**
      * displays all songs within the music library
      * @post a list of all the songs within the music library printed to the user
      */
    void displayAllSongs();

    /**
      * takes in an artist from the user
      * @param the name of the artist
      * @post a list of all the songs from the given artist is displayed to the user
      */
    void displayArtist(std::string artist);

    /**
      * displays all information of the song given an artist and a title
      * @param the name of the artist
      * @param the title of the song
      * @post a list of information about the song is displayed to the user
      */
    std::string displaySongInfo(std::string artistIn, std::string titleIn);

    /**
     * calculates the total duration of the list of songs
     * @param listToSum
     * @return the total duration
     */
    int sumDuration();

    /**
     * finds the song for an array list
     * @param songToFind
     * @return a pointer to the song found
     */
    Song* findSong(Song songToFind);

    /**
     * find song at a specific index
     * @param index
     * @return
     */
    Song findSongAtIndex(int index);

    /**
     * gets the number of items in the arraylist
     * @return integer values
     */
    int getItemCount();

<<<<<<< HEAD
    MusicLibrary(const MusicLibrary& libraryToCopy);
=======
    Song removeOneSong(Song songToRemove);
>>>>>>> 0bbedf4802b91c402a738fe2a8eb837b31516c58
};

// we need to add and remove songs from the library


#endif //COMP220_TERMPROJECT_MUSICLIBRARY_H
