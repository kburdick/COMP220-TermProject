//
// Created by Kurt Burdick on 10/15/19.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include "ArrayList.h"
#include "ArrayLib.h"

ArrayList::ArrayList(int initialCapacity) {

    if (initialCapacity < 1){
        throw std::invalid_argument("In ArrayList constructor, size must be > 0");
    }

    this->currCapacity = initialCapacity;
    this->array = new Song[currCapacity];
    this->currItemCount = 0; //no valid items in the array
}

ArrayList::ArrayList(const ArrayList& arrayListToCopy) {
    this->currCapacity = arrayListToCopy.currCapacity;
    this->currItemCount = arrayListToCopy.currItemCount;
    this->array = new Song[currCapacity];
    //remember to populate the copied array
    for(int i = 0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i];
    }
}

ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy) {
    if(this != &arrayListToCopy) {
        delete [] array;

        this->currCapacity = arrayListToCopy.currCapacity;
        this->currItemCount = arrayListToCopy.currItemCount;
        this->array = new Song[currCapacity];
        //remember to populate the copied array
        for(int i = 0; i < currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }

    return *this;

}

ArrayList::~ArrayList(){
    delete [] array;
}

//file io stuff
//TODO write function description
void ArrayList::WriteFile(std::string fileName) {

}


int ArrayList::getDuration(Song songIn){
    int duration = songIn.getSongDuration();

    return duration;
}


void ArrayList::doubleCapacity() {
    int doubleCap = currCapacity * 2;

    Song* arrCopy = new Song[doubleCap];

    for(int i = 0; i < currCapacity; i++) {
        arrCopy[i] = array[i];
    }

    this->array = arrCopy;
}

void ArrayList::insertAtEnd(Song songToAdd) {
    if (currItemCount == currCapacity) {
        doubleCapacity();
        array[currItemCount] = songToAdd;
        currItemCount += 1;
    }
    else{
        array[currItemCount] = songToAdd;
        currItemCount += 1;
    }
}

void ArrayList::insertInOrder(Song songToAdd){

}


Song ArrayList::getValueAt(int index) {
    Song value;

    if (index == 0 & currItemCount == 0) {
        throw std::out_of_range("Bad index given to getValueAt: 0");
    }

    if(index >= currItemCount) {
        throw std::out_of_range("invalid index");
    }

    if (index < 0) {
        throw std::out_of_range("invalid index");
    }

    if (index >= 0 & index < currItemCount) {
        value = array[index];
        return value;
    }
}

void ArrayList::toString() {
    //TODO fix to string methods for song printing
    std::string arrString;

    for(int i = 0; i < currItemCount; i++){

        arrString = array[i].toString();
        std::cout << arrString << std::endl;
        arrString = "";
    }
}

bool ArrayList::isEmpty() {

    if(currItemCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

int ArrayList::getCurrentItemCount() {
    return currItemCount;
}

void ArrayList::clearList() {
    this->array = new Song[currCapacity];
    currItemCount = 0;
}

bool ArrayList::findSong(Song songToFind) {
    int unusedTimer = 0;

    int result = ::find(array, currItemCount, songToFind, unusedTimer);

    if(result == -1){
        return 0;
    }
    else{
        return 1;
    }
}

int ArrayList::findSongIndex(Song songToFind) {
    int unusedTimer = 0;

    return ::find(array, currItemCount, songToFind, unusedTimer);
}

int ArrayList::findSongByArtist(std::string artistIn){
    //TODO finish function implementation could be void?
    std::string artist = "";
    //std::string artist;
    int found = -1;

    for(int i = 0; i < currItemCount; i++) {
        Song temp = array[i];

        artist = temp.getSongArtist();
        //std::cout<< artist << std::endl;
       // std::cout<< artistIn << std::endl;



        std::cout << artist ;
        if(artist == artistIn){
            found = i;
            return found;
        }
    }
    return found;
}

int ArrayList::findSongByTitle(std::string titleIn){
    //TODO finish implementing this function

    std::string title = "";
    int found = -1;

    for(int i = 0; i < currItemCount; i++) {
        title = array[i].getSongTitle();

        if(title == titleIn) {
            found = i;
            return found;
        }

        title = "";
    }
    return found;
}


void ArrayList::insertAtFront(Song songToAdd) {
    int unusedTimer = 0;

    if(currItemCount == currCapacity) {
        doubleCapacity();
    }

    Song* arrCopy = new Song[currItemCount + 1];
    currItemCount += 1;

    for(int i = 0; i < currItemCount; i++) {
        if(i == 0){
            arrCopy[0] = songToAdd;
        }
        else{
            arrCopy[i] = array[i - 1];
        }
    }
    array = ::copyArray(arrCopy, currItemCount, unusedTimer);

    delete [] arrCopy;
}

void ArrayList::insertAt(Song songToAdd, int index) {
    int unusedTimer = 0;

    if(index < 0 || index > currItemCount) {
        throw std::out_of_range("No item to remove");
    }

    Song* arrCopy = new Song[currItemCount + 1];
    currItemCount += 1;

    for(int i = 0; i < currItemCount; i++) {

        if(i < index) {
            arrCopy[i] = array[i]; //TODO make sure this is actually copying songs?
        }

        if(i == index) {
            arrCopy[index] = songToAdd;
        }

        if(i > index) {
            arrCopy[i] = array[i - 1];
        }
    }

    array = copyArray(arrCopy, currItemCount, unusedTimer);

    delete [] arrCopy;
}

Song ArrayList::removeSongAtEnd() {
    int unusedTimer = 0;

    Song songCopy = array[currItemCount - 1];

    if (currItemCount <= 0 | currItemCount > currCapacity) {
        throw std::out_of_range("In removeValueAtEnd, List must have items");
    }

    Song* arrCopy = new Song[currItemCount - 1];
    currItemCount = currItemCount - 1;

    for(int i = 0; i < currItemCount; i++) {
        arrCopy[i] = array[i];
    }

    array = copyArray(arrCopy, currItemCount, unusedTimer);
    delete [] arrCopy;

    return songCopy;
}

Song ArrayList::removeSongAtFront() {
    int unusedTimer = 0;

    Song songCopy = array[0];

    if (currItemCount <= 0 | currItemCount > currCapacity) {
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }

    Song* arrCopy = new Song[currItemCount - 1];
    currItemCount = currItemCount - 1;

    for(int i = 0; i < currItemCount; i++) {
        arrCopy[i] = array[i + 1];
    }

    array = copyArray(arrCopy, currItemCount, unusedTimer);
    delete [] arrCopy;

    return songCopy;
}

Song ArrayList::removeSong(Song songToRemove) {
    int unusedTimer = 0;

    bool result = findSong(songToRemove);

    if(result == false) {
        throw std::out_of_range("Song not in library");
    }

    Song* arrCopy = new Song[currItemCount - 1];
    currItemCount = currItemCount - 1;
    Song songCopy;

    //TODO fix algorithm for removing song from the array list
    /**for(int i = 0; i <= currItemCount; i++) {
        if(i != array[i]) {
            arrCopy[i] = array[i];
        }
        else {
            indexCopy = array[index];
            arrCopy[i] = array[i + 1];
        }
    }
*/
    array = copyArray(arrCopy, currItemCount, unusedTimer);
    delete [] arrCopy;

    return songCopy;
}
