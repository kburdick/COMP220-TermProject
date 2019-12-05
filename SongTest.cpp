//
// First test file for basic io and toString methods for the song class
// created by: Kurt Burdick 11/18/19
// modified by: ...
//


#include <iostream>
#include "Song.h"

int main() {

    //TODO fix test output formatting

    std::cout << "\n---------------------------" << std::endl;
    std::cout << "---- Song Class Tester ----" << std::endl;
    std::cout << "---------------------------\n" << std::endl;

    Song song1 = Song("One", "Metallica", 446);

    std::cout << "\n---- Testing getters ----\n" << std::endl;
    std::cout << "expected: One, got: " << song1.getSongTitle() << std::endl;
    std::cout << "expected: Metallica, got: " << song1.getSongArtist() << std::endl;
    std::cout << "expected: 446, got: " << song1.getSongDuration() << std::endl;
    std::cout << "expected: 0, got: " << song1.getPlayCount() << std::endl;
    std::cout << "\n---- Test basic toString method for Song: ----\n" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "\n---- Testing setters ----\n" << std::endl;

    song1.updateSongTitle("Master of Puppets");
    song1.updateSongDuration(515);
    song1.updatePlayCount(2);
    song1.updateSongArtist("METALLICA");

    std::cout << "\n---- Song is now: ----\n" << std::endl;
    std::cout << "expected: Master of Puppets, got: " << song1.getSongTitle() << std::endl;
    std::cout << "expected: METALLICA, got: " << song1.getSongArtist() << std::endl;
    std::cout << "expected: 515, got: " << song1.getSongDuration() << std::endl;
    std::cout << "expected: 2, got: " << song1.getPlayCount() << std::endl;
    std::cout << "\n---- re-test toString method ----\n" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "\n---- Test string input for constructor: ----\n" << std::endl;
    std::string testString = "Harvester of Sorrow, Metallica, 600, 5";
    std::cout << "string used: " << "Harvester of Sorrow, Metallica, 600, 5" << std::endl;

    Song song2 = Song(testString);
    std::cout << "expected: Harvester of Sorrow, got: " << song2.getSongTitle() << std::endl;
    std::cout << "expected: Metallica, got: " << song2.getSongArtist() << std::endl;
    std::cout << "expected: 600, got: " << song2.getSongDuration() << std::endl;
    std::cout << "expected: 5, got: " << song2.getPlayCount() << std::endl;
    std::cout << "\n---- re-test toString method ----\n" << std::endl;
    std::cout << song2.toString() << '\n' << std::endl;

    std::string testSong = "The Rover, Led Zeppelin, 800, 2";
    Song ledSong = Song(testSong);
    std::cout << "\n-- make another new song, using: " << ledSong.toString() << std::endl;

    std::cout << "\n---- Test Copy Constructor and assignment operator ----\n" << std::endl;
    Song song3 = Song(ledSong);
    std::cout << "\n-- try copy constructor --\n" << std::endl;
    std::cout << "expected: " << ledSong.toString() << " got: " << song3.toString() << std::endl;
    std::cout << "\n-- try assignment operator --\n" << std::endl;
    Song song4 = song3;
    std::cout << "expected: " << song3.toString() << " got: " << song4.toString() << std::endl;

    std::cout << "\n----------------------------" << std::endl;
    std::cout << "---- End of Song Tester ----" << std::endl;
    std::cout << "----------------------------\n" << std::endl;

    return 0;
}