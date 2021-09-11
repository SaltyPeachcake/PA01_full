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
    //std::map<DSString, DSString> testTweets; // map of test ID and tweet
    std::map<DSString, DSString> testTweetsProcessed; //same as above but processed  ie: all lower case, no grammar, etc
    std::map<DSString, int> testSent;
    std::vector<std::pair<int, DSString>> trainingTweetsVec;
    int totalTestTweets ;


    // I have not actually read the initial map after creation, perhaps that will help debug?

    void readTestTweets(const char*); // have to re do this to do only tweets lol

    void readTestSentiment(const char*);

    void readTrainingData(const char*);

};


#endif //PA01_SENTIMENT_FILEREADER_H
