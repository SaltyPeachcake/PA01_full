//
// Created by Mark Fontenot on 6/2/2021.
//

#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H

#include <iostream>
#include <cstring>


class DSString{

private:
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/



     char* customString;
     short sLength; // length of the string given. Since each string will only have max of 148 chars we can use type short
     //I know that the length isnt needed in the field, but I like having it cause easy to reference

public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/

    //What is this? is it complete? what is it even doing?
    //DSString() : maxL(nullptr), size(0) // default constructor

    DSString(); //Default constructor
    DSString(const char*); // Takes the c-string and creates a DSString object
    DSString(const DSString&); //Copies? kinda confused by this one
    DSString(const char); //needed this to test out more things
    ~DSString(); //Destructor, deletes object




    /**
     * Overloaded Assignment Operators
     */

    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString& operator= (const char);

    /**
     * Overloaded non-modifying string concat
     * @return
     */
    DSString operator+ (const DSString&);

    DSString& operator+= (const DSString&);
    DSString& operator+= (const char);

    /**
     * Standard relational operators.  Feel free to add additional.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/

    bool operator== (const char*) const;
    bool operator== (const DSString&) const;
    bool operator!= (const DSString&) const;
    bool operator!= (const char*) const;
    bool operator> (const DSString&) const;
    bool operator> (const char*) const;
    bool operator< (const DSString&) const;
    bool operator< (const char*) const;

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char& operator[] (const int);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength(); //must remove one char from end to get rid of null char

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int start, int numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<< (std::ostream&, const DSString&);

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.

   // DSString find(DSString str); //will find string within a string

   /**
    * Is unused but want to implement to function similar to how getline() with a string would
    */
   std::istream & getLine (std::istream &ist, DSString &str, //got this from stack overflow
                                  char delim = '\n');

   /**
    * originally converted to int but ran into maxIntValue so converted to long instead. Not even using function anymore
    */
   long toInt();

   /**
    * Gets each word within a sentence. Words are found via # of spaces+1
    */
   DSString* getWords(int& ); //I believe this is returning a container for all the words in the string.

   /**
    * Normalizes string by calling deletePunctuation() and toLower()
    */
   DSString& processString();

   /**
    * Old punctuation handler. Did not work after much fiddling. Just ignored it until I could no longer
    */
   DSString& deleteGrammar();

   /**
    * Punctuation handler. Took hours and was infuriating. Just ignored it until I needed to fix it
    */
   DSString& deletePunctuation();

   /**
    * I think you can figure out what this ine does
    */
   DSString& toLower();

};



#endif //PA01_SENTIMENT_DSSTRING_H
