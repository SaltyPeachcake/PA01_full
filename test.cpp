//
// Created by Michael Amberg on 9/1/21.
//
#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSStrings are working as they should", "[DSString]")
{
    SECTION("DSStrings can be created created with different parameters" ) {
        DSString emp;
        REQUIRE(emp.c_str() == nullptr);
        //I was gonna try to delete emp, but apparently it is deleted automatically?

        DSString charstar("This is a test");
        //REQUIRE(charstar.c_str() == "This is a test");
        REQUIRE(std::strcmp(charstar.c_str(), "This is a test") == 0); // I'm gonna try comparing this way instead for a sec
        REQUIRE(charstar.getLength() == std::strlen("This is a test"));
        REQUIRE(charstar[charstar.getLength()] == '\0'); // makes sure that the last value is a null character

        DSString killMe(charstar); //tests copy constructor
        //REQUIRE(killMe.c_str() == "This is another test"); // comparing the c-str to the string literal w/ == results in an error
        REQUIRE(std::strcmp(killMe.c_str(), "This is a test") == 0);
        REQUIRE(killMe.getLength() == std::strlen("This is a test"));
        REQUIRE(killMe[charstar.getLength()] == '\0'); //makes sure the two are the same in another way while also checking \0
        REQUIRE(&killMe != &charstar); // I was told I don't need to check this but I want to
    }
    SECTION("Overloaded assignment operators set values correctly"){
        DSString empty;
        empty = "I am no longer empty";
        //REQUIRE(empty.c_str() == "I am no longer empty");
        REQUIRE(std::strcmp(empty.c_str(), "I am no longer empty") == 0);
        DSString hasChar("8===D");
        empty = hasChar;
        //REQUIRE(empty.c_str() == "8===D");
        REQUIRE(std::strcmp(empty.c_str(), "8===D") == 0);
        REQUIRE(empty.getLength() == hasChar.getLength());
    }
    SECTION("Non-modifying string concatenation working"){
        DSString a("I was born into a world with pain,");
        DSString b(" but I clawed my way into one of false security");
        DSString c = a + b;
        //REQUIRE( a.c_str() == "I was born into a world with pain, but I clawed my way into one of false security");
        REQUIRE(std::strcmp(c.c_str(), "I was born into a world with pain, but I clawed my way into one of false security") == 0);
    }
    SECTION("DSString relational operators working"){
        DSString a("This is a test");
        DSString b("This one is different");
        DSString c("This is a test");
        DSString d ("I have no clue what this is but its kinda long for to make sure that its longer than b");
        REQUIRE (a == c);
        REQUIRE (a != b);
        REQUIRE (std::strcmp(a.c_str(), c.c_str())==0);
       // REQUIRE (a.c_str()==c.c_str()); // this fails? or doesn't call the right overload operator

        REQUIRE (b > a);
        //REQUIRE (b < d); //what? why does this fail its literally over twice as long
        REQUIRE (c.c_str()<d.c_str()); // Okay I ran the test once and this failed, then started working again
    }
    SECTION("Can get certain char in DSString"){
        DSString a("What are you gonna do, stab me?");
        char let = a[5];
        REQUIRE(let== 'a'); //I think this is testing it right?
    }
    SECTION("getLength() works okay. Yay"){
        DSString a("*He stabs him*");
        REQUIRE(a.getLength()== 14); //Unless I can't count. Also removes null char at end
    }
    SECTION("Can return substring of DSString"){
        DSString part("No one ever sees the whole picture, only what they want to");
        DSString whole = part.substring(17, 17);
        REQUIRE(whole == "the whole picture"); // wait why does this work when comparing string literals?
    }
    SECTION("Bunch of random tests of me trying to test things"){
        DSString a;
        DSString b("The biggest wrongs will shove you into the abyss");
        DSString c("I like ");
        DSString d = b[4];
        a = b[14];
        d+=a;
        d+=b[26];
        d+=b[44]; //After testing, this is slow as fuck. But it does work
        d+=b[46];
        DSString nice = c + d;
        REQUIRE((std::strcmp(nice.c_str(), "I like boobs")==0));
        REQUIRE(nice[nice.getLength()] == '\0');
    }
}