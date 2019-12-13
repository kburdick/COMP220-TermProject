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

    //std::string temp1 = myMusic->displaySongInfo("Detlef", "Rock It");
    //std::cout << temp1;

    //make an empty library
   // MusicLibrary* anotherFile = new MusicLibrary();
   // int temp2 = anotherFile->getTotalSongCount();

    // testing displaySongArtist
    std::cout << "\n----Testing the displaySongArtist----\n" << std::endl;
    std::cout << "\n----Should print out three songs by Kayzo----\n" << std::endl;
    std::string artistToTest = "Kayzo";
    myMusic->displayArtist(artistToTest);
    std::cout << "\n----Should print out one song by Animals As Leaders----\n" << std::endl;
    artistToTest = "Animals As Leaders";
    myMusic->displayArtist(artistToTest);
    std::cout << "\n----Should print out one song by Deep Moth----\n" << std::endl;
    artistToTest = "Deep Moth";
    myMusic->displayArtist(artistToTest);



    //TODO Automate the tests in some way with another file.....

}