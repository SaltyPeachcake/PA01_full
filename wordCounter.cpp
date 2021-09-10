//
// Created by Michael Amberg on 9/8/21.
//

#include "wordCounter.h"
#include<map>
#include <vector>

void wordCounter::printMaps(std::map<DSString, int>& pos,  std::map<DSString, int>& neg)const {
    auto itPos = pos.begin();
    std::cout<<"Positive words: \n";
    while(itPos!=pos.end()){
        std::cout<< itPos->first << " COUNT: " << itPos->second << "\n";
        itPos++; //need to update iterator every time
    }
    auto itNeg = neg.begin();
    std::cout<<"Negative words: \n";
    while(itNeg!=neg.end()){
        std::cout<< itNeg->first << " COUNT: " << itNeg->second << "\n";
        itNeg++;
    }
}

void wordCounter::countWords2(std::vector<std::pair<int, DSString>>& tweets) {

    for (auto it = begin (tweets); it != end (tweets); ++it) {
        int sent = it->first;
        DSString tweet = it ->second;
        //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";
        int size = 0;

        DSString* words = tweet.getWords(size);
        if(sent==0){ //negative words //once it gets to this point the program bacially stops. Maybe infinite loop?
            //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";
            for(int i=0; i<size;i++){ // odd error i guess

                auto negIT = negativeWords.find(words[i]); //looks for the word
                if ( negIT != negativeWords.end() ) { //word is found
                    negIT->second++; // will this work correctly?
                } else { //word is not found
                    negativeWords.insert(std::pair(words[i],1));
                }
            }
        }
        if(sent==4){ //positive words
            //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";
            for(int i=0; i<size;i++){
                auto posIT = positiveWords.find(words[i]);
                if ( posIT != positiveWords.end() ) { //word is found
                    posIT->second++;
                } else { //word is not found
                    positiveWords.insert(std::pair(words[i],1));
                }
            }
        }
    }
}
