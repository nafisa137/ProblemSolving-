// File name:
// Purpose: 3.STL – Map. Farah Mohamed works remotely
// with a foreign company that is writing a search engine.
// One of the criteria for ordering the retrieved documents is how many times a word exists in the document. To find that out, she needs to develop a frequency table for a given text file. A frequency table lists words and the number of times each word appears in a document or a file. Help her write a program that creates a frequency table for a file whose name is entered by the user. Use STL map that stores <Key, Value> pairs of string and int. First, read the input file and clean it of all punctuation and non-alphanumeric characters except "-" which can be part of a word. You may find functions ispunct(), isalnum(), tolower(), etc (see cctype library) useful to use. Test your program on multiple different files.
// Author(s):  Nafisa Abdalrahman Mohamed
// ID(s): 20220854
// Section: 1
// Date: 8/12/20223

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <iomanip>

using namespace std;

// Function to clean the word from punctuation and convert to lowercase
string cleanWord(const string& word) {
    string cleanedWord;
    for (char ch : word) {
        if (isalnum(ch) || ch == '-') {
            cleanedWord += tolower(ch);
        }
    }
    return cleanedWord;
}


