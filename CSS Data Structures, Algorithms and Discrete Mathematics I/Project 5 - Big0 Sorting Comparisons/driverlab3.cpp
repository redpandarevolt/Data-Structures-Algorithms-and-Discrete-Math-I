//Marcela Gomez CSS 342 Lab 3, 11/8/2018

#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "bubblesort.cpp"
#include "insertionsort.cpp"
#include "selectionsort.cpp"

using namespace std;

// array initialization with random numbers
void initArray( vector<int> &array, int randMax ) {
  int size = array.size( );

  for ( int i = 0; i < size; ) {
    int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if ( array[j] == tmp ) {
        hit = true;
        break;
      }
    }
    if ( hit )
      continue;
    array[i] = tmp;
    i++;
  }
}

// array printing
void printArray( vector<int> &array, char arrayName[] ) {
  int size = array.size( );

  for ( int i = 0; i < size; i++ )
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}

//time complexity
int elapsed( timeval &startTime, timeval &endTime ) {
    return ( endTime.tv_sec - startTime.tv_sec ) * 1000000 + ( endTime.tv_usec - startTime.tv_usec );
}

int main( int argc, char* argv[] ) {
    ofstream outfile;
    outfile.open("compare.txt"); //Create an output file with "compare.txt" filename.
    outfile<<"size \t bubble \t insertion \t selection \n";
    int size = 20;
    int rnd = 1;
    
    while(size <= 5000)
    {
        srand(size);//genreates array
        
        vector<int> item(size);
        
        initArray(item, 1000000);
        
        vector<int> item1(item);
        vector<int> item2(item);
        vector<int> item3(item);
        
        timeval startTime;
        timeval endTime;
        
        outfile<<size<<"\t";
        
        gettimeofday( &startTime, 0 );
        bubblesort(item1);
        gettimeofday( &endTime, 0 );
        int bubbleTime = elapsed( startTime, endTime );
        outfile<< bubbleTime << "\t";
        
        gettimeofday( &startTime, 0 );
        insertionsort(item2);
        gettimeofday( &endTime, 0 );
        int insertionTime = elapsed(startTime, endTime);
        outfile<< insertionTime << "\t";
        
        gettimeofday( &startTime, 0 );
        selectionsort(item3);
        gettimeofday( &endTime, 0 );
        int selectionTime = elapsed(startTime, endTime);
        outfile<< selectionTime << "\n";
        
        size +=20;
    }
   
	outfile.close();
  return 0;
}
