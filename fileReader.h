//
// Created by Michael Amberg on 9/6/21.
//

#ifndef PA01_SENTIMENT_FILEREADER_H
#define PA01_SENTIMENT_FILEREADER_H

#include "DSString.h"
#include <map>
#include <iostream>
#include <vector>

class fileReader {

public:
    const int testCount = 10000; //change these to however many lines are in .csv
    const int trainingCount = 20000;

    std::map<DSString, DSString> testTweetsProcessed; //same as above but processed  ie: all lower case, no grammar, etc
    std::map<DSString, int> testSent;
    std::vector<std::pair<int, DSString>> trainingTweetsVec;
    int totalTestTweets ;


    // I have not actually read the initial map after creation, perhaps that will help debug?
    /**
     * Reads all the tweets into a map of ID and DSString
     */
    void readTestTweets(const char*); // have to re do this to do only tweets lol

    /**
     * Reads all the IDs into a map of ID and sentiment
     */
    void readTestSentiment(const char*);

    /**
     * Reads all tweets into vector of sentiment and DSString.
     */
    void readTrainingData(const char*);

};


#endif //PA01_SENTIMENT_FILEREADER_H
