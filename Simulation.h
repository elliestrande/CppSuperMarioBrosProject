/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*This file will run the simulator, taking the input file data and using it to run the simulation. Then it will output the 2D array and log all of
*the relevant information about Mario's individual moves. At the end it will output whether mario has won or lost the game.
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileProcessor.h"
#include <string>
#include "Level.h"
#include "Mario.h"
#include <time.h>

#include <iostream>
using namespace std;

class Simulation{
    public:
    //default constructor
    Simulation();
    //overloaded constructor takes in FileProcessor pointer that has the input and output files
    Simulation(FileProcessor* myFile);
    //default destructor
    ~Simulation();
    //this method takes in a bool value, representing whther the percents added to 100. Then it runs the sim if true
    //otherwise it prints to output file that percents need to be adjusted
    void runSim(bool myBool);

    private:
    //int member variables hold the information obtained from input file
    int v;
    int l;
    int n;
    int c;
    int x;
    int g;
    int k;
    int m;
    //this string will hold what should be output to the output file
    string temp;
    //creates 3D array for simulation
    char*** myArr;
    //FileProcessor pointer that holds the input and output file
    FileProcessor* myFileProcessor;
    //pointer to mario variable to gain access to mario methods
    Mario* myMario;
    //pointer to level variable to gain access to level methods
    Level* myLevel;

};


#endif