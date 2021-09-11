#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSString.h"
#include "fileReader.h"
#include "wordCounter.h"
#include "produceResults.h"

int main(int argc, char** argv) {

    fileReader newfileReader;
    newfileReader.readTrainingData(argv[3]);


    wordCounter newWordCounter;
    newWordCounter.countWords2(newfileReader.trainingTweetsVec);
    newfileReader.trainingTweetsVec.clear();
    //newWordCounter.printMaps(newWordCounter.positiveWords, newWordCounter.negativeWords);
    newWordCounter.determineWordWeights(newWordCounter.positiveWords, newWordCounter.negativeWords);
    newWordCounter.positiveWords.clear();
    newWordCounter.negativeWords.clear(); //clearing these to try to free up memory.
    //newWordCounter.printMaps(newWordCounter.wordWeights);

    newfileReader.readTestSentiment(argv[2]);
    newfileReader.readTestTweets(argv[1]);

    newWordCounter.determineSentiment(newfileReader.testTweetsProcessed);



    produceResults final;
    final.testItAll(newWordCounter.classifiedTweets, newfileReader.testSent, newfileReader.totalTestTweets);

    //Catch::Session().run(); //just temporary



    return 0;
}
int test(){
    Catch::Session().run();
    return 0;
}