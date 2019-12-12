//
// Created by Kurt Burdick on 9/24/19.
// modified 12/10/19
//

#include <iostream>
#include <string>
#include "Song.h"

int genRandInt(int min, int max, int& numLinesRun) {
    int randomNumber{};
    numLinesRun += 3;
    numLinesRun += 1;

    //check if actual parameters are passed in incorrectly (min is max and vice-versa)
    if(min > max){
        randomNumber = rand()%(min - max + 1) + max;
        numLinesRun += 1;
    }
    else{
        randomNumber = rand()%(max - min + 1) + min;
        numLinesRun += 1;
    }

    numLinesRun += 1;
    return randomNumber;
}

//TODO make a function to generate a random array that does not repeat numbers
int* genRandArray(int size, int min, int max, int& numLinesRun) {

    int* randArray = new int[size];
    numLinesRun += 4;
    numLinesRun += 2;

    for(int i = 0; i < size; i++){
        randArray[i] = genRandInt(min, max, numLinesRun);
        numLinesRun += 3;
    }

    numLinesRun += 1;
    return randArray;
}


// this function is tail recursive
std::string toString(const int* arrayPtr, int size, int i, std::string currentString){
    std::string arrString;
    arrString += currentString;
    //updates the string to contain the next values and allows it to be passed the the next function call

    if(size < 1){
        arrString += "}";
        return arrString;
    }

    if(size == 1){
        arrString += std::to_string(arrayPtr[i]);
    }

    else {
        arrString += std::to_string(arrayPtr[i]) + ", ";
    }

    return toString(arrayPtr, size - 1, i + 1, arrString);
}

//stub function for toString
std::string toString(const int* arrayPtr, int size){
    return toString(arrayPtr, size, 0, "{");
}


//tail recursion
int find(Song* const arrayPtr, int size, Song songToFind, int index, int &numLinesRun){
    numLinesRun += 6;
    if(size < 1){
        numLinesRun += 1;
        return -1;
    }

    else{
        std::string songString = songToFind.getSongTitle();

        Song songInArray = arrayPtr[index];
        std::string arrString = songInArray.getSongTitle();
        numLinesRun += 1;
        //TODO fix equivalent evaluation for songs from the array
        // possibly add a new function to compare?
        if(arrString == songString){
            numLinesRun += 1;
            return index;
        }
        else{
            numLinesRun += 1;
            return find(arrayPtr, size - 1, songToFind, index + 1, numLinesRun);
        }
    }
}

//stub function for find
int find(Song* const arrayPtr, int size, Song songToFind, int &numLinesRun){
    numLinesRun += 5;
    return find(arrayPtr, size, songToFind, 0, numLinesRun);
}


//tail recursive
int findLast(const int* const arrayPtr, const int size, const int numToFind, int &numLinesRun){

    numLinesRun += 5;
    if(size < 1){
        numLinesRun += 1;
        return -1;
    }
    else {

        numLinesRun += 1;
        if (arrayPtr[size - 1] == numToFind) {
            numLinesRun += 1;
            return size -1;
        }
        else {
            numLinesRun += 1;
            return findLast(arrayPtr, size - 1, numToFind, numLinesRun);
        }
    }
}


//this function implements tail recursion
int findMaxIndex(const int* const arrayPtr, const int size, int index, int maxInd, int &numLinesRun){

    numLinesRun += 6;
    if(size == 0){
        numLinesRun += 1;
        throw std::invalid_argument("Array size must be > 0");
    }

    numLinesRun += 1;
    if(index == size) {
        numLinesRun += 1;
        return maxInd;
    }

    numLinesRun += 1;
    if(arrayPtr[index] > arrayPtr[maxInd]){
        numLinesRun += 1;
        maxInd = index;
    }

    numLinesRun += 1;
    return findMaxIndex(arrayPtr, size, index + 1, maxInd, numLinesRun);
}

//stub function to match interface from header file
int findMaxIndex(const int* const arrayPtr, const int size, int &numLinesRun){
    numLinesRun += 4;
    return findMaxIndex(arrayPtr, size, 0, 0, numLinesRun);
}


Song* copyArray(const Song* arrayToCopy, int size, int& numLinesRun){
    numLinesRun += 3;

    const Song* origArray = arrayToCopy;
    Song* newArray = new Song[size];
    numLinesRun += 2;
    numLinesRun += 2;

    for(int i = 0; i < size; i++){
        newArray[i] = origArray[i];
        numLinesRun += 3;
    }

    numLinesRun += 1;
    return newArray;
}


