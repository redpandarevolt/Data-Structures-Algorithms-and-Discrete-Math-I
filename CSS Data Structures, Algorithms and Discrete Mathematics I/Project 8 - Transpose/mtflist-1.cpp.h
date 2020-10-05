template<class Object>
int MtfList<Object>::find( const Object &obj ) {
  DListNode<Object> *top = DList<Object>::header->next;
  DListNode<Object> *found = top;

  for ( ; found != NULL && found->item != obj;  found = found->next )
    ++DList<Object>::cost;

  if ( found == NULL )
    return -1; // not found

  if ( found == top )
    return 0;  // no need to move to front

  // remove found from the current position
  found->prev->next = found->next;  // found->prev != null
  if ( found->next != NULL )
    found->next->prev = found->prev;

  // insert found between header and top
  found->next = top;                  
  top->prev = found;                // top != null
  found->prev = DList<Object>::header;
  DList<Object>::header->next = found;

  return 0;
}





