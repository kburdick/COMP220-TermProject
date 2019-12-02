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
        float duration;
        int playCount;

    public:

        Song();
        Song(std::string title, std::string artist, float duration);
        Song(std::string songString);
        Song(const Song& songToCopy);
        Song& operator=(const Song& songToCopy);
        ~Song();
        std::string getSongTitle();
        std::string getSongArtist();
        float getSongDuration();
        int getPlayCount();
        void updateSongTitle(std::string title);
        void updateSongArtist(std::string artist);
        void updateSongDuration(float duration);
        void updatePlayCount(int num);
        std::string toString();

};


#endif //COMP220_TERMPROJECT_FA19_SONG_H
