#pragma once

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<chrono>
#include<string>
#include"gnuplot.h"
using namespace std;

#define MAX_SIZE 50000

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::system_clock::time_point TimePoint;

class AlgoFeeder{
private:
  Gnuplot gp;
  int i=0,x,array[MAX_SIZE];
  fstream feed, save;
  string gnuCommand;
public:
  int* getTestFeed(string feedName,int size);
  // TODO define getTestFeed() funstion with template class
  TimePoint getClockNow();
  double getMicroseconds(TimePoint, TimePoint);
  //TODO::  double getNanoseconds(TimePoint, TimePoint);
  void printResult(int array[100], int size);
  void saveTextResult(int size, int duration, string fileName);
  void showGraphResult(string fileName);
  void saveGraphResult();

};

TimePoint AlgoFeeder::getClockNow(){
  return Clock::now();
}

double AlgoFeeder::getMicroseconds(TimePoint start, TimePoint end){
  return((double)std::chrono::duration_cast<std::chrono::microseconds>(end-start).count());
}

int* AlgoFeeder::getTestFeed(string feedName, int size){
	feed.open(feedName);
	if (!feed)
	{
		cout<<"\nFile not found or unable to open\n";
		exit(1);
	}

	while(i<size){
			feed >> x;

				array[i++] = x;
		}
  return array;
  feed.close();
}

void AlgoFeeder::printResult(int array[MAX_SIZE], int size){
  cout<<"\nprintResult: \n";
  for(i=0;i<size;i++){
    cout<<array[i]<<" ";
  }
}

void AlgoFeeder::saveTextResult(int size, int duration, string fileName = "output.txt"){
  fileName = "./result/"+fileName;
  save.open(fileName, ios::out | ios::app);
  if (!save) {
    cout<<"Error in creating file\n";
  }
  save<<size<<" "<<duration<<"\n";
  // cout<<"\nText result saved successfully!"<<endl;
  save.close();
}

void AlgoFeeder::showGraphResult(string fileName){
  fileName = "./result/"+fileName;
  gnuCommand = fileName + "\' u 1:2 w l";
  gnuCommand = "plot \'"+gnuCommand;
  gp(gnuCommand);
}
