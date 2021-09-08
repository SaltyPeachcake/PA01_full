//
// Created by Michael Amberg on 9/6/21.
//

#ifndef PA01_SENTIMENT_FILEREADER_H
#define PA01_SENTIMENT_FILEREADER_H

#include "DSString.h"
#include <map>
#include <iostream>


class fileReader {

public:
    static std::map<int, std::pair<DSString, int>> tweetMap; // map of ID and pair of tweet with sentiment


    static void readTestTweets(const char*);

    static void readTestSentiment(const char*);

};


#endif //PA01_SENTIMENT_FILEREADER_H
