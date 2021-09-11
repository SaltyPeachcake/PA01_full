//
// Created by Michael Amberg on 9/10/21.
//

#include "produceResults.h"
#include<map>
#include "DSString.h"
#include<fstream>
#include<vector>

void produceResults::testItAll(std::map<DSString, int> & myData, std::map<DSString, int> & actualData, int& totalTested, const char* file) {
    int correct = 0;

    for( auto it = begin(myData); it != end (myData); ++it ){ //could probably store both arguments as vector then compare index to save time if needed

        DSString key = it->first;

        auto testIT = actualData.find(key);
        if ( testIT != actualData.end() ) {
            if(it->second == testIT->second){ // I somehow get the right prediction
                //std::cout<<it->first<<" : "<<it->second<<"  to:  "<<testIT->second<<" : "<<testIT->first<<"\n";
                correct++;
            } else incorrectTweetIDs.emplace_back(it->first);
        } else { //can I just remove this?
        }
    }
    float accuracy = (float(correct) / float(totalTested)); // I feel like getting the total tweets this way will not return correct value
    accuracy = round( accuracy * 1000.0 ) / 1000.0;
//    std::cout<<"Total Correct: "<<correct<<"  Accuracy: "<< accuracy<<"%\n";
//    std::cout<<"Total tweets tested: "<<totalTested<<std::endl;
    writeToFile(file,accuracy);
}

void produceResults::writeToFile(const char * file, float accuracy) {
    std::fstream ofs;
    ofs.open(file, std::ios::out | std::ios::trunc);
    ofs<<accuracy<<"\n";

    for (auto & element : incorrectTweetIDs) {
        ofs<<element<<"\n";
    }
    ofs.close();
}
