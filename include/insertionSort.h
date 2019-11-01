#pragma once

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 50000

class insertionSort{
public:
  int* insertionSort(int array[MAX_SIZE], int size){
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
};
