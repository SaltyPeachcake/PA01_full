//
// Created by Michael Amberg on 9/6/21.
//

#include "fileReader.h"
#include "DSString.h"
#include <iostream>
#include <fstream> //needed to not throw error on file declaration
#include <vector>

void fileReader::readFile(const char* inputFileName){

    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    std::vector<DSString> row; //creates empty vector for each line in csv
    char line[3000];
    if(inFile.is_open()) inFile.getline(line, 3000); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        while ( inFile && (tCount<=10)){
            row.clear();
            inFile.getline(line,3000);

            DSString wholeLine(line); //converts line to one DSString
            int i = 0;
            int commas =0;
            int mark = 0;
            for(char c: line){
                if(c == ','){
                    commas++;
                    //DSString col = wholeLine.substring(mark, (i-1)-mark);
                    mark = i+1;

                    //this isnt going to work. How does it read the last tweet
                    if(commas == 1 ){
                        DSString col = wholeLine.substring(0, 10);
                        row.push_back(col);
                    }
                    if(commas==4){ //this is the tweet itself it will just read the whole thing
                        DSString col = wholeLine.substring(mark, wholeLine.getLength()-(mark-1));
                        row.push_back(col);
                        break;
                    }

                }
                i++;
            }

            std::cout << "ID: " << row[0] << " : \n";
            std::cout << "Tweet: " << row[1] << "\n";
            tCount++;
            //Do I need to break each word apart?

        }
        inFile.close();
    }
}