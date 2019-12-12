//
// Created by Robert on 12/3/19.
//

#ifndef COMP220_TERMPROJECT_FILEIO_H
#define COMP220_TERMPROJECT_FILEIO_H

#include <string>
#include "Song.h"
#include "List.h"
#include "LinkedList.h"
#include "ArrayList.h"

/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to a Linked List of song pointers to add to a playlist
 */
LinkedList* readPlaylist(std::string fileName);

/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to an arrayList of songs to add to the library
 */
ArrayList* readLibrary(std::string fileName);


/**
 * Writes a playlist or library to fileName
 * @param fileName
 */
 //TODO bring this function back into this file instead of in linkedlist.cpp?
//void WriteFile(std::string fileName, * songList);

#endif //COMP220_TERMPROJECT_FILEIO_H
