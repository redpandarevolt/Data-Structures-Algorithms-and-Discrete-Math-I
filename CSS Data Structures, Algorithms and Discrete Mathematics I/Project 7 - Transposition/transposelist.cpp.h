//
//  TransposeList.cpp.h
//  
//  Created by Marcela on 11/20/18.
//  Copyright © 2018 Marcela. All rights reserved.
//
//using namespace std;
template<class Object>
int TransposeList<Object>::find(const Object &obj ) {
DListNode<Object> *found = DList <Object> :: header->next;
    
    int i = 0;
    for ( ; found != NULL && found->item != obj;  found = found->next, ++i )
        ++DList<Object> ::cost;
    
    if (found == NULL){
        return -1; // not found
    }
    
    if (found == DList<Object>::header->next ){
        return 0;  // no need to swap
    }
    // remove found from the current position
    DList<Object>*prevNode = found->prev;
    prevNode->next = found->next;
    
    if (found->next != NULL)
        found->next->prev = prevNode;


        // insert found before previous
        found->next = prevNode;
        found->prev = prevNode->prev;
    
        prevNode->prev = found;
        found->prev->next = found;
    
    return i;

}
