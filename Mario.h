/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*/
#ifndef MARIO_H //header guard
#define MARIO_H

#include <string>
#include <iostream>
using namespace std;

//create Mario class
class Mario{
    public:
        Mario(); //default constructor
        Mario(int V); //overloaded constructor
        virtual ~Mario(); //default deconstructor
        //adds a coin to mario's wallet
        void addCoin();
        //increases Mario's power level
        void increasePowerLevel();
        //decreases Mario's power level
        void decreasePowerLevel();
        //level get method
        int getLevel();
        //awards mario a life whenever his coin count hits 20
        void wallet_at_20();
        //gets Mario's number of lives
        int getNumLives();
        //removes a life
        void remove_life();
        //gets the number of coins in mario's wallet
        int getNumCoins();
        //gets mario's power level
        string getPowerLevel();
        //increments mario's level
        void incrementLevel();
        //checks mario's win streak
        void checkWinStreak(int winLose);
        //will retrieve the win streak amount
		int getWinStreak();

    private:
        int m_numlives;
        int m_wallet;
        std::string m_powerlevel;
        int m_level;
		int m_winStreak;

};

#endif