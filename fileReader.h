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
    std::map<int, DSString> tweetMap;


    static void readFile(const char*);

};


#endif //PA01_SENTIMENT_FILEREADER_H
