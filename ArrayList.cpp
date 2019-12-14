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


void ArrayList::WriteFile(std::string fileName) {
    std::ofstream outFile(fileName);
    if (outFile){
        for (int i=0; i < currItemCount; i++){
            outFile << array[i].toString() << '\n';
        }
    }
    else{
        throw "File Not Found";
    }
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
    currCapacity = doubleCap;
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
    std::string artist = songToAdd.getSongArtist();
    std::string title = songToAdd.getSongTitle();
    if (this->isEmpty()){
        this->insertAtEnd(songToAdd);
        return;
    }
    else{
        for(int i = 0; i < currItemCount; i++){
            if (artist < array[i].getSongArtist()){
                this->insertAt(songToAdd,i);
                return;
            } else if (artist == array[i].getSongArtist()){
                if (title < array[i].getSongTitle()){
                    this->insertAt(songToAdd,i);
                    return;
                }
            }
        }
    }
    insertAtEnd(songToAdd);
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
    std::string artist = "";
    //std::string artist;
    int found = -1;

    for(int i = 0; i < currItemCount; i++) {
        Song temp = array[i];

        artist = temp.getSongArtist();
        if(artist == artistIn){
            found = i;
            return found;
        }
    }
    return found;
}

int ArrayList::findSongByTitle(std::string titleIn){
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
    if (currItemCount == currCapacity){
        doubleCapacity();
    }
    for (int i=0; i<currItemCount+1; i++){
        Song temp = array[i];
        array[i] = songToAdd;
        songToAdd = temp;
    }
    currItemCount++;
}

void ArrayList::insertAt(Song songToAdd, int index) {
    if (index < 0 or index > currItemCount) {
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    if (currItemCount == currCapacity) {
        doubleCapacity();
    }
    if (index < currItemCount) {
        for (int i = index; i < currItemCount + 1; i++) {
            Song temp = array[i];
            array[i] = songToAdd;
            songToAdd = temp;
        }
        currItemCount++;
    }
    else{
        insertAtEnd(songToAdd);
    }
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

/**
 * removes the Song from Master Library and returns it as a Song Object
 * @param Song object to remove
 * @post the array of songs is shifted to compensate for the loss
 * @return the song
 * @throws out_of_range exception if index is invalid
 */
Song ArrayList::removeSong(Song songToRemove) {
    if (isEmpty()){
        throw std::out_of_range("No item to remove");
    }
    int index = findSongIndex(songToRemove);
    //std::cout << index << std::endl;
    Song toReturn = array[index];
    for (int i = index; i < currItemCount-1; i++){
        array[i] = array[i+1];
    }
    currItemCount += -1;
    return toReturn;
}

