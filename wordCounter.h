//
// Created by Michael Amberg on 9/8/21.
//

#ifndef PA01_SENTIMENT_WORDCOUNTER_H
#define PA01_SENTIMENT_WORDCOUNTER_H

#include<map>
#include "DSString.h"
#include<vector>



class wordCounter {

public:
    std::map<DSString, int> positiveWords;
    std::map<DSString, int> negativeWords;
    int posWordCount = 0;
    int negWordCount = 0;
    int totalPosTweets = 0;
    int totalNegTweets = 0;

    std::map<DSString, float> wordWeights;

    std::map<DSString, int> classifiedTweets;
    std::vector<DSString> incorrectTweetIDs;

    void countWords2(std::vector<std::pair<int, DSString>>&); //call vectors and similar via reference not value. value makes a copy

    void printMaps(std::map<DSString, int>&,  std::map<DSString, int>&)const;

    void printMaps(std::map<DSString, float>&)const;

    void modifyWordLists(std::map<DSString, int>&, std::map<DSString, int>&);

    void determineWordWeights(std::map<DSString, int>&,std::map<DSString, int>& );

    void determineSentiment(std::map<DSString, DSString>&);

    float round(float var);

    /**
     * Possibly look at the precentages of both? If words occur above x% in both lists then declare it a modifer word,
     * look at word either before or after it in combo.
     *
     * First get the fucking map working. Print out the map to see what the thing looks like.
     *
     * Maybe a system similar to counting cards? Assign weight to certain words, start at 0 then add or subtract
     * based in words in tweet. if >0 pos or <0 neg.
     *
     * probably won't be able to do stemming but would be cool.
     */

};


#endif //PA01_SENTIMENT_WORDCOUNTER_H
