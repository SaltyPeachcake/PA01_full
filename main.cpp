#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "DSString.h"
#include "fileReader.h"

int main(int argc, char** argv) {

    //std::ifstream testFile (argv[1]); //pretty sure this opens the file?
   fileReader::readFile(argv[1]);



    //Catch::Session().run(); //just temporary
    return 0;
}
int test(){
    Catch::Session().run();
    return 0;
}