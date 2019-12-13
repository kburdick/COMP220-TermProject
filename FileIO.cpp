//
// Created by Robert on 12/4/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include "FileIO.h"
#include "LinkedList.h"


/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to a Linked List of songs to add to a playlist or library
 */
LinkedList* readPlaylist(std::string fileName){
    std::ifstream infile(fileName);

    if (infile){
        LinkedList* playlist = new LinkedList();
        std::string line;
        std::stringstream splitter(line);

        while (getline(infile, line)){

            Song temp = Song(line);
            playlist->insertAtEnd(temp);
            getline(splitter, line, '\n');

        }

        return playlist;
    }
    else {
        throw "File Not Found!";
    }
}

/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to a Linked List of songs to add to a playlist or library
 */
ArrayList* readLibrary(std::string fileName){
    std::ifstream infile(fileName);

    if (infile){
        ArrayList* library = new ArrayList(100);
        std::string line;
        std::stringstream splitter(line);

        while (getline(infile, line)){

            Song temp = Song(line);
            library->insertInOrder(temp);
            getline(splitter, line, '\n');

        }

        return library;
    }
    else {
        throw "File Not Found!";
    }
}