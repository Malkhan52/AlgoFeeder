#include "../include/AlgoFeeder.h"
using namespace std;

void insertionSort(int array[MAX_SIZE], int size){
  for(int j=1;j<size;j++){
    int item = array[j];
    int i = j-1;
    while((i>=0)&&(item<array[i])){
      array[i+1] = array[i];
      i--;
    }
    array[i+1] = item;
  }
}

int main(int argc, char* argv[]){
  if (argc != 4) {
    cout<<"Enter 3 arguments <feed fileName> <total feed> <out fileName>\n";
    exit(0);
  }
  AlgoFeeder AF;
  int *array, total_feed = atoi(argv[2]);
  char* fileName = argv[1];
  char* outFileName = argv[3];
  array = AF.getTestFeed(fileName, total_feed);
  for(int size=1000;size<=total_feed;size += 1000)
	{
    TimePoint start = AF.getClockNow();
    insertionSort(array, size);
    TimePoint end = AF.getClockNow();
    double duration = AF.getMicroseconds(start, end);
    // cout<<"\nSize: "<<size<<", Elapsed time: "<<duration<<" microseconds"<<endl;
    AF.saveTextResult(size, duration, outFileName);
    AF.showGraphResult(outFileName);
  }
  return 0;
}
