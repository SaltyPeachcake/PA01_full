//
// Created by Michael Amberg on 9/6/21.
//

#include "fileReader.h"
#include "DSString.h"
#include <iostream>
#include <fstream> //needed to not throw error on file declaration
#include <vector>
#include <map>


void fileReader::readTestSentiment(const char * inputFileName){ //I am just going to assume that each tweet sentiment is the same index as in the tweet dataset
    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    char line[20];
    int sent;
    //if(inFile.is_open()) inFile.getline(line, 20); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        while ( inFile && tCount<=testCount ){  //I dont know how else to read file without hard coding how many lines are needed. Every other method produced bad_alloc
            inFile.getline(line,20);
            if(tCount==0){tCount++; } else{ //skips line I hope
                sent = line[0]-'0';
                DSString theLine(line);
                DSString ID = theLine.substring(2,10);
                testSent.insert(std::pair(ID,sent));
                tCount++;
            }
        }
    }
}

void fileReader::readTestTweets(const char* inputFileName){

    totalTestTweets = 0; //sets baseline

    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    std::vector<DSString> row; //creates empty vector for each line in csv
    char line[600];
    //if(inFile.is_open()) inFile.getline(line, 600); //clears first line of col names
    if ( !inFile.eof() ) {
        int tCount =0;
        while ( inFile && tCount<=testCount ){ // Change this number to whatever the test dataset size is
            row.clear();
            inFile.getline(line,600);
            if(tCount==0){tCount++;  } else{ //skips line
                DSString wholeLine(line); //converts line to one DSString
                int i = 0;
                int commas =0;
                int mark = 0;
                for(char c: line){
                    if(c == ','){
                        commas++;
                        mark = i+1;

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

                //testTweets.insert(std::pair(row[0], row[1])); //creates a new key value pair
                testTweetsProcessed.insert(std::pair(row[0], row[1].processString())); //creates another map where the tweet is pre-processed for analysis
                totalTestTweets++;
                //std::cout << "ID: " << n << " Tweet: " << row[1] << " Senti: " <<sentVal[tCount] << "\n";
                tCount++;
            }
        }
        inFile.close();
    }
}

void fileReader::readTrainingData(const char * inputFileName) {

    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    std::vector<DSString> row; //creates empty vector for each line in csv
    char line[600];
    int sent;
    //if(inFile.is_open()) inFile.getline(line, 600); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        //should define tweet make constructor here?
        while ( inFile && tCount<=trainingCount ){
            row.clear();
            inFile.getline(line,600);
            if(tCount==0){tCount++;
                //should skip the first line without making .good() a problem?
            }else{
                DSString wholeLine(line); //converts line to one DSString


                int i = 0;
                int commas =0;
                int mark = 0;
                for(char c: line){
                    if(c == ','){
                        commas++;
                        mark = i+1;

                        if(commas == 1 ){
                            sent = wholeLine[0]-'0';
                        }
                        if(commas==5){ //this is the tweet itself it will just read the whole thing
                            DSString col = wholeLine.substring(mark, wholeLine.getLength()-(mark-1));
                            row.push_back(col);
                            break;
                        }

                    }
                    i++;
                }
                //int n = row[0][0] - '0';
                //inserting the values to the map produces errors
                trainingTweetsVec.emplace_back(sent, row[0].processString());
                //std::cout << "Sent: " << sent << " Tweet: " << row[0] << "\n";
                tCount++;
            }

        }
        inFile.close();
    }
}




