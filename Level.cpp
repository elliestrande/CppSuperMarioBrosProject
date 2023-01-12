/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*/
#include <string>
#include "Level.h"
#include "cstdlib"
#include <iostream>

//level default constructor
Level::Level(){
    m_numLevelSize = 0;
    m_totalLevels = 0;
    m_pCoins = 0;
    m_pNothing = 0;
    m_pGoomba = 0;
    m_pKoopa = 0;
    m_pMushroom = 0;
    m_outcome = 0;
}

//overloaded constructor that takes in the size of the level as well as the percentage of the array that will be filled with each object
Level::Level(int totalLevels, int numLevelSize, int pCoins, int pNothing, int pGoomba, int pKoopa, int pMushroom){
    //sets the member variables 
    m_totalLevels = totalLevels;
    m_numLevelSize = numLevelSize;
    m_pCoins = pCoins;
    m_pNothing = pNothing;
    m_pGoomba = pGoomba;
    m_pKoopa = pKoopa;
    m_pMushroom = pMushroom;

    //creates constant variables to build a 2D array of size m_numLevelSize
    const int row = m_numLevelSize;
    const int column = m_numLevelSize;

    //creates a new char 2D array of size m_levelArray
    m_levelArray = new char*[row];
    for(int i = 0; i < row; i++){
        m_levelArray[i] = new char[column];
    }
}

//default deconstructor
Level::~Level(){
    delete[] m_levelArray;
}

//accessor functions
int Level::getRowLocation(){
    return m_marioLocationRow;
}

int Level::getColumnLocation(){
    return m_marioLocationColumn;
}
int Level::getOutcome(){
    return m_outcome;
}

//function that generates a 2D array represending the NxN grid
char** Level::createArray(int level){
    //indicates mario will move once array is populated
    m_outcome = 0;
    
    int r = m_numLevelSize;
    int c = m_numLevelSize;
    //creates random position
    int bossRandR = rand() % r;
    int bossRandC = rand() % c;

    int warpRandR = rand() % r;
    int warpRandC = rand() % c;

    //makes sure the boss & warp pipe & hero are not the same
    while(bossRandR == warpRandR && bossRandC == warpRandC){
        if(bossRandR == warpRandR){
            warpRandR = rand() % r;
        }
        else if(bossRandC == warpRandC){
            warpRandC = rand() % c;
        }
        else{
            break;
        }
    }
    char** testGrid = new char*[r];
    for(int i = 0; i < r; i++){
        testGrid[i] = new char[c];
        for (int j = 0; j < c; j++){

            if(i == bossRandR && j == bossRandC){
                testGrid[i][j] = 'b';
            }
            
            else if(i == warpRandR && j == warpRandC){
                if(level <(m_totalLevels-1)){
                    testGrid[i][j] = 'w';
                }
                else{
                    testGrid[i][j] = 'x';
                }
            }

            else{
                int numRand = (rand() % 100) + 1;

                //passes in the percentages to fill the array with the various objects
                if(numRand > 0 && numRand <  m_pCoins){
                    testGrid[i][j] = 'c';
                }
                else if(numRand > (m_pCoins) && numRand < (m_pCoins + m_pNothing)){
                    testGrid[i][j] = 'x';
                }
                else if(numRand > (m_pCoins + m_pNothing) && numRand < (m_pCoins + m_pNothing + m_pGoomba)){
                    testGrid[i][j] = 'g';
                }
                else if(numRand > (m_pCoins + m_pNothing + m_pGoomba) && numRand < (m_pCoins + m_pNothing + m_pGoomba + m_pKoopa)){
                    testGrid[i][j] = 'k';
                }
                else{
                    testGrid[i][j] = 'm';
                }
            }
        }
    }
    //returns array
    return testGrid;

    
}

//generates random numbers within the levelArray size to place mario within the level
void Level::setMarioLocation(){
    int randomRow = rand() % m_numLevelSize;
    int randomColumn = rand() % m_numLevelSize;
    m_marioLocationRow = randomRow;
    m_marioLocationColumn = randomColumn;
}

//function that changes the values of msrio's position in the array by moving him up, down, left, or right
string Level::moveMario(Mario* m){
        int LEFT = 0;
        int RIGHT = 1;
        int UP = 2;
        int DOWN = 3;
        string movement = "dummy value";
    if (m_outcome == 0){
        //generates a random integer between 0 and 3
        int random = rand() % 4;
        //finds how the row or column value for marios location needes to be adjusted based on which way mario has been told to move
        if (random == 0){
            movement = "RIGHT";
            if (m_marioLocationColumn == (m_numLevelSize - 1)){
                m_marioLocationColumn = 0;
            }else{
                m_marioLocationColumn += 1;
            }

            return movement;
        } else if (random == 1){
            movement = "LEFT";
            if (m_marioLocationColumn == 0){
                m_marioLocationColumn = (m_numLevelSize - 1);
            } else {
                m_marioLocationColumn -= 1;
            }
            return movement;
        } else if (random == 2){
            movement = "DOWN";
            if (m_marioLocationRow == (m_numLevelSize -1)){
                m_marioLocationRow = 0;
            } else {
                m_marioLocationRow += 1;
            }
            return movement;
        } else if (random == 3){
            movement = "UP";
            if (m_marioLocationRow == 0){
                m_marioLocationRow = (m_numLevelSize -1);
            } else {
                m_marioLocationRow -= 1;
            }
            return movement;
        }
    }
    else if(m_outcome == 1){
        movement = "STAYS PUT";
        return movement;
    }
    else if(m_outcome == 2){
        movement = "NEXT LEVEL";
        return movement;
    }
    return movement;
}

//function that tells us what object is at the array point mario is currently at
char Level::arrayObject(char** a){
    //obtains the object at the place where mario is located
    char object = a[m_marioLocationRow][m_marioLocationColumn];
    //returns object
    return object;
}

//function that controls mario's interaction with the objects in the array
//takes in a mario pointer, the character of the object, and a pointer to the 2D level array
string Level::marioInteraction(Mario* m, char object, char** ar){
    //if outcome returns 0, mario moves on
    //if outcome returns 1, mario stays put
    //if outcome returns 2, incriment level

    string returnStr;
    //if mario interacts with a coin
    if (object == 'c'){
        //calls method to increment his coins
        m->addCoin();
        //makes the space where the object once was blank
        ar[m_marioLocationRow][m_marioLocationColumn] = 'x';
        returnStr = "Mario collected a coin";
        m_outcome = 0;
    //if mario interacts with a mushroom
    } else if (object == 'm'){
        m->increasePowerLevel();
        ar[m_marioLocationRow][m_marioLocationColumn] = 'x';
        returnStr = "Mario ate a mushroom";
        m_outcome = 0;

    //if mario interacts with a goomba
    } else if (object == 'g'){
        int win = 0;
        //generates a random number out of 100 
        int randomPercentage = (rand() % 100) + 1;
        //mario wins if the random number generated was <= 80
        if (randomPercentage <= 80){
            ar[m_marioLocationRow][m_marioLocationColumn] = 'x';
            returnStr = "Mario fought a Goomba and won";
            //checks mario's win streak to see if he has 7 wins, in which case his lives are incremented
            m->checkWinStreak(1);
			returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
            m_outcome = 0;
            win +=1;
        //if the random number is > 80, mario loses
        //if mario's power level is not PL0
        } else if (randomPercentage > 80 && (m->getPowerLevel() != "PL0")){
            m->decreasePowerLevel();
            m_outcome = 0;
            returnStr = "Mario fought a Goomba and lost";
            m->checkWinStreak(0);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
        }
        //if mario loses and his power level is PL0
        else if ((randomPercentage > 80) && (m->getPowerLevel() == "PL0")){
            m->decreasePowerLevel();
            m_outcome = 1;
            returnStr = "Mario fought a Goomba and lost";
            m->checkWinStreak(0);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
        }
    //if mario interacts with koopa troopa
    } else if (object == 'k'){
        int randomPercentage2 = (rand() % 100) + 1;
        int win = 0;
        if (randomPercentage2 <= 65){
            ar[m_marioLocationRow][m_marioLocationColumn] = 'x';
            returnStr = "Mario fought a Koopa and won";
            m->checkWinStreak(1);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
            m_outcome = 0;
            win = 1;
        } else if ((randomPercentage2 > 65) && (m->getPowerLevel() != "PL0")){
            m->decreasePowerLevel();
            returnStr = "Mario fought a Koopa and lost";
            m_outcome = 0;
            m->checkWinStreak(0);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
        } else if ((randomPercentage2 > 65) && (m->getPowerLevel() == "PL0")){
            m->decreasePowerLevel();
            m_outcome = 1;
            returnStr = "Mario fought a Koopa and lost";
            m->checkWinStreak(0);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
        }
    
    } else if(object == 'w'){
        returnStr = "Mario warped";
        m_outcome = 2;

    //when mario encounters a level boss   
    } else if (object == 'b'){

        int randomProb = rand() % 2;
        //if the random probability integer is 1, mario defeats the boss
        if (randomProb == 1){
            //position becomes empty
            returnStr = "Mario fought the level boss and won";
            m->checkWinStreak(1);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
            m_outcome = 2;

        //if the random probability integer is 0, mario loses to the boss
        } 
        else if (randomProb == 0){
            //checks to see if the power level is PL0 or PL1, in which case a life is lost
            returnStr = "Mario fought the level boss and lost";
            m->checkWinStreak(0);
            returnStr += "\nMario winstreak: ";
            returnStr += to_string(m->getWinStreak());
            if ((m->getPowerLevel() == "PL0") || (m->getPowerLevel() == "PL1")){
                //checks to see if mario has another life
                if (m->getNumLives() >= 0){
                    m->remove_life();
                }
             else{
                m->decreasePowerLevel();
                m->decreasePowerLevel();
                }
            }
            //has mario stay at the same location
            m_outcome = 1;
            //resets that location in the array to be a level boss
            m_levelArray[**(m_levelArray + m_marioLocationRow)] [**(m_levelArray + m_marioLocationColumn)] = 'b';
        } 
    }
    else if (object == 'x'){
        returnStr = "The position is empty";
        //mario moves on
        m_outcome = 0;
    }
    return returnStr;
}

//creates the 3D array and runs the simulation 
char*** Level::finalLevelsWorld(){
    //creates a new 3D array
    char*** finalWord = new char**[m_numLevelSize];

    //continues to run the game for each level
    for(int i = 0; i < m_totalLevels; i++){ //CHANGED FROM M_NUMLEVELSIZE TO M_TOTALLEVELS
        char** placerGrid = createArray(i);
        finalWord[i] = placerGrid;
        
    }

    //returns the 3D array
    return finalWord;
}