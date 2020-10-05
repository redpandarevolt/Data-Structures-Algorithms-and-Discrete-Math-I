template<class Object>
SList<Object>::SList( ) {
      init( );
}

template<class Object>
SList<Object>::SList( const SList &rhs ) {
      init( );
      *this = rhs;   // then assign rhs to this.
}

template<class Object> 
void SList<Object>::init( ) {
        for ( int i = 0; i < LEVEL; i++ ) {  // for each level
            // create the left most dummy nodes;
            header[i] = new SListNode<Object>;//dynamic allocation
            header[i]->prev = NULL;
            header[i]->down = ( i > 0 ) ? header[i - 1] : NULL;
            header[i]->up = NULL;
            if ( i > 0 ) header[i - 1]->up = header[i];

            // create the right most dummy nodes;
            header[i]->next = new SListNode<Object>;//dynamic allocation
            header[i]->next->next = NULL;
            header[i]->next->prev = header[i];
            header[i]->next->down = ( i > 0 ) ? header[i - 1]->next : NULL;
            header[i]->next->up = NULL;
            if ( i > 0 ) header[i - 1]->next->up = header[i]->next;
      }
    //srand(time(0));
    cost = 0;
}

template<class Object>
SList<Object>::~SList( ) {
    clear( );                             // delete items starting 1st
    for ( int i = 0; i < LEVEL; i++ ) {
        delete header[i]->next;           // delete the right most dummy
        delete header[i];                 // delete the left most dummy
    }
}

//deterimines if the list is empty
template<class Object>
bool SList<Object>::isEmpty( ) const {
    return (header[0]->next->next == NULL);
}

//returns size of linked list
template<class Object>
int SList<Object>::size( ) const {
    SListNode<Object> *p = header[0]->next; // at least the right most dummy
    int size = 0;

    for ( ; p->next != NULL; p = p->next, ++size );
    return size;
}

template<class Object>
void SList<Object>::clear( ) {
// for each level, iterate from the first to last item.
//cout<< "Going into clear function"<< endl;

     for ( int i = 0; i < LEVEL; i++ ) {
         SListNode<Object> *p = header[i]->next;
         while(p->next != NULL ){
             SListNode<Object> *del = p;
             p = p->next;
             delete del;
             del = NULL;
         }
         header[i]->next = p;
     }
}


template<class Object>
void SList<Object>::insert( const Object &obj ) {
  // right points to the level-0 item before which a new object is inserted.
    //cout<< "Going into Insert Method"<< endl;
    SListNode<Object> *right = searchPointer(obj);
    SListNode<Object> *up = NULL;
    
    if (right->next != NULL && right->item == obj )
        // there is an identical object
        return;
    
    // Implement the rest by yourself /////////////////////////

    //create a new node to insert
    SListNode<Object> *newPtr = new SListNode<Object>();
    newPtr->item = obj; //assign obj to item in new node

    //Take care of self connections first
    newPtr->next = right; //connect curr node to node on right
    newPtr->prev = right->prev; //connect curr node to prev

    //Take care of neighboring connections
    right->prev->next = newPtr;//connect prev node to curr
    right->prev = newPtr; //connect right node to curr
    
    newPtr->up = NULL;
    newPtr->down = NULL;
    
    //set maximum level to 6
    int curr_level = 0;//set current level to 0
    
    SListNode<Object> *tempPtr = newPtr; //use temp pointer to hold newPtr address
    //odd number then go up and insert
    while( rand() %2 == 1 && curr_level < LEVEL){
        //cout<<"entered while loop after rand"<< endl;
        
        SListNode<Object> *curr = tempPtr;
        //check to see if node has ->up
        while(curr->up == NULL /*&& curr->prev != NULL*/){
            curr= curr->prev; //if null move left
        }
        
        curr = curr->up;// move current up to level up from lower level.
        curr = curr->next;//move curr to the right*/

        SListNode<Object> *upLevelNode = new SListNode<Object>();
        upLevelNode->item = obj;
    
        upLevelNode->next = curr;         //connect curr node to node on right
        upLevelNode->prev = curr->prev;   //connect curr node to prev
    
        //Take care of neighboring connections
        curr->prev->next = upLevelNode;//connect prev node to curr
        curr->prev = upLevelNode;
    
        tempPtr->up = upLevelNode;
        upLevelNode->down = tempPtr;
        upLevelNode->up = NULL;
        tempPtr = upLevelNode;
        //newPtr = upLevelNode;

        curr_level++;
    }
}

template<class Object> 
bool SList<Object>::find( const Object &obj ) {
    // p oints to the level-0 item close to a given object
    SListNode<Object> *p = searchPointer( obj );

    return ( p->next != NULL && p->item == obj );     // true if obj was found
}

template<class Object>
SListNode<Object> *SList<Object>::searchPointer( const Object &obj ) {
    SListNode<Object> *p = header[LEVEL - 1];     // start from the top left
    while ( p->down != NULL ) {                   // toward level 0
        p = p->down;                                // shift down once
        cost++;

        if ( p->prev == NULL ) {                    // at the left most item
            if ( p->next->next == NULL )              // no intermediate items
                continue;
            else {                                    // some intermadiate items
                if ( p->next->item <= obj )             // if 1st item <= obj
                    p = p->next;                          // shift right to item 1
                cost++;
            }
    }

    while ( p->next->next != NULL && p->next->item <= obj ) {
      // shift right through intermediate items as far as the item value <= obj
        p = p->next;
        cost++;
    }
  }

  // now reached the bottom. shift right once if the current item < obj
  if ( p->prev == NULL || p->item < obj ) {
      p = p->next;
      cost++;
  }
  return p; // return the pointer to an item >= a given object.
}

template<class Object>
void SList<Object>::remove( const Object &obj ) {
    // p points to the level-0 item to delete
    SListNode<Object> *p = searchPointer( obj );

// validate if p is not the left most or right most and exactly contains the
    // item to delete
    if ( p->prev == NULL || p->next == NULL || p->item != obj )
        return;

  // Implement the rest by yourself /////////////////////////////////////////
    
    SListNode<Object> *del = p;
    while(del != NULL){
        del->next->prev = del->prev;
        del->prev->next = del->next;
        
        SListNode<Object> *upPtr = del->up;
        delete del;
        del = NULL;

        del = upPtr;
    }
}

template<class Object>
const SList<Object> &SList<Object>::operator=( const SList &rhs ) {
    if ( this != &rhs ) { // avoid self-assignment
        clear( );           // deallocate old items
    
        int index;
        SListNode<Object> *rnode;
        for ( index = 0, rnode = rhs.header[0]->next; rnode->next != NULL;
             rnode = rnode->next, ++index )
            insert( rnode->item );

        cost = rhs.cost;
        
    }
    return *this;
}

template<class Object>
int SList<Object>::getCost( ) const {
    return cost;
}

template<class Object>
void SList<Object>::show( ) const {
    cout << "contents:" << endl;
    for ( SListNode<Object> *col = header[0]; col != NULL; col = col->next ) {
        SListNode<Object> *row = col;
        for ( int level = 0; row != NULL && level < LEVEL; level++ ) {
            if ( row->prev == NULL )
                cout << "-inf\t";
            else if ( row->next == NULL )
                cout << "+inf\t";
            else
                cout << row->item << "\t";
            row = row->up;
        }
        cout << endl;
    }
}


