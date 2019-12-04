//
// created by Kurt Burdick 11/25/19.
// modified by Kurt Burdick 12/2/19.
//

#include <iostream>
#include "LinkedList.h"

/**
     * Constructor
     */
LinkedList::LinkedList() {
    //creates an empty list
    this->head = nullptr;
    this->tail = nullptr;
    this->currItemCount = 0;
}

//Destructor
LinkedList::~LinkedList(){
    while (head != nullptr) {
        LinkedNode* temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = nullptr;
    currItemCount = 0;
}

/**
    * appends the new song to the end of the list
    * @post the list has an additional song in it, at the end
    */
void LinkedList::insertAtEnd(Song songToAdd) {
    LinkedNode* newNode = new LinkedNode(songToAdd);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        currItemCount += 1;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
        currItemCount += 1;
    }
}



/**
     * gives a string representation of the current list
     * @returns null
     * @post displays all songs to the current console
     */
void LinkedList::toString(){
    LinkedNode* current = head;

    while(current != nullptr) {

        std::cout << current->getItem().toString() << '\n';

        current = current->getNext();
    }
}


/**
     * checks if there are any valid songs in the list
     * @return true if there are no valid songs in the list, false otherwise
     */
bool LinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

/**
    * makes the list empty of valid songs
    * @post the list is empty, such that isEmpty() == true
    */
void LinkedList::clearList() {
    while (head != nullptr) {
        LinkedNode *temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = nullptr;
    currItemCount = 0;

}

/**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
bool LinkedList::findSong(Song songToFind) {
    LinkedNode* current = head;

    int index = 0;

    while(current != nullptr) {

        if(current->getItem().getSongTitle() == songToFind.getSongTitle()){
            return 1;
        }

        index++;
        current = current->getNext();
    }
    return 0;
}

/**
   * Searches a song list for a certain song
   * @return index of the song in the list, -1 if the song is not present
   */
int LinkedList::findSongByArtist(std::string artistIn){
    LinkedNode* current = head;

    int index = 0;

    while(current != nullptr) {

        if(current->getItem().getSongArtist() == artistIn){
            return index;
        }

        index++;
        current = current->getNext();
    }

    return -1;
}

/**
* Searches a song list for a certain song
* @return index of the song in the list, -1 if the song is not present
*/
int LinkedList::findSongByTitle(std::string titleIn){
    LinkedNode* current = head;

    int index = 0;

    while(current != nullptr) {

        if(current->getItem().getSongTitle() == titleIn){
            return index;
        }

        index++;
        current = current->getNext();
    }

    return -1;

}


/**
     * removes the song from the list, and returns a copy of that song
     * @param the song from which to remove the song
     * @post the song is removed from the list if found, everything else is shifted down one
     * @return a copy of the song at index
     * @throws out_of_range exception if song is invalid, prints the song it could not find
     */
Song LinkedList::removeSong(Song songToRemove) {
    //TODO write this function to remove songs from the list/playlist

    if(head == nullptr || currItemCount == 0){
        throw std::out_of_range("In removeSong, List must have items");
    }

    else {
        LinkedNode *current = head;
        bool songFound;
        int count = 0;
        Song songValue;

        while (count < currItemCount) {
            songFound = findSong(songToRemove);

            if (songFound == 1) {
                LinkedNode *temp = current->getNext();

                current->setNext(temp->getNext());
                songValue = temp->getItem();
                delete temp;
            }

            current = current->getNext();
            count++;
        }
        currItemCount -= 1;

        return songValue;
    }
}

/**
    * sorts the list for alphabetical order of artists and then songs
    * @param none
    * @post the songs in the list are sorted alphabetically
    * @return none
    */
void LinkedList::sortList() {
    //TODO write this function to sort the list alphabetically
    //LinkedNode* current = head;
  //  std::string firstArtist = current->getItem().getSongArtist();
//    std::string firstSong = current->getItem().getSongTitle();
    //while(current != nullptr){

    //}

}


/**
    * shuffles the list to be in random order
    * @param none
    * @post the list is shuffled out of order
    */
void LinkedList::shuffle() {
    //TODO used for the playlist class.
}