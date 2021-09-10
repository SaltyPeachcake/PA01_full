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
    std::map<long, std::pair<DSString, int>> tweetMap; // map of ID and pair of tweet with sentiment
    std::map<int, DSString> trainingTweets;
    std::vector<int> sentVal;
    std::vector<std::pair<int, DSString>> trainingTweetsVec;

    // I have not actually read the initial map after creation, perhaps that will help debug?

    void readTestTweets(const char*); // have to re do this to do only tweets lol

    void readTestSentiment(const char*);

    void readTrainingData(const char*);

};


#endif //PA01_SENTIMENT_FILEREADER_H
