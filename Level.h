/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*/
#ifndef LEVEL_H //header guard
#define LEVEL_H

#include<string>
#include "Mario.h"

class Level{
    public:
         //default constructor
        Level();
        //overloaded constructor
        Level(int totalLevels, int numLevelSize, int pCoins, int pNothing, int pGoomba, int pKoopa, int pMushroom);
        //default deconstructor
        virtual ~Level();
        //function that generates a 2D array represending the NxN grid
        char **createArray(int m_level);
        //function that moves mario by moving him up, down, left, or right
        std::string moveMario(Mario* mario);
        //get method for mario's location in rows
        int getRowLocation();
        //set mario's location in the array
        void setMarioLocation();
        //get method for mario's location in columns
        int getColumnLocation();
        //to get the object Mario will interact with
        char arrayObject(char** a);
        //will set up all of Mario's interactions
        string marioInteraction(Mario* mario, char object, char** a);
        int arrSize;
        char*** finalLevelsWorld();
        void printLevel();
        void results(char*** arr, int l);
        //gets the outcome of whether Mario moves on, stays put, or advances to next level
        int getOutcome();

     private:
        int m_level;
        int m_totalLevels;
        int m_marioLocationRow;
        int m_marioLocationColumn;
        char** m_levelArray;
        int m_numLevelSize;
        int m_pCoins;
        int m_pNothing;
        int m_pGoomba;
        int m_pKoopa;
        int m_pMushroom;
        int m_outcome;
        Mario* mario;
};
#endif