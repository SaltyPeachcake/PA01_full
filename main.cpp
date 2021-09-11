#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSString.h"
#include "fileReader.h"
#include "wordCounter.h"
#include "produceResults.h"

int main(int argc, char** argv) {
    if(argc==1){ // checks how many command line arguments there are. If no arguments are called then CatchTests are ran
        Catch::Session().run();
        return 0;
    } else if(argc==5){  // makes sure that there are 4 arguments passed to the program for proper functioning

        /*
         * Reads training file, passes to countWords2() to build positive and negative word lists.
         * determineWordWeights quantifies how positive or negative each word is
         */
        fileReader newfileReader;
        newfileReader.readTrainingData(argv[1]);

        wordCounter newWordCounter;
        newWordCounter.countWords2(newfileReader.trainingTweetsVec);
        //newWordCounter.printMaps(newWordCounter.positiveWords, newWordCounter.negativeWords); //used to debug and see actual word list
        newWordCounter.determineWordWeights(newWordCounter.positiveWords, newWordCounter.negativeWords);
        //newWordCounter.printMaps(newWordCounter.wordWeights); //used to display the weight associated with each word + or -

        /*
         * the testTweets are read, then sentiment is determined for each tweet in testTweet map
         */
        newfileReader.readTestSentiment(argv[3]);
        newfileReader.readTestTweets(argv[2]);
        newWordCounter.determineSentiment(newfileReader.testTweetsProcessed);

        /*
         * The final function tests how many tweets were classified correctly and adds incorrect ones to a vector
         * the accuracy and vector are then output to a .txt file
         */
        produceResults final;
        final.testItAll(newWordCounter.classifiedTweets, newfileReader.testSent, newfileReader.totalTestTweets, argv[4]);

        return 0;
    }
    else{
        std::cout<<"Incorrect number of arguments passed"<<std::endl;
        return 0;
    }
}