#pragma once

#include<iostream>
#include <string>
using namespace std;

class Gnuplot{
public:
  Gnuplot();
  ~Gnuplot();
  void operator()(const string & command);
protected:
  FILE *GnuplotPipe;
};

Gnuplot::Gnuplot(){
  GnuplotPipe = popen("gnuplot -persist","w");
  if(!GnuplotPipe)
    cerr<<("Gnuplot not found");
}
Gnuplot::~Gnuplot(){
  fprintf(GnuplotPipe, "exit\n");
  pclose(GnuplotPipe);
}
void Gnuplot::operator()(const string & command){
  fprintf(GnuplotPipe, "%s\n",command.c_str());
  fflush(GnuplotPipe);
}
