//
// Created by Michael Amberg on 9/8/21.
//

#ifndef PA01_SENTIMENT_WORDCOUNTER_H
#define PA01_SENTIMENT_WORDCOUNTER_H

#include<map>
#include "DSString.h"


class wordCounter {

public:
    std::map<DSString, int> positiveWords;
    std::map<DSString, int> negativeWords;
    int posWordCount = 0;
    int negWordCount = 0;
    int pos1 = 0;
    int neg1 = 0;


    void countWords2(std::vector<std::pair<int, DSString>>&); //call vectors and similar via reference not value. value makes a copy

    void printMaps(std::map<DSString, int>&,  std::map<DSString, int>&)const;

    void modifyWordLists(std::map<DSString, int>&, std::map<DSString, int>&);

    void determineSentiment(std::vector<std::pair<int, DSString>>&);

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
