//
// Created by Michael Amberg on 9/8/21.
//

#include "wordCounter.h"
#include "fileReader.h"
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
    std::cout<< "Total negative words: " << negWordCount << " Total tweets: "<<totalNegTweets<<"\n";
    std::cout<< "Total positive words: " << posWordCount <<" Total tweets: "<<totalPosTweets<< std::endl;
}
void wordCounter::printMaps(std::map<DSString, float> & weights) const {
    auto it = weights.begin();
    std::cout<<"Word Weights: \n";
    while(it!=weights.end()){
        std::cout<< it->first << " WEIGHT: " << it->second << "\n";
        it++; //need to update iterator every time
    }
}

void wordCounter::countWords2(std::vector<std::pair<int, DSString>>& tweets) {

    for (auto it = begin (tweets); it != end (tweets); ++it) {
        int sent = it->first;
        DSString tweet = it ->second;
        //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";
        int size = 0;

        //std::map<DSString, int> posW;
        //std::map<DSString, int> negW;

        DSString* words = tweet.getWords(size);
        if(sent==0){
            negWordCount += size;
            totalNegTweets++;
        }
        if(sent==4){
            posWordCount += size;
            totalPosTweets++;
        }
        for(int i=0; i<size;i++){
            if(words[i].getLength() > 1){ //this gets rid of all DSStrings that are only one character
                if(sent==0){ //negative words
                    //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";

                        auto negIT = negativeWords.find(words[i]); //looks for the word
                        if ( negIT != negativeWords.end() ) { //word is found
                            negIT->second++; // will this work correctly?
                        } else { //word is not found
                            negativeWords.insert(std::pair(words[i],1));
                        }
                }
                if(sent==4){ //positive words
                    //std::cout<<"Sentiment: "<<sent<<" Tweet: "<<tweet<<"\n";

                    auto posIT = positiveWords.find(words[i]);
                        if ( posIT != positiveWords.end() ) { //word is found
                            posIT->second++;
                        } else { //word is not found
                            positiveWords.insert(std::pair(words[i],1));
                        }
                }
            }
        }
        //positiveWords = &posW;
    }
}


void wordCounter::determineWordWeights(std::map<DSString, int> & pos, std::map<DSString, int> & neg) {

    for (auto it = begin (pos); it != end (pos); ++it) { //goes through every word in positive word list
        DSString key = it->first;
        float wordW;

        auto negIT = neg.find(key);
        if ( negIT != neg.end() ) { // sees if word occurs in both lists

            float posWeight = wordWeight(it->second, 4);
            float negWeight = wordWeight(negIT->second, 0);
            wordW = posWeight - negWeight;

            wordWeights.insert(std::pair(key,wordW));

        } else { //word is not found
            wordW = wordWeight(it->second, 4);;
            wordWeights.insert(std::pair(key,wordW));
        }

    }
    for (auto it = begin (neg); it != end (neg); ++it) {
        DSString key = it->first;
        float wordW;

        auto wIT = wordWeights.find(key); //checks to see if word has already been weighed or not
        if ( wIT != wordWeights.end() ) { // word does occur in both lists. Checking this first cause faster if true
            // nothing happens
        } else { //word is not found
            wordW = 0.0 -  wordWeight(it->second, 0);
            wordWeights.insert(std::pair(key,wordW));
        }
    }
    //delete positiveWords;
}

/**
 * equation takes total tweets^2 * word freq / total word count
 * tweets is ^2 to average wordcount
 *
 * Also messing with it it may change
 */
float wordCounter::wordWeight(int& frequency, int sent) {
    float weight;
    if(sent==0){
        weight = round(( float(frequency))/(float(negWordCount)/(float(totalNegTweets))));
        return weight;
    }
    else if( sent ==4){
        weight = round(( float(frequency))/(float(posWordCount)/(float(totalPosTweets))));
        return weight;
    }else if( sent==2){
        weight = round(((float(totalNegTweets^2) * float(frequency)))/(float(negWordCount)));
        return weight;
    }
}

void wordCounter::determineSentiment(std::map<DSString, DSString>& tweets){ // takes proccessed test tweets

    for( auto it = begin(tweets); it != end (tweets); ++it ){
        int size = 0;
        float weight = 0.0;
        DSString tweet = it ->second;
        DSString* words = tweet.getWords(size);

        for(int i = 0; i<size;i++){
            DSString key = words[i];
            auto wIT = wordWeights.find(key); //finds word in pre-built map

            if ( wIT != wordWeights.end() ) {  //locates the word and its weight
                weight += wIT->second;
            } else { //can I just remove this?
            }
        }
        if(weight>=0.0){
            classifiedTweets.insert(std::pair(it->first,4));
        } else classifiedTweets.insert(std::pair(it->first,0));

    }
}
/**
 * rounds the float to two decimals just so it doesnt get too messy
 */
float wordCounter::round(float var){
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}






//can convert DSString to a normal one if using a stemming library.

