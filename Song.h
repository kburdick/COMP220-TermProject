//
// Created by Kurt Burdick on 11/18/19.
//

#ifndef COMP220_TERMPROJECT_FA19_SONG_H
#define COMP220_TERMPROJECT_FA19_SONG_H

#include <string>

    class Song {
    private:
        std::string title;
        std::string artist;
        int duration;
        int playCount;


    public:

        /**
         * Default Constructor
         */
        Song();

        /**
         * Constructor from individual string inputs
         * @param title of song
         * @param artist of song
         * @param duration of song
         */
        Song(std::string title, std::string artist, int duration);

        /**
         * Constructor for a csv based input string for all values
         * (example input: 'The Rover, Led Zeppelin, 800, 2' )
         * @param songString shown above
         */
        Song(std::string songString);

        /**
         * Copy Constructor for copying a song
         * (NOTE: should not do this for our purposes)
         * @param songToCopy song object input
         */
        Song(const Song& songToCopy);

        /**
         * Overloaded assignment operator
         * @param songToCopy song object input
         * @return the reference to a new song object
         */
        Song& operator=(const Song& songToCopy);


        /**
         * Destructor
         */
        ~Song();

        /**
         * Getter
         * @return title of a song
         */
        std::string getSongTitle();

        /**
         * Getter
         * @return artist of a song
         */
        std::string getSongArtist();

        /**
         * Getter
         * @return duration of a song
         */
        int getSongDuration();

        /**
         * Getter
         * @return number of times a song has been played
         */
        int getPlayCount();

        /**
         * Setter
         * @param title update title of song
         */
        void updateSongTitle(std::string title);

        /**
         * Setter
         * @param artist update artist of song
         */
        void updateSongArtist(std::string artist);

        /**
         * Setter
         * @param duration update duration of song
         */
        void updateSongDuration(int duration);

        /**
         * Setter
         * @param num update play count of song
         */
        void updatePlayCount();

        /**
         * Displays all song information (artist, title, duration, playcount)
         * @return a formatted song string
         * (assumes a csv format)
         */
        std::string toString();

};


#endif //COMP220_TERMPROJECT_FA19_SONG_H
