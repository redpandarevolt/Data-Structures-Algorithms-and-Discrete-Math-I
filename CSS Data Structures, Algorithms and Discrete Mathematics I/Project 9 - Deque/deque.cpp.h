template <class Object>
Deque<Object>::Deque( ) {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque( ) {                         // the destructor
  clear( );
}

template <class Object>
bool Deque<Object>::isEmpty( ) const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size( ) const {                 // retrieves # deque nodes
    int i = 0;
    for (DequeNode *ptr = front; ptr != NULL; ptr = ptr->next) {// traverse que
        ++i;
    }
    return i;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    //retrieve the back node
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
  while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
    removeFront( );
}

template <class Object>
void Deque<Object>::addFront( const Object &obj ) {// add a new node to  front
  // Implement the function body.
    DequeNode *newPtr = new DequeNode;  //initiate a new node
    newPtr->item = obj;                 //assign obj to the item of the node
    newPtr->next = front;               //connect node to front node
    newPtr->prev = NULL;                //set newPtr->prev to Null as a front
    
    if(isEmpty())                       //on empty list set new node to back
        back = newPtr;
    else
        front->prev = newPtr;           //connent neighboring node to new node
    front = newPtr;                     // re assing front to newPtr
}
template <class Object>
void Deque<Object>::addBack( const Object &obj ) { // add a new node to tail
  // Implement the function body.
    DequeNode *newPtr = new DequeNode;  //initiate a new node
    newPtr->item = obj;                 //assign obj to the item of the node
    newPtr->next = NULL;                //set newPtr->next to Null as a back
    newPtr->prev = back;                //connect node to back node
    
    if(isEmpty())                       //if empty assign front to newPtr
        front = newPtr;
    else
        back->next = newPtr;            //connect back node to new node
    back = newPtr;                      //assign newPtr to be the new back node
}

template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
  // Implement the function body.
    Object frontItem = getFront();      //hold the item to be returned
    DequeNode *old = front;             //create a pointer to the front
    
    if(front == back){                  // there is only one node;
        front = NULL;                   //remove pointer to NULL
        back = NULL;
    }
    else {
        front = front->next;    //assign the front to node after removed node
        front->prev = NULL;     //assign the new front prev to NULL
    }
    delete old;                 //delete the old node
    return frontItem;           //return the item that was removed.
}

template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node
  // Implement the function body.
    Object backItem = getBack();    //hold item being removed
    DequeNode *old = back;          //create a pointer to the back
    
    if(front == back){              // there is only one node;
        front = NULL;               //assign removed node pointers to NULL.
        back = NULL;
    }
    else {
        back = back->prev;  //reassign back to node ahead of removed node
        back->next = NULL;  //set pointer from back to NULL
    }
    delete old;                     //remove old node.
    return backItem;                //return removed item.
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
  if ( this != &rhs ) { // avoid self assignment
    clear( );
    for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
      addBack( rptr->item );
  }
  return *this;
}


