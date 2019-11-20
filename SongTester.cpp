//
// First test file for basic io and toString methods for the song class
// created by: Kurt Burdick 11/18/19
// modified by: ...
//


#include <iostream>
#include "Song.h"

int main() {

    std::cout << "----Song Constructor Tester----" << std::endl;
    std::cout << "-------------------\n" << std::endl;

    Song song1 = Song("One", "Metallica", 446);

    std::cout << song1.getSongTitle() << std::endl;
    std::cout << song1.getSongArtist() << std::endl;
    std::cout << song1.getSongDuration() << std::endl;
    std::cout << "test basic toString method for Song:" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "\n------------------" << std::endl;
    std::cout << "Change the fields..." << std::endl;
    std::cout << "------------------\n" << std::endl;

    song1.updateSongTitle("Master of Puppets");
    song1.updateSongDuration(515);
    song1.updatePlayCount(2);

    std::cout << "Song is now:" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << "Test string as input for song object:\n" << std::endl;

    std::string testString = "Harvester of Sorrow, Metallica, 600, 5";
    Song song2 = Song(testString);
    std::cout << song2.toString() << std::endl;

    std::cout << "---------------\n" << std::endl;
    std::cout << "Test string as input for song object again..." << std::endl;

    std::string testSong = "The Rover, Led Zeppelin, 800, 2";
    Song ledSong = Song(testSong);
    std::cout << ledSong.toString() << std::endl;
    std::cout << "test get play count: " << ledSong.getPlayCount() << std::endl;

    //TODO: Test the copy constructors and other functions more robustly HERE:
    //
    return 0;
}