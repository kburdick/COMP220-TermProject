//
// Created by Robert on 12/5/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"
#include "FileIO.h"

int main(){
    std::cout << "--------------------------" << std::endl;
    std::cout << "----File Reader Tester----" << std::endl;
    std::cout << "--------------------------\n" << std::endl;

    std::cout << "\n create linked list pointer to test import...\n" << std::endl;
    LinkedList* testList;
    testList = readPlaylist("testSongLib.csv");

    std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "----To String Should Print Same information from the file----" << std::endl;
    std::cout << "-------------------------------------------------------------\n" << std::endl;
    testList->toString();

    std::cout << "\n create array list pointer to test import...\n" << std::endl;
    ArrayList* testLib;

    testLib = readLibrary("testSongLib.csv");
    testLib->toString();
    std::cout << "\n----To String Should Print Same information from the file again----\n" << std::endl;

    //make a music library
    MusicLibrary* myMusic = new MusicLibrary(testLib);
    myMusic->displayAllSongs();

    int temp = myMusic->sumDuration();
    std::cout << temp << std::endl;

    std::cout << myMusic->displaySongInfo("Detlef", "Rock It") << std::endl;


    //make an empty library
    MusicLibrary* anotherFile = new MusicLibrary();
    int temp2 = anotherFile->getTotalSongCount();


    //TODO Automate the tests in some way with another file.....

}