//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"
#include "Playlist.h"

int main() {

    std::cout << "----Library Tester----\n" << std::endl;

    std::cout << "--make a song to test--" << std::endl;
    std::cout << "-------------------\n" << std::endl;

    Song song1 = Song("One", "Metallica", 446);

    std::cout << song1.getSongTitle() << std::endl;
    std::cout << song1.getSongArtist() << std::endl;
    std::cout << song1.getSongDuration() << std::endl;
    std::cout << "test basic toString method for Song:" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "--Create Music Library--" << std::endl;
    //TODO write test functions to create the music library and test its functionality

    std::cout << "\n" << std::endl;

    return 0;
}
