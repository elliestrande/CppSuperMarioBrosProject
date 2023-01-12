/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*/
#include <string>
#include "Mario.h"

#include <iostream>
using namespace std;

//default constructor
Mario::Mario(){
    m_numlives = 3;
    m_wallet = 0;
    m_powerlevel = "PL0";
    m_level = 0;
}

//overloaded constructor
Mario::Mario(int V){
    m_numlives = V;
    m_wallet = 0;
    m_powerlevel = "PL0";
    m_level = 0;
}

//default deconstructor
Mario::~Mario(){

}

void Mario::addCoin(){
    m_wallet += 1;
    if (m_wallet == 20){
        m_numlives += 1;
        m_wallet = 0;
    }
}

//awards mario a life whenever his coin count hits 20
void Mario::wallet_at_20(){
    m_numlives += 1;
    m_wallet = 0;
}

//when mario comes in contact with a mushroom increases Mario's power level
void Mario::increasePowerLevel(){
    if (m_powerlevel == "PL0"){
        m_powerlevel = "PL1";
    } else if (m_powerlevel == "PL1"){
        m_powerlevel = "PL2";
    } else {
        m_powerlevel = "PL2";
    }
}
//decreases mario's power level
void Mario::decreasePowerLevel(){
     if (m_powerlevel == "PL2"){
        m_powerlevel = "PL1";
    } else if (m_powerlevel == "PL1"){
        m_powerlevel = "PL0";
    } else if (m_powerlevel == "PL0"){
        if (m_numlives == 0){
            //ends game
            m_numlives = -1;
        } else {
            m_numlives -= 1;
        }
    }
}

//detracts a life
void Mario::remove_life(){
    if (m_numlives == 0){
        m_numlives = -1;
    } else{
        m_numlives -= 1;
        m_powerlevel = "PL0";
    }
}
//get methods for mario's private member variables
int Mario::getNumCoins(){
    return m_wallet;
}
int Mario::getNumLives(){
    return m_numlives;
}

string Mario::getPowerLevel(){
    return m_powerlevel;
}

int Mario::getLevel(){
    return m_level;
}
//increments mario's level
void Mario::incrementLevel(){
    m_level++;
}

//checks mario's win streak and increments mario's number of lives by 1 if he has a win streak of 7
//if a 1 is passed in, then he won and the streak gets 1 added
//if a 0 is passed in, then the streak is lost
void Mario::checkWinStreak(int winLose){
    if(winLose == 1){
        m_winStreak += 1;
        if(m_winStreak == 7){
            m_numlives += 1;
            m_winStreak = 0;
        }
    }
    else if (winLose == 0){
        m_winStreak = 0;
    }
}
//returns the win streak amount
int Mario::getWinStreak(){
    return m_winStreak;
}