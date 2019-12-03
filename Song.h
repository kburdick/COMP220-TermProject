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

        Song();
        Song(std::string title, std::string artist, int duration);
        Song(std::string songString);
        Song(const Song& songToCopy);
        Song& operator=(const Song& songToCopy);
        ~Song();
        std::string getSongTitle();
        std::string getSongArtist();
        int getSongDuration();
        int getPlayCount();
        void updateSongTitle(std::string title);
        void updateSongArtist(std::string artist);
        void updateSongDuration(int duration);
        void updatePlayCount(int num);
        std::string toString();

};


#endif //COMP220_TERMPROJECT_FA19_SONG_H
