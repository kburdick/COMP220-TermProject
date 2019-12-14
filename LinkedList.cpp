//
// created by Kurt Burdick 11/25/19.
// modified by Kurt Burdick 12/2/19.
//

#include <iostream>
#include "LinkedList.h"
#include "MusicLibrary.h"

/**
     * Constructor
     */
LinkedList::LinkedList() {
    //creates an empty list
    this->name = "";
    this->head = nullptr;
    this->tail = nullptr;
    this->currItemCount = 0;
}

LinkedList::LinkedList(std::string name){
    this->name = name;
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

LinkedList::LinkedList(const LinkedList& arrayListToCopy){
    this->name = arrayListToCopy.name;
    this->head = arrayListToCopy.head;
    this->tail = arrayListToCopy.tail;
    this->currItemCount = arrayListToCopy.currItemCount;

    while (head != nullptr) {
        LinkedNode* temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = nullptr;
    currItemCount = 0;
}

LinkedList &LinkedList::operator=(const LinkedList& arrayListToCopy) {
    if(this != &arrayListToCopy){
        this->name = arrayListToCopy.name;
        this->head = arrayListToCopy.head;
        this->tail = arrayListToCopy.tail;
        this->currItemCount = arrayListToCopy.currItemCount;
    }
    return *this;
}

/**
    * get the song duration
    * @param songIn input parameter
    */
int LinkedList::getDuration(Song songIn) {
    int duration = songIn.getSongDuration();

    return duration;
};


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
     * adds a new song to the list in alphabetical order by artist and then by song
     * @param songToAdd song to add to the list
     * @post song is added in order and the library will be sorted for lookup
     */
void LinkedList::insertInOrder(Song songToAdd){}

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

void LinkedList::WriteFile(std::string fileName){
    std::ofstream outFile(fileName);
    LinkedNode* current = head;
    if (outFile){
        while (current != nullptr){
            outFile << current->getItem().toString() << '\n';
            current = current->getNext();
        }
    }
    else{
        throw "File Not Found";
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
    if(head == nullptr || currItemCount == 0){
        throw std::out_of_range("In removeSong, List must have items");
    }
    int index = findSong(songToRemove);
    LinkedNode* currNode = head;
    LinkedNode* previousNode = nullptr;
    for(int i = 0; i<index; i++){
        previousNode = currNode;
        currNode = currNode->getNext();
    }
    Song songToReturn = currNode->getItem();
    LinkedNode* next = currNode->getNext();
    delete currNode;
    previousNode->setNext(next);
    currItemCount -= 1;
    return songToReturn;
}


/**
 * determines the total amount of items within the list
 * @param none
 * @return the total amount of items within the list
 */
int LinkedList::getCurrentItemCount(){
    return currItemCount;
}

Song LinkedList::getValueAt(int index){
    Song newSong = Song("");
    return newSong;
}

void LinkedList::insertAtFront(Song songToAdd){
}

void LinkedList::insertAt(Song songToAdd, int index){
}

Song LinkedList::removeSongAtEnd(){
    Song newSong = Song("");
    return newSong;
}

Song LinkedList::removeSongAtFront(){
    if (head == nullptr){
        throw("Playlist is empty");
    }
    LinkedNode* newHead = head->getNext();
    Song song = head->getItem();
    delete head;
    head = newHead;
    return song;
}

int LinkedList::findSongIndex(Song songToFind){
    std::string title = songToFind.getSongTitle();
    return findSongByTitle(title);
}

/**
* sums the total duration of the playlist
* @post the total duration in seconds of the playlist
*/
void LinkedList::sumDuration(){
    int sumDuration = 0;
    LinkedNode* curr = head;
    while (curr != nullptr){
        sumDuration += curr->getItem().getSongDuration();
        curr = curr->getNext();
    }
    std::cout<<sumDuration<<"\n";
}

/**
* Prints information about the next song in the playlist
* Removes the desired song from the playlist
* Adds one to the play count of that song in the library
* If the playlist is empty, then remove the playlist
* @param the name of the song
* @post all of the information about the song is displayed to the user
*/
void LinkedList::playNext(MusicLibrary* library){
    if (this->isEmpty()){
        delete(this);
    }
    Song song = head->getItem();
    Song* libSong = library->findSong(song);
    libSong->updatePlayCount();
    removeSongAtFront();
}

std::string LinkedList::getName(){
    return name;
}
