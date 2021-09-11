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

    /**
     *  takes vector of tweets and sentiment, breaks each tweet into individual DSStrings
     *  each DSString is then added to map of either positive or negative depending on original sentiment.
     *  The count of occurrence goes up if the word occurs more than once.
     *  Each string is normalized (lowercase no punct) beforehand
     */
    void countWords2(std::vector<std::pair<int, DSString>>&); //call vectors and similar via reference not value. value makes a copy

    /**
     * Debugging tool, prints the map of +/- words
     */
    void printMaps(std::map<DSString, int>&,  std::map<DSString, int>&)const;

    /**
     * Debugging tool, just prints the map of words with weight associated to each.
     */
    void printMaps(std::map<DSString, float>&)const;

    /**
     * Finds the weight of each word via a custom equation. The weight can be positive or negative.
     */
    void determineWordWeights(std::map<DSString, int>&,std::map<DSString, int>& );

    /**
     * Goes through each word in the Tweet and gets weight of it. Adds/subtracts from starting point of 0.
     * the weight being +/- at the end corresponds to sentiment assigned to it.
     */
    void determineSentiment(std::map<DSString, DSString>&);

    /**
     * simple rounding function to not make the weights too annoying to work with. (2 decimals)
     */
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