int* genShuffledArray(int size, int& numLinesRun){
    int* newArray =  new int[size];
    int temp = 0;
    int randomIndex = 0;
    numLinesRun += 5;

    numLinesRun += 1;
    if(size == 0){
        newArray = nullptr;
        numLinesRun += 1;
    }

    numLinesRun += 2;
    //create array
    for(int i = 0; i < size; i++) {
        newArray[i] = i + 1;
        numLinesRun += 3;
    }

    numLinesRun += 2;
    //shuffles the array
    for(int i = 0; i < size; i++) {
        randomIndex = rand() % size;

        //could benefit from a swap variable function...
        temp = newArray[i];
        newArray[i] = newArray[randomIndex];
        newArray[randomIndex] = temp;
        numLinesRun += 7;
    }

    numLinesRun += 1;
    return newArray;
}


int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int total = 0;
    numLinesRun += 5;

    numLinesRun += 2;
    for(int i = 0; i < size; i++){

        numLinesRun += 1;
        if(arrayPtr[i] == numToFind){
            total += 1;

            numLinesRun += 1;
        }
        numLinesRun += 2;

    }

    numLinesRun += 1;
    return total;
}


void sort(int* arrayToSort, int size, int& numLinesRun){
    //this is a bubble sort with O(n^2)
    int i, j;
    int swap = 0;
    numLinesRun += 5;

    numLinesRun += 2;
    for (i = 0; i < size - 1; i++){

        // Last i elements are already in place
        numLinesRun += 2;
        for (j = 0; j < size - i - 1; j++){

            numLinesRun += 1;
            if (arrayToSort[j] > arrayToSort[j + 1]){
                //again this would benefit from the swap function
                swap = arrayToSort[j + 1];
                arrayToSort[j + 1] = arrayToSort[j];
                arrayToSort[j] = swap;

                numLinesRun += 3;
            }

            numLinesRun += 2;
        }

        numLinesRun += 2;
    }
}


// tail recursion
int binFind(const int* const arrayPtr, const int size, const int numToFind, int low, int high, int &numLinesRun) {

    //proper base/test case use if the low index is not equal to the high index then,
    // it did not find the number in the array
    numLinesRun += 7;
    if (low <= high) {


        //int division automatically truncates the decimal (rounds down if odd element array)
        int midpoint = (low + high) / 2;

        numLinesRun += 2;
        if (numToFind == arrayPtr[midpoint]) {
            numLinesRun += 2;
            return midpoint;
        }

        numLinesRun += 1;
        if (numToFind < arrayPtr[midpoint]) {
            numLinesRun += 1;
            return binFind(arrayPtr, midpoint, numToFind, low, midpoint - 1, numLinesRun);
        } else {
            numLinesRun += 1;
            return binFind(arrayPtr, midpoint, numToFind, midpoint + 1, high, numLinesRun);
        }
    }

    else{
        numLinesRun += 1;
        return -1;
    }
}

//stub function for binary search
int binFind(const int* const arrayPtr, const int size, const int numToFind, int &numLinesRun){
    numLinesRun += 5;
    return binFind(arrayPtr, size, numToFind, 0, size - 1, numLinesRun);
}


int* merge(const int* a1, int size1, const int* a2, int size2, int& numLinesRun) {
    int i = 0;
    int j = 0;
    int k = 0;
    numLinesRun += 8;

    int* mergeArr = new int[size1 + size2];

    numLinesRun += 2;
    if(size1 + size2 == 0) {
        numLinesRun += 1;
        return nullptr;
    }

    numLinesRun += 1;
    while (i < size1 && j < size2) {

        numLinesRun += 1;
        if (a1[i] <= a2[j]) {
            mergeArr[k] = a1[i];
            i++;

            numLinesRun += 2;

        }

        else {
            mergeArr[k] = a2[j];
            j++;

            numLinesRun += 2;
        }
        k++;
        numLinesRun += 1;
    }

    numLinesRun += 1;
    if (i < size1) {

        numLinesRun += 2;
        for (int p = i; p < size1; p++) {
            mergeArr[k] = a1[p];
            k++;
            numLinesRun += 3;
        }

    }

    else {

        numLinesRun += 2;
        for (int p = j; p < size2; p++) {

            mergeArr[k] = a2[p];
            k++;
            numLinesRun += 3;
        }

    }
    numLinesRun += 1;

    return mergeArr;
}


Song* mergeSort(const Song* arrayToSort, int size, int& numLinesRun){
    //TODO fix function for merge sort and add the number of lines run
    // not sure why this is not working
    int rightInd = size - 1;
    int leftInd = 0;

    int middle = (leftInd + rightInd) / 2;
    int leftSize = middle;
    int rightSize = (size - middle) - 1;

    Song* leftArr = nullptr;
    Song* rightArr = nullptr;
    Song* finalArr = nullptr;

    if (size == 1){
        finalArr = copyArray(arrayToSort, size, numLinesRun);
        return finalArr;
    }

    if (leftSize < rightSize) {

        leftArr = mergeSort(arrayToSort, leftSize, numLinesRun);

        rightArr = mergeSort(arrayToSort, rightSize, numLinesRun);
    }

    //finalArr = merge(leftArr, leftSize, rightArr, rightSize, numLinesRun);

    return finalArr;
}
