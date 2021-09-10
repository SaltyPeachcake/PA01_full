#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSString.h"
#include "fileReader.h"
#include "wordCounter.h"

int main(int argc, char** argv) {

    //std::ifstream testFile (argv[1]); //pretty sure this opens the file?
   // /**
    fileReader newfileReader;
    newfileReader.readTrainingData(argv[3]);
    //newfileReader.readTestSentiment(argv[2]);
    //newfileReader.readTestTweets(argv[1]);

    wordCounter newWordCounter;
    newWordCounter.countWords2(newfileReader.trainingTweetsVec);
    //newWordCounter.countWords(newfileReader.tweetMap);
    newWordCounter.printMaps(newWordCounter.positiveWords, newWordCounter.negativeWords);


    //fileReader::readTestSentiment(argv[2]);
    //fileReader::readTestTweets(argv[1]);




    //Catch::Session().run(); //just temporary
    return 0;
}
int test(){
    Catch::Session().run();
    return 0;
}