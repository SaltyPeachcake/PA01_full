//
// Created by mark on 6/2/2021.
//


#include "DSString.h"
#include <cstring>

/**
 * The constructors
 */
DSString::DSString(){
    sLength = 0; //uneeded but still nice to have in my opinion
    customString = nullptr;
}

DSString::DSString(const char* tempStr){
    sLength = std::strlen(tempStr) +1;

    customString = new char[sLength];
    std::strcpy(customString,tempStr);
}

DSString::DSString(const DSString& in){
    sLength = in.sLength;
    customString = new char[sLength+1];
    std::strcpy(customString, in.customString);
}

DSString::~DSString(){
    delete[] customString;
}

/**
 * I have no clue if these next two functions opperate correctly but I hope they do
 */
DSString& DSString::operator= (const char* arg){
    //want this.CS to update the value its pointing to what arg.CS is pointing to
    delete[] customString; //deletes old pointer
    customString = new char[std::strlen(arg) +1]; //creates new one
    std::strcpy(customString, arg); //copies value
    return *this; //returns the new pointer
}
//I think this func is basically the same but is referred to differently
DSString& DSString::operator= (const DSString& arg){
    delete[] customString; //deletes old pointer
    customString = new char[arg.sLength +1]; //creates new one
    std::strcpy(customString, arg.customString); //copies value
    return *this; //returns the new pointer
}

/**
 *  Concatenates two strings without modifying them
 */
DSString DSString::operator+ (const DSString& arg){
    //since the size will be different, I think I should delete the first object and recreate it
    short newLength = sLength+arg.sLength;
    char* temp = new char[newLength+1];
    std::strcpy(temp,customString);
    delete[] customString;
    customString = new char[newLength+1];
    //also I feel like when concatenating I will want to add a space at the end of the first string so they don't mesh
    std::strcat(temp, arg.customString); //what happens to the arg? does it stay there? Should I delete it?
    std::strcpy(customString,temp);
    sLength = newLength; //updates the length of object
    delete[] temp;
}

/**
 * Standard relational operators, two versions of each type
 */
bool DSString::operator== (const char* arg ){
    return std::strcmp(customString, arg) == 0; // returns true if equal, false if not
}

bool DSString::operator== (const DSString& arg){
    return std::strcmp(customString, arg.customString) == 0;
}

bool DSString::operator> (const char* arg){
    return std::strcmp(customString, arg) > 0;
}

bool DSString::operator> (const DSString& arg){
    return std::strcmp(customString, arg.customString) > 0;
}

bool DSString::operator< (const char* arg){
    return std::strcmp(customString, arg) < 0;
}

bool DSString::operator< (const DSString& arg){
    return std::strcmp(customString, arg.customString) < 0;
}

/**
 * subscript opperator
 */
char& DSString::operator[] (const int i){
    return customString[i]; //does this return the right type?
}



int DSString::getLength(){
    //return sLength; //I mean could do this but oh well
    return std::strlen(customString);
}

/**
 * substring function
 */
DSString DSString::substring(int start, int numChars){
    char* temp = new char[numChars+1];
    std::strncpy(temp,customString+start,numChars);
    DSString subS; //creates new
}