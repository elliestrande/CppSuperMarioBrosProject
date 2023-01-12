/*
Ellie Strande, Kendra Manz, Samantha Mondragon
2371288, 2343541, 2406434
strande@chapman.edu, many@chapman.edu, mondragonlanderos@chapman.edu
CPSC 350-01
A2: Not So Supper Mario Bros
*This file opens and reads input file and writes to the ouput file to log actions from the simulator
*
*This file makes it possible for the code to process a txt file and then write to an output txt file. 
*This class reads the input file and takes all the int values and stores them as variables to be 
*accessed by other classes
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*FileProcessor has a constructor, a destructor, and a function called processFile that takes two strings and returns
* a void type. FileProcessor has 8 int variables to store the values that the input file provides, allowing the int 
* variables to be accessible to other classes
*/
class FileProcessor{
    public:
    int getLvl();//get method for total number of levels for simulation
    int getGrid();//gets the size of the 2D array
    int getLives();//gets mario's current amount of lives
    int getPCoin();//gets the percentage of coins 
    int getPEmpty();//gets the percentage of empty squares
    int getPGoomba();//gets the percentage of Goombas
    int getPKoopa();//gets the percentage of Koopas 
    int getPMushroom();//gets the percentage of Mushrooms
    FileProcessor();//default constructor for FileProcessor
    FileProcessor(string input, string output);//overloaded constructor for FileProcessor, taking two strings representing input and output file
    virtual ~FileProcessor();
    void processFile(); //will read the input file, extracting data
    void outputFile(string log);//may need a function to write to ouput file
    bool checkPercent();//checks percents from input file add up to exactly 100, if they do it returns true else it returns false
    void results(char*** arr, int l, int n);//function to print the specific level to output file
    
    private:
    //variable holding total number of levels
    int m_lvl;
    //variable holding the size of 2D array
    int m_grid;
    //variable holding current amount of lives
    int m_lives;
    //variable holding the percent of coins in array
    int p_coin;
    //variable holding the percent of empty squares for array
    int p_empty;
    //variable holding the percent of Goombas in array
    int p_goomba;
    //variable holding the percent of Koopas in array
    int p_koopa;
    //variable holding the percent of mushrooms in array
    int p_mushroom;
    //variable holding the string representation of input file
    string m_input;
    //variable holding the string representation of output file
    string m_output;
    //ofstream variable for the output file, allows us to open and write to output file
    ofstream f2;

};

#endif