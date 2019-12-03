//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"
#include "Playlist.h"

int main() {

    std::cout << "----------------------" << std::endl;
    std::cout << "----List Tester----" << std::endl;
    std::cout << "----------------------\n" << std::endl;


    std::cout << "----make a song to test----\n" << std::endl;

    Song song1 = Song("One", "Metallica", 446);

    std::cout << song1.getSongTitle() << std::endl;
    std::cout << song1.getSongArtist() << std::endl;
    std::cout << song1.getSongDuration() << std::endl;
    std::cout << "test basic toString method for Song:" << std::endl;
    std::cout << song1.toString() << std::endl;

    std::cout << "\n";

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "----Create a linked list of songs to test----" << std::endl;
    std::cout << "---------------------------------------------\n";

    //make a new linkedlist of songs
    LinkedList* songList = new LinkedList();
    std::cout << "\n--Test toString on empty list--\n" << std::endl;
    std::cout << "expect nothing...\n\n" << std::endl;
    songList->toString();

    //add two songs to the list
    std::cout << "add two songs to the list...\n\n" << std::endl;
    songList->insertAtEnd(song1);
    songList->insertAtEnd(song1);

    //test the tostring method
    std::cout << "\n----test toString method----\n" << std::endl;
    songList->toString();

    //make another song and add it to the list
    std::string testSong = "The Rover, Led Zeppelin, 800, 2";
    std::cout << "\nadding... " << testSong << " ...to the list\n" << std::endl;
    Song song2 = Song(testSong);

    std::cout << "\n----Re-test toString method----\n" << std::endl;
    songList->insertAtEnd(song2);
    songList->toString();

    delete songList;

    std::cout << "\nNOTE: currently adds duplicates..." << std::endl;
    std::cout << "a function for adding songs will be altered in library and playlist classes\n" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "----end test for linkedlist----" << std::endl;
    std::cout << "-------------------------------\n" << std::endl;


    std::cout << "----------------------------" << std::endl;
    std::cout << "----Create Music Library----" << std::endl;
    std::cout << "----------------------------\n" << std::endl;

    //TODO write test functions to create the music library and test its functionality
    //todo place in a separate test file?? also make tests for the playlist class in a different test file?

    std::cout << "\n" << std::endl;


    return 0;
}
