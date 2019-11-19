//
// Created by Toby Dragon on 10/30/18.
// modified by Kurt Burdick 11/5/19.
//

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
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
 // function has big O(1)
void LinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);

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
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 // function has a big O(n)
int LinkedList::getValueAt(int index){
    int value;

    if(index == 0 & currItemCount == 0) {
        throw std::out_of_range("bad index");
    }

    if(index < 0) {
        throw std::out_of_range("Bad index");
    }

    if(index >= currItemCount){
        throw std::out_of_range("bad index");
    }

    else {
        LinkedNode* current = head;
        int count = 0;

        while (current != nullptr) {

            if (count == index) {
                value = (current->getItem());
                return value;
            }

            count++;
            current = current->getNext();
        }
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
 // function has big O(n)
std::string LinkedList::toString(){
    std::string listString = "{";

    if(head == nullptr){
        listString += "}";
        return listString;
    }

    else {
        LinkedNode* current = head;
        int count = 0;

        while(current != nullptr) {
            if(count == currItemCount - 1) {
                listString += std::to_string(current->getItem()) + "}";
                return listString;
            }
            else{
                listString = listString + std::to_string(current->getItem()) + ", ";
            }
            count++;
            current = current->getNext();
        }
        return listString;
    }
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
 // function has big O(1)
bool LinkedList::isEmpty(){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
 //function has big O(1)
int LinkedList::itemCount(){
    return currItemCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
 //function has O(n)
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
 //function has big O(n)
int LinkedList::find(int numToFind){
    LinkedNode* current = head;

    int index = 0;

    while(current != nullptr) {

        if(current->getItem() == numToFind){
            return index;
        }

        index++;
        current = current->getNext();
    }
    return -1;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
 //function has big O(n)
int LinkedList::findLast(int numToFind){
    LinkedNode* current = head;

    int index = -1;
    int count = 0;

    while(current != nullptr) {

        if(current->getItem() == numToFind){
            index = count;
        }

        count++;
        current = current->getNext();
    }

    return index;
}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */
 // function has big O(n)
int LinkedList::findMaxIndex(){

    if(currItemCount == 0) {
        throw std::out_of_range("bad index");
    }

    LinkedNode* current = head;

    int index = -1;
    int count = 0;
    int maxValue = head->getItem();

    while(current != nullptr) {

        if(current->getItem() >= maxValue) {
            maxValue = current->getItem();
        }

        count++;
        current = current->getNext();
    }

    current = head;
    int count2 = 0;

    for(int i = 0; i < currItemCount; i++) {

        if(current->getItem() == maxValue){
            index = count2;
            return index;
        }
        else {
            count2++;
            current = current->getNext();
        }
    }
}



/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
 //function has big O(1)
void LinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        currItemCount += 1;
    }
    else {
        newNode->setNext(head);
        head = newNode;
        currItemCount += 1;
    }
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
 // function has big O(n)
void LinkedList::insertAt(int itemToAdd, int index) {

    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("bad index");
    }

    if(index == 0){
        return insertAtFront(itemToAdd);
    }

    if(index == currItemCount){
        return insertAtEnd(itemToAdd);
    }

    else {
        LinkedNode *current = head;
        int count = 0;

        while(count != index) {

            if(count == (index - 1)){
                LinkedNode* newNode2 = new LinkedNode(itemToAdd);

                newNode2->setNext(current->getNext());
                current->setNext(newNode2);

            }

            current = current->getNext();
            count++;
        }
    }
    currItemCount += 1;
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
 // function has big O(n)
int LinkedList::removeValueAtEnd(){

    if(head == nullptr || currItemCount == 0){
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }

    if (currItemCount == 1) {
        LinkedNode* item = head;

        int val1 = item->getItem();

        delete item;

        head = nullptr;
        tail = nullptr;

        currItemCount = 0;

        return val1;
    }

    else {
        LinkedNode *lastItem = tail;
        LinkedNode *current = head;
        int count = 0;
        int value;

        while (current->getNext() != nullptr) {

            if (current->getNext() == tail) {
                value = tail->getItem();

                tail = current;
                current->setNext(nullptr);

                delete lastItem;
            }

            else {
                count++;
                current = current->getNext();
            }
        }
        currItemCount -= 1;
        return value;
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
 // function has big O(1)
int LinkedList::removeValueAtFront(){
    if(head == nullptr){
        throw std::out_of_range("no item to remove");
    }

    LinkedNode* nextItem = head->getNext();
    LinkedNode* currentFront = head;

    int value = head->getItem();

    this->head = nextItem;
    delete currentFront;
    currItemCount = currItemCount - 1;

    return value;
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //function has big O(n)
int LinkedList::removeValueAt(int index){

    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("bad index");
    }

    if(index == 0){
        return removeValueAtFront();
    }

    if(index == currItemCount){
        return removeValueAtEnd();
    }

    else {
        LinkedNode *current = head;
        int count = 0;
        int value = 0;

        while(count != index) {

            if(count == (index - 1)){
                LinkedNode* temp = current->getNext();

                current->setNext(temp->getNext());
                value = temp->getItem();
                delete temp;
            }

            current = current->getNext();
            count++;
        }
        currItemCount -= 1;
        return value;
    }
}
