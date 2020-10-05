//Marcela Gomez CSS 342 Program 3, 11/8/2018

#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "mergeImproved.cpp"

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
    cout << "print array" << endl;
}

//time complexity
int elapsed( timeval &startTime, timeval &endTime ) {
    return ( endTime.tv_sec - startTime.tv_sec ) * 1000000 + ( endTime.tv_usec - startTime.tv_usec );
    cout<< "time elapsed calculated" << endl;
}

int main( int argc, char* argv[] ) {
    ofstream outfile;
    outfile.open("quickSort.txt"); //Create an output file with "quickSort.txt" filename.
    outfile<<"size \t Merge \t ImprovedMerge \t Quick \n";
    int size = 20;
    int rnd = 1;
    
    //while loop creates elapsed times and sends them to a text file
    while(size <= 100000)
    {
        srand(size);//genreates array
        
        //vector initiated for us to make three idential copies
        vector<int> items(size);
        initArray(items, 1000000);
        
        //Makes three copies of the same array
        vector<int> item1(items);
        vector<int> item2(items);
        vector<int> item3(items);
        
        //initiated timeval
        timeval startTime;
        timeval endTime;
        
        outfile<<size<<"\t";
        
        //Start time marked, array is sorted, End time marked
        // Elapsed time goes to the text file.
        //Elapsed time for merge sort
        gettimeofday( &startTime, 0 );
        mergesort(item1);
        gettimeofday( &endTime, 0 );
        int mergeTime = elapsed( startTime, endTime );
        outfile<< mergeTime << "\t";
        
        //Elapsed timefor merge improved
        gettimeofday( &startTime, 0 );
        mergeImproved(item2);
        gettimeofday( &endTime, 0 );
        int improvedTime = elapsed(startTime, endTime);
        outfile<< improvedTime << "\t";
        
        //elapsed tiem for quick sort
        gettimeofday( &startTime, 0 );
        quicksort(item3);
        gettimeofday( &endTime, 0 );
        int quickTime = elapsed(startTime, endTime);
        outfile<< quickTime << "\n";
        
        //increase size of array and go back into while loop
        size +=20;
    }
   
	outfile.close();
  return 0;
}
