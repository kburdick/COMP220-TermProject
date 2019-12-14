//
// Created by Robert on 12/13/19.
//

#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"
#include "FileIO.h"
#include "Playlist.h"

int main(){
    srand(time(NULL));

    Playlist *allLists = new Playlist();
    allLists->newPlaylist("pl1");
    std::cout << allLists->getPlaylistName(0) << std::endl;
    allLists->newPlaylist("Pl2");
    std::cout << allLists->getPlaylistName(1) << std::endl;

    MusicLibrary masterLib = MusicLibrary(readLibrary("testSongLib.csv"));

    //LinkedList* testList = readPlaylist("testSongLib.csv");
    //testList->sumDuration();


    std::cout<<"----------------------------------------"<<std::endl;
    for (int i=0; i<masterLib.getItemCount(); i++){
        allLists->getPlaylist("pl2")->insertAtEnd(masterLib.findSongAtIndex(i));
    }
    std::cout<<"We are opening this Playlist and Calling to string: "<<allLists->getPlaylistName(2)<<std::endl;
    allLists->getPlaylist("pl2")->toString();
    std::cout<<"----------------------------------------"<<std::endl;

    Song tempSong = masterLib.findSongAtIndex(2);

    std::cout<<"----------------------------------------"<<std::endl;

    std::cout<<masterLib.findSongAtIndex(2).getPlayCount()<<std::endl;


    allLists->newRandomPlaylist("RandomPlaylist", 1500, &masterLib);

    std::cout << allLists->getPlaylistName(2) << std::endl;
    std::cout << allLists->getCurrCount() << std::endl;

    allLists->getPlaylist("RandomPlaylist")->toString();
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
}