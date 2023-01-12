/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*This file will run the simulator, taking the input file data and using it to run the simulation. Then it will output the 2D array and log all of
* the relevant information about Mario's individual moves. At the end it will output whether mario has won or lost the game.
*/

#include "Simulation.h"
#include "cstdlib"
#include <string>
#include <iostream>
using namespace std;


//default constructor
Simulation::Simulation(){
    //assigns member variables a dummy variable
    myFileProcessor = new FileProcessor();
    myMario = new Mario();
    myLevel = new Level(0,0,0,0,0,0,0);
    v = 0;
    l = 0;
    n = 0;
    c = 0;
    x = 0;
    g = 0;
    k = 0;
    m = 0;
}

//overloaded constructor takes in FileProcessor pointer that has the input and output files
Simulation::Simulation(FileProcessor* mfp){
   myFileProcessor = mfp;
   //assigns starting number of lives
    v = myFileProcessor->getLives();
    //assigns total number of levels
    l = myFileProcessor->getLvl();
    //assigns size of grid
    n = myFileProcessor->getGrid();
    //assigns percentage of Coins
    c = myFileProcessor->getPCoin();
    //assigns percentage of Empty
    x = myFileProcessor->getPEmpty();
    //assigns percentage of Goombas
    g = myFileProcessor->getPGoomba();
    //assigns percentage of Koopas
    k = myFileProcessor->getPKoopa();
    //assigns percentage of Mushrooms
    m = myFileProcessor->getPMushroom();
    //creates new instance of Mario with the number of starting lives
    myMario = new Mario(v);
    //creates new instance of Level object with data obtained from output file
    myLevel = new Level(l, n, c, x, g, k, m);
}

//default destructor
Simulation::~Simulation(){
    //releases memory once done with these variables
    delete myMario;
    delete myLevel;
}

//this method takes in a bool value, representing whther the percents added to 100. Then it runs the sim if true
//otherwise it prints to output file that percents need to be adjusted
void Simulation::runSim(bool myBool){
    if(!myBool){
        //outputs to adjust percentages in input file to add to 100
        myFileProcessor->outputFile("Cannot run Simulation");
    }
    else{
        //allows RNG to work 
        srand(time(NULL));

        //indicates simulation has started
        myFileProcessor->outputFile("Running Sim");

        //creates grid size for 3D array
        myArr = new char**[n];
        //this randomly populates the first level 
        char** placerGrid = myLevel->createArray(0);
        //assigns the first level to 3D array
        myArr[0] = placerGrid;
       
        //sets mario's position in the grid
        myLevel->setMarioLocation();
        //prints the level to the output file
        myFileProcessor->results(myArr, 0, n);
        //skips line in output file
        myFileProcessor->outputFile("");
        //variable to keep track of how many moves mario made
        int count = 0;

        //simulation is monitered by while loop, checking if either mario has no more lives or if he has beaten the last level
        while(myMario->getNumLives() != -1 && (myMario->getLevel() + 1) <= l){ 
            //increments count at top of loop to indicate he's making a new move
            cout << "iteration: " << ++count << endl;
            
            //this outputs mario's current level
            temp = "Current Level: ";
            temp += to_string(myMario->getLevel() + 1);
            myFileProcessor->outputFile(temp);

            //next we output mario's current position in the array
            temp = "Mario's current position [r,c]: [";
            temp += to_string(myLevel->getRowLocation());
            temp += ",";
            temp += to_string(myLevel->getColumnLocation());
            temp += "]";

            //outputting mario's powerlevel BEFORE interacting with the square
            myFileProcessor->outputFile(temp);
            temp = "Power Level: ";
            temp += myMario->getPowerLevel();
            myFileProcessor->outputFile(temp);

            //this variable keeps track of what is in the square before mario populates it
            char obj;
            obj = placerGrid[myLevel->getRowLocation()][myLevel->getColumnLocation()];
            //outputs the action that was taken
            temp = "Action taken: ";
            myFileProcessor->outputFile(temp);
            temp = myLevel->marioInteraction(myMario, (char)obj, placerGrid);
            myFileProcessor->outputFile(temp);

            //output num lives after interaction
            temp = "Number of Lives: ";
            temp += to_string(myMario->getNumLives());
            myFileProcessor->outputFile(temp);

            //output num coins after interaction
            temp = "Number of Coins: ";
            temp += to_string(myMario->getNumCoins());
            myFileProcessor->outputFile(temp);

            //output direction mario will move next 
            temp = "Mario will move: ";
            myFileProcessor->outputFile(temp);
            temp = myLevel->moveMario(myMario);
            myFileProcessor->outputFile(temp);
            
            //skips line
            myFileProcessor->outputFile("");

            //if getOutcome() == 2 that means mario has moved to next level, thus creating a new level and randomly populating it
            if(myLevel->getOutcome() == 2){
                //increments mario's level
                myMario->incrementLevel();
                //randomly populates new level
                placerGrid = myLevel->createArray(myMario->getLevel());
                myArr[myMario->getLevel()] = placerGrid;
                //sets mario's location in new level
                myLevel->setMarioLocation();
                //prints new level to output file
                myFileProcessor->results(myArr, myMario->getLevel(), n);
                myFileProcessor->outputFile("");
                continue;
            }

            //prints array after mario's has interacted with it
            myFileProcessor->results(myArr, myMario->getLevel(), n);
            myFileProcessor->outputFile("");

        }
        //checks whwther mario won or lost the game
        if(myMario->getNumLives() == -1){
            //outputs losing message, indicating a game over
            myFileProcessor->outputFile("Mario has run out of lives!");
            myFileProcessor->outputFile("-----GAME OVER-----");
            myFileProcessor->outputFile("");
        }
        else if(myMario->getLevel() == l){
            //outputs that mario has won
            myFileProcessor->outputFile("Mario has defeated Bowser and saved the Princess!");
            myFileProcessor->outputFile("Mario wins!");
            myFileProcessor->outputFile("");
        }
        //outputs how many moves mario made
        temp = "Mario made ";
        temp += to_string(count);
        temp += " moves";
        myFileProcessor->outputFile(temp);
    }
}