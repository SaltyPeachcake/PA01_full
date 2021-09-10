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
    if(inFile.is_open()) inFile.getline(line, 20); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        while ( inFile && (tCount<=5)){
            inFile.getline(line,20);
            sent = line[0]-'0';
            sentVal.push_back(sent);
            //std::cout << "Sent: " << sent << "\n";
            tCount++;
        }
    }
}

void fileReader::readTestTweets(const char* inputFileName){

    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    std::vector<DSString> row; //creates empty vector for each line in csv
    char line[600];
    if(inFile.is_open()) inFile.getline(line, 600); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        //should define tweet make constructor here?
        while ( inFile && (tCount<=5)){
            row.clear();
            inFile.getline(line,600);

            DSString wholeLine(line); //converts line to one DSString
            int i = 0;
            int commas =0;
            int mark = 0;
            for(char c: line){
                if(c == ','){
                    commas++;
                    //DSString col = wholeLine.substring(mark, (i-1)-mark);
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
            long n = row[0].toInt();
            //inserting the values to the map produces errors
            tweetMap.insert(std::pair(n, std::pair(row[1],sentVal[tCount]))); //creates a new key value pair, sets sentiment to 2 until other file is read
            //std::cout << "ID: " << n << " Tweet: " << row[1] << " Senti: " <<sentVal[tCount] << "\n";
            tCount++;


        }
        sentVal.clear();
        inFile.close();
    }
}

void fileReader::readTrainingData(const char * inputFileName) {

    std::ifstream inFile;
    inFile.open(inputFileName,std::ios::in); // do I need the ios::in?

    std::vector<DSString> row; //creates empty vector for each line in csv
    char line[600];
    int sent;
    if(inFile.is_open()) inFile.getline(line, 600); //clears first line of col names
    if ( inFile.is_open() ) {
        int tCount =0;
        //should define tweet make constructor here?
        while ( inFile && (tCount<=200)){
            row.clear();
            inFile.getline(line,600);

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
                        //DSString col = wholeLine[0];
                        //row.push_back(col);
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
            trainingTweetsVec.emplace_back(sent, row[0]);
            //std::cout << "Sent: " << sent << " Tweet: " << row[0] << "\n";
            tCount++;


        }
        sentVal.clear();
        inFile.close();
    }
}




