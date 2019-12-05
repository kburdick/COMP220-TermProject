//
// Created by Robert on 12/4/19.
//

#include "FileIO.h"
#include <fstream>
#include <exception>
#include "LinkedList.h"
#include <iostream>


/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to a Linked List of songs to add to a playlist or library
 */
LinkedList* ReadFile(std::string fileName){
    LinkedList* lib = new LinkedList();
    std::ifstream infile(fileName);
    if (infile){
        std::string line;
        while (infile){
            line = "";
            getline(infile, line); //Strafes csv for full line. This should match songString format
            std::cout<<line<<std::endl;
            Song temp = Song(line);
            lib->insertAtEnd(temp);
        }
        return lib;
    }
    else {
        throw "File Not Found!";
    }
}


/**
void WriteFile(std::string fileName, LinkedList* songList){
    std::ofstream outFile(fileName);
    LinkedNode* current  = songList->head;
    if (outFile){
        while (!songList->isEmpty()){

        }
    }
}
**/