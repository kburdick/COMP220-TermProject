//
// Created by Kurt Burdick on 11/20/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"

int main() {
    srand(time(NULL));
    std::cout << "-------------------" << std::endl;
    std::cout << "----List Tester----" << std::endl;
    std::cout << "-------------------\n" << std::endl;

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

    std::cout << '\n' << std::endl;

    //song not in the list
    Song song3 = Song("Gravity", "John Mayer", 500);

    std::cout << "\n----Test boolean find song method----\n" << std::endl;
    std::cout << "expected 1, got: " << songList->findSong(song2) << std::endl;
    std::cout << "expected 0, got: " << songList->findSong(song3) << std::endl;

    std::cout << "\n----Test find song by artist method----\n" << std::endl;
    std::cout << "expected 0, got: " << songList->findSongByArtist("Metallica") << std::endl;
    std::cout << "expected -1, got: " << songList->findSongByArtist("John Mayer") << std::endl;

    std::cout << "\n----Test find song by title method----\n" << std::endl;
    std::cout << "expected 2, got: " << songList->findSongByTitle("The Rover") << std::endl;
    std::cout << "expected -1, got: " << songList->findSongByTitle("Gravity") << std::endl;

    std::cout << "\n finally add song to the list, and test again\n" << std::endl;
    songList->insertAtEnd(song3);
    std::cout << "expected 3, got: " << songList->findSongByArtist("John Mayer") << std::endl;


    //test remove song
    //std::cout << "----test removeSong method----\n" << std::endl;
    //songList->removeSong(song2);
    //songList->toString();

    delete songList;

    std::cout << "\nNOTE: currently adds duplicates..." << std::endl;
    std::cout << "a function for adding songs will be altered in library and playlist classes\n" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    std::cout << "\n----Test shuffle songs ----\n" << std::endl;
    LinkedList* songList2 = new LinkedList(); // creates a new songList
    Song song10 = Song("Heart Strings", "Enamour", 244);
    Song song11 = Song("Rock It", "Detlef", 432);
    Song song12 = Song("Activate", "Deep Moth", 372);
    Song song13 = Song("Turbo Time", "Patrick Topping", 392);
    Song song14 = Song("Roped In", "Gorgon City", 265);
    Song song15 = Song("ARK", "Kayzo", 217);
    Song song16 = Song("Blackwing", "Cloudkicker", 342);
    Song song17 = Song("Physical Education", "Animals As Leaders", 323);
    Song song18 = Song("Turbo Speed", "Patrick Topping", 267);
    Song song19 = Song("Braincase", "Kayzo", 187);
    Song song20 = Song("Antidance", "Kayzo", 286);
    songList2->insertAtEnd(song10);
    songList2->insertAtEnd(song11);
    songList2->insertAtEnd(song12);
    songList2->insertAtEnd(song13);
    songList2->insertAtEnd(song14);
    songList2->insertAtEnd(song15);
    songList2->insertAtEnd(song16);
    songList2->insertAtEnd(song17);
    songList2->insertAtEnd(song18);
    songList2->insertAtEnd(song19);
    songList2->insertAtEnd(song20);
    std::cout << "\n----Unshuffled List of songs in a list----\n" << std::endl;
    songList2->toString();
    std::cout << "\n----shuffled List of songs in a list----\n" << std::endl;
    std::cout << songList2->getCurrentItemCount() << std::endl;
    songList2->toString();



    std::cout << "\n----Test ranGenNum ----\n" << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;
    std::cout << songList2->ranNumGenerator(songList2->getCurrentItemCount()) << std::endl;

    std::cout << "\n----Writing List to testSongLib.csv----\n" << std::endl;
    songList2->WriteFile("testSongLib.csv");


    std::cout << "----end test for linkedlist----" << std::endl;
    std::cout << "-------------------------------\n" << std::endl;


    std::cout << "\n" << std::endl;

    return 0;
}
