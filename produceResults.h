//
// Created by Michael Amberg on 9/10/21.
//

#ifndef PA01_SENTIMENT_PRODUCERESULTS_H
#define PA01_SENTIMENT_PRODUCERESULTS_H

#include<map>
#include "DSString.h"
#include<vector>


class produceResults {

public:
    std::vector<DSString> incorrectTweetIDs;
    /**
     * tests self-classified to actual data set and keeps track of how many correct, adds wrong to vector
     * @param myData - the tweets classified by the program
     * @param actualData - tweets gathered from testSentiment dataset
     * @param totalTested  - int used to find accuracy
     */
    void testItAll(std::map<DSString, int> & myData, std::map<DSString, int> & actualData, int& totalTested,const char* );

    /**
     * Just takes the argv and accuracy to write to output file. incorrect Tweets are stored in class field.
     */
    void writeToFile(const char*, float);
};


#endif //PA01_SENTIMENT_PRODUCERESULTS_H
