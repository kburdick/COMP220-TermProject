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

    std::cout << "\n create linkedlist to test import...\n" << std::endl;

    LinkedList* testList;

    std::cout << "\n------------------------------" << std::endl;
    std::cout << "----Read File to Test List----" << std::endl;
    std::cout << "------------------------------\n" << std::endl;

    testList = ReadFile("readIn.csv");


    std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << "----To String Should Print Same information from the file----" << std::endl;
    std::cout << "-------------------------------------------------------------\n" << std::endl;

    testList->toString();
}