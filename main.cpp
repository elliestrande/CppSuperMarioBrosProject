/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*main method starts the whole simulation, taking in an input and output file
*/
#include "FileProcessor.h"
#include "Simulation.h"


#include<iostream>
using namespace std;


int main(int argc, char* argv[])
{
    FileProcessor fp(argv[1], argv[2]);//create fp object with argv main input
    fp.processFile();
    FileProcessor* point;
    point = &fp;
    Simulation sim(point);
    sim.runSim(point->checkPercent());
    return 0;
}