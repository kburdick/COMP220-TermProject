//
// Created by Robert on 12/5/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"
#include "FileIO.h"
#include "Playlist.h"

int main() {
    /**
    std::cout << "--------------------------" << std::endl;
    std::cout << "----File Reader Tester----" << std::endl;
    std::cout << "--------------------------\n" << std::endl;

    std::cout << "\n create linked list pointer to test import...\n" << std::endl;
    LinkedList* testList;
    testList = readPlaylist("testSongLib.csv");
    testList->WriteFile("testList.csv");

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
<<<<<<< HEAD
    //myMusic->WriteFile("MusicLibTest.csv");
=======
<<<<<<< HEAD
    myMusic->WriteFile();
=======
<<<<<<< HEAD
   // myMusic->WriteFile("MusicLibTest.csv");
=======
    //myMusic->WriteFile("MusicLibTest.csv");
>>>>>>> a07ea968dca0e56dc13a85a77566eb9f0d41ad69
>>>>>>> 0bbedf4802b91c402a738fe2a8eb837b31516c58
>>>>>>> a52678307501d3591056ab04894791ae296873e4

    int temp = myMusic->sumDuration();
    std::cout << temp << std::endl;

    std::string temp1 = myMusic->displaySongInfo("Detlef", "Rock It");
    std::cout << temp1;

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

<<<<<<< HEAD
    //std::cout << "\n----Testing the removeSong----\n" << std::endl;
    //MusicLibrary* myMusic2 = new MusicLibrary(testLib);
    //myMusic2->removeSongs("extraSongs.csv");
    //myMusic2->displayAllSongs();
=======
    std::cout << "\n----Testing the removeSong----\n" << std::endl;
<<<<<<< HEAD
    MusicLibrary* myMusic2 = new MusicLibrary(testLib);
    myMusic2->removeSongs("extraSongs.csv");
    myMusic2->displayAllSongs();
**/


    srand(time(NULL));

    Playlist *allLists = new Playlist();
    allLists->newPlaylist("pl1");
    allLists->newPlaylist("pl2");

    std::string tempPL = allLists->getPlaylistName(1);
    std::cout << tempPL;
    std::cout << allLists->getPlaylistName(0) << std::endl;
    allLists->newPlaylist("Pl2");
    std::cout << allLists->getPlaylistName(1) << std::endl;

    MusicLibrary masterLib = MusicLibrary(readLibrary("testSongLib.csv"));

    //LinkedList* testList = readPlaylist("testSongLib.csv");
    //testList->sumDuration();

    Song tempSong = masterLib.findSongAtIndex(2);
    std::cout << "HERE" << std::endl;
    allLists->getPlaylist("pl1")->insertAtEnd(tempSong);
    tempSong = masterLib.findSongAtIndex(3);
    allLists->getPlaylist("pl1")->insertAtEnd(tempSong);
    allLists->getPlaylist("pl1")->sumDuration();
    allLists->getPlaylist("pl1")->toString();
    allLists->getPlaylist("pl1")->playNext(&masterLib);
    allLists->getPlaylist("pl1")->toString();

    std::cout<<masterLib.findSongAtIndex(2).getPlayCount()<<std::endl;


    allLists->newRandomPlaylist("RandomPlaylist", 1500, &masterLib);

    std::cout << allLists->getPlaylistName(2) << std::endl;
    std::cout << allLists->getCurrCount() << std::endl;
    try {
        std::cout << "CHECK" << std::endl;
        LinkedList *tempPL = allLists->getPlaylist("RandomPlaylist");
        int size = tempPL->getCurrentItemCount();

        for (int i = 0; i < size; i++) {
            Song songOut = tempPL->getValueAt(i);
            std::cout << songOut.toString() << std::endl;
        }
    }
    catch (std::invalid_argument) {
            std::cout << "inhere" << std::endl;
        }
   // ArrayList* testLib2;
    //testLib2 = readLibrary("testList.csv");
    //MusicLibrary* myMusic2 = new MusicLibrary(testLib2);
    //myMusic2->displayAllSongs();
    //myMusic->removeSongs("songss.csv.txt");
    //Song temp3 = myMusic->findSongAtIndex(0);
    //Song temp5 = myMusic->removeOneSong(temp3);
    //std::cout << temp5.toString() << "\n" << std::endl;

    //myMusic->displayAllSongs();

    //Playlist* allLists = new Playlist();
    //allLists->newPlaylist("pl1");

    //LinkedList* tempPL = allLists->getPlaylist("pl1");
    //tempPL->toString();

    //std::cout << "\n----Testing the newPlaylist----\n" << std::endl;
    //std::cout << "\n----Creating 3 playlists and getting them----\n" << std::endl;
    //Playlist* allLists2 = new Playlist();
    //allLists2->newPlaylist("pl2");
    //LinkedList* temppl2 = allLists2->getPlaylist("pl2");
    //temppl2->getName();
    //Playlist* allLists3 = new Playlist();
    //allLists3->newPlaylist("pl3");
    //LinkedList* temppl3 = allLists2->getPlaylist("pl3");
    //temppl3->toString();
    //Playlist* allLists4 = new Playlist();
    //allLists4->newPlaylist("pl4");
    //LinkedList* temppl4 = allLists2->getPlaylist("pl4");
    //temppl4->toString();




    //std::cout << "\n----Testing the newRandomPlaylist----\n" << std::endl;



}