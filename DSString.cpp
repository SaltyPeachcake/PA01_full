//
// Created by mark on 6/2/2021.
//


#include "DSString.h"
#include <cstring>
#include <stdlib.h>

/**
 * The constructors
 */
DSString::DSString(){
    sLength = 0; //unneeded but still nice to have in my opinion
    customString = nullptr;
}

DSString::DSString(const char* tempStr){
    sLength = std::strlen(tempStr);

    customString = new char[sLength+1];
    std::strcpy(customString,tempStr);
}

DSString::DSString(const DSString& in){
    sLength = in.sLength;
    customString = new char[sLength+1];
    std::strcpy(customString, in.customString);
}

DSString::DSString(const char letter){
    sLength = 1;
    customString = new char(letter); // this wont throw errors? its not a char*
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
    sLength = std::strlen(arg);
    std::strcpy(customString, arg); //copies value
    return *this; //returns the new pointer
}
//I think this func is basically the same but is referred to differently
DSString& DSString::operator= (const DSString& arg){
    delete[] customString; //deletes old pointer
    customString = new char[arg.sLength +1]; //creates new one
    sLength = std::strlen(arg.customString);
    std::strcpy(customString, arg.customString); //copies value
    return *this; //returns the new pointer
}
DSString& DSString::operator= (const char arg){
    delete[] customString; //deletes old pointer
    customString = new char(arg); //creates new one
    sLength = 1;
    return *this; //returns the new pointer
}

/**
 *  Concatenates two strings without modifying them
 */
DSString DSString::operator+ (const DSString& arg){
    //since the size will be different, I think I should delete the first object and recreate it
    short newLength = sLength+arg.sLength;
    char* temp = new char[newLength+1];
    std::strcpy(temp,customString); //copies original string to one that is longer
    //also I feel like when concatenating I will want to add a space at the end of the first string so they don't mesh
    std::strcat(temp, arg.customString); //what happens to the arg? does it stay there? Should I delete it?
    DSString concat(temp); // so I dont need to delete temp[]?
    return concat;
}
/**
 * concatenates two strings but modifies the first to be the combination of both
 */
DSString& DSString::operator+= (const DSString& arg){
    //since the size will be different, I think I should delete the first object and recreate it
    short newLength = sLength+arg.sLength;
    char* temp = new char[newLength+1];
    std::strcpy(temp,customString);
    std::strcat(temp, arg.customString);
    delete[] customString;
    customString = temp;
    /**
    customString = new char[newLength+1];
    std::strcpy(customString, temp);
    delete[] temp;**/
    return *this;
}

DSString& DSString::operator+= (const char arg){
    //since the size will be different, I think I should delete the first object and recreate it
    short newLength = sLength+1;
    char* temp = new char[newLength+1];
    std::strcpy(temp,customString);
    DSString pain(arg); // I feel like there is a better way to do this. making new object every time is slow
    std::strcat(temp, pain.customString);
    delete[] customString;
    customString = temp;
//    customString = new char[newLength+1];
//    std::strcpy(customString, temp);
//    delete[] temp;
    return *this;
    //is pain deleted automatically after the function call?
}

/**
 * Standard relational operators, two versions of each type
 */
bool DSString::operator== (const char* arg) const{
    return std::strcmp(customString, arg) == 0; // returns true if equal, false if not
}

bool DSString::operator== (const DSString& arg) const{ // we were told to include this? idk why
    return std::strcmp(customString, arg.customString) == 0;
}

bool DSString::operator!= (const DSString& arg ) const{
    return std::strcmp(customString, arg.customString) != 0;
}

bool DSString::operator!= (const char* arg ) const{
    return std::strcmp(customString, arg) != 0;
}

bool DSString::operator> (const char* arg) const{
    return std::strcmp(customString, arg) > 0;
}

bool DSString::operator> (const DSString& arg) const{
    return std::strcmp(customString, arg.customString) > 0;
}

bool DSString::operator< (const char* arg) const{
    return std::strcmp(customString, arg) < 0;
}

bool DSString::operator< (const DSString& arg) const{
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

   // char* temp = new char[numChars+1];
   // std::strncpy(temp,customString+start,numChars);
    DSString subS; //creates new DSS object
    subS.sLength = numChars;
    delete[] subS.customString; // I don't know If i need to delete or not but might as well
    subS.customString = new char[numChars+1];
    std::strncpy(subS.customString,customString+start,numChars); //can I just do this instead?
    //std::strcpy(subS.customString,temp);

    if(subS.customString[subS.sLength] != '\0'){ //makes sure it ends in null char
        subS.customString[subS.sLength] = '\0';
    }
    return subS;
}

/**
 *  The function that returns the value / c-string the object holds
 */
char* DSString::c_str(){
    return customString;
}

/**
* prints the DSString to the OS
*/

std::ostream& operator <<(std::ostream& OS, const DSString& str){ //since  << is declared as a friend I don't need to call namespace
    OS << str.customString;
    return OS;
}

std::istream &DSString::getLine(std::istream &inStream, DSString &line, char delim) {
    int i = 0;
    char* wholeLine = new char[300];
    for (char c; inStream.get(c) && c != delim; ){
        wholeLine[i] = c;
        i++;
        //line += c; //this works but is horribly inefficient atm
    }


}

long DSString::toInt() {
    //int num = arg.c_str() - 0; //this is a way to convert one character to an int
    return  atol(this->c_str());
}

DSString* DSString::getWords(int& s) { //improve efficiency by making the index of spaces kept track up originally

    char* string = this->c_str();
    int spaces = 0;
    for(int i = 0; i<this->getLength();i++){
        if(string[i] == ' '){
            spaces++;
        }
    }
    s = spaces;
    auto* words = new DSString[spaces+1]; //creates new DSString array or whatever of each word. Words is how many spaces+1
    int spaces2 = 0;
    int mark = 0;
    for(int i = 0; i<this->getLength();i++){
        if(string[i] == ' '){
            DSString word(this->substring(mark, i-mark));
           mark = i+1;
           words[spaces2] = word;
           spaces2++;
        }
        if(spaces2==spaces){ //only occurs at the last space
            DSString word(this->substring(mark, this->getLength()-(mark-1)));
            words[spaces2] = word;
        }
    }
    return words;
}
