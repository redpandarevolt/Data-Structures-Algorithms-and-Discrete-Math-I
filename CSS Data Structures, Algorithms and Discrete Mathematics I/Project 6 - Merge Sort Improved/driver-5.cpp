#include <iostream>
#include <vector>
#include <stdlib.h>
#include "mergeImproved.cpp"


// array initialization with random numbers
void initArray(vector<int> &array, int randMax) {
  int size = array.size( );

  for (int i = 0; i < size; ) {
    int tmp = (randMax == -1) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if (array[j] == tmp) {
        hit = true;
        break;
      }
    }
    if (hit)
      continue;
    array[i] = tmp;
    i++;
  }
}

// array printing
void printArray(vector<int> &array, string arrayName) {
  int size = array.size( );

  for (int i = 0; i < size; i++)
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}



int main(int argc, char* argv[]) {
  // verify arguments
  if (argc != 2) {
    cerr << "usage: quicksort size" << endl;
    return -1;
  }

  // verify an array size
  int size = atoi( argv[1] );
  if (size <= 0) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // array generation
  srand(1);
  vector<int> items(size);
  initArray(items, size);
  cout << "initial:" << endl;
  printArray(items, "items");

  // mergesort
  mergeImproved(items);
  cout << "sorted:" << endl;
  printArray(items, "items");

  return 0;
}
