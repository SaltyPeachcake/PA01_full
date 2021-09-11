//
// Created by Michael Amberg on 9/10/21.
//

#include "produceResults.h"
#include<map>
#include "DSString.h"
#include<vector>

void produceResults::testItAll(std::map<DSString, int> & myData, std::map<DSString, int> & actualData, int& totalTested) {
    int correct = 0;
    for( auto it = begin(myData); it != end (myData); ++it ){ //could probably store both arguments as vector then compare index to save time if needed

        DSString key = it->first;

        auto testIT = actualData.find(key);
        if ( testIT != actualData.end() ) {
            std::cout<<it->first<<" : "<<it->second<<"  to:  "<<testIT->second<<" : "<<testIT->first<<"\n";
            if(it->second == testIT->second){ // I somehow get the right prediction

                correct++;
            } else incorrectTweetIDs.emplace_back(it->first);
        } else { //can I just remove this?
        }
    }
    float accuracy = correct / totalTested; // I feel like getting the total tweets this way will not return correct value
    std::cout<< accuracy<<"\n";
    std::cout<<"Total tweets tested: "<<totalTested<<std::endl;
}
