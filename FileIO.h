//
// Created by Robert on 12/3/19.
//

#ifndef COMP220_TERMPROJECT_FILEIO_H
#define COMP220_TERMPROJECT_FILEIO_H

#include <string>
#include "Song.h"
#include "LinkedList.h"

/**
 * Reads in a csv file and returns a sorted linked list of songs
 * @param fileName
 * @return a pointer to a Linked List of songs to add to a playlist or library
 */
LinkedList* ReadFile(std::string fileName);

/**
 * Writes a playlist or library to fileName
 * @param fileName
 */
void WriteFile(std::string fileName);

#endif //COMP220_TERMPROJECT_FILEIO_H
