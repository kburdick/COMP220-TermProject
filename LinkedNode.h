//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Song.h"

class LinkedNode {

private:
    Song item;
    LinkedNode* next;

public:
    LinkedNode(Song item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    Song getItem();
    LinkedNode* getNext();
    void setItem(Song newSong);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
