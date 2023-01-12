/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*This file opens and reads input file and writes to the ouput file to log actions from the simulator
*/


#include "FileProcessor.h"

#include <iostream>
using namespace std;


//default constructor for FileProcessor
FileProcessor::FileProcessor(){
   m_input = "";
   m_output = "";
}
//overloaded constructor takes input and output file and opens the output file
FileProcessor::FileProcessor(string input, string output){
    m_input = input;
    m_output = output;
    //opens output file
    f2.open(m_output);
}

//default Destructor for FileProcessor
FileProcessor::~FileProcessor(){
    //closes output file
    f2.close();
}

//This function opens and reads the input file, initilizing the variables neccessary to run the simulation
void FileProcessor::processFile(){
    //creates ifstream object to read input file and opens file
    ifstream f1(m_input);
    //this string holds each number value from input file line by line
    string temp;
    //checks that input file was opened correctly
    if(f1.is_open()){
        //since the input file should only have 8 lines of int values, we don't need a loop to cycle through the file
        //reads input from input file, string value in string temp
        getline(f1, temp);
        //converts string value into int
        m_lvl = stoi(temp);

        getline(f1, temp);
        m_grid = stoi(temp);

        getline(f1, temp);
        m_lives = stoi(temp);

        getline(f1, temp);
        p_coin = stoi(temp);

        getline(f1, temp);
        p_empty = stoi(temp);

        getline(f1, temp);
        p_goomba = stoi(temp);

        getline(f1, temp);
        p_koopa = stoi(temp);

        getline(f1, temp);
        p_mushroom = stoi(temp);
    }
}

//get method for total number of levels for simulation
int FileProcessor::getLvl(){
    return m_lvl;
}
//gets the size of the 2D array
int FileProcessor::getGrid(){
    return m_grid;
}
//gets mario's current amount of lives
int FileProcessor::getLives(){
    return m_lives;
}
//gets the percentage of coins 
int FileProcessor::getPCoin(){
    return p_coin;
}
//gets the percentage of empty squares 
int FileProcessor::getPEmpty(){
    return p_empty;
}
//gets the percentage of Goombas 
int FileProcessor::getPGoomba(){
    return p_goomba;
}
//gets the percentage of Koopas 
int FileProcessor::getPKoopa(){
    return p_koopa;
}
//gets the percentage of Mushrooms 
int FileProcessor::getPMushroom(){
    return p_mushroom;
}
//This function checks that all the percents from the input file add up to exactly 100, this will allow us to start the simulation
bool FileProcessor::checkPercent(){
    //adds all the percentages together
    int sum = 0;
    sum += p_coin;
    sum += p_empty;
    sum += p_goomba;
    sum += p_koopa;
    sum += p_mushroom;
    //checks if the percents don't add up to 100
    if(sum != 100){
        //will output to the file that the percents do not add to 100 and returns false
        f2 << "Percents do not add up to 100" << endl;
        f2 << "Please adjust percents to add up to 100 exactly" << endl;
        return false;
    }
    else {
        return true;
    }
}

//outputFile function here takes in a string and outputs it to output file
void FileProcessor::outputFile(string log){

   f2 << log << endl;

}

//this funtion takes in the 3D array, an int representing the level, and an int representing the size of the 2D
//cycling through and outputting the contents
void FileProcessor::results(char*** arr, int l, int n){
    for (int j = 0; j < n; ++j){
        for(int k = 0; k < n; k++){
            f2 << "[" << l << "][" << j << "][" << k << "]";
            f2 << arr[l][j][k] << endl;
        }
    }
}
