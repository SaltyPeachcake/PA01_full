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


    void testItAll(std::map<DSString, int> & myData, std::map<DSString, int> & actualData, int& totalTested,const char* );

   void writeToFile(const char*, float);
};


#endif //PA01_SENTIMENT_PRODUCERESULTS_H
