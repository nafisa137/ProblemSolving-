//File name: A3_Sheet2b2_20220835
//Purpose : Document Similarity
//Author : Safa Tawfik Al-sharabi
//ID : 20220835
//Section : S1
// Date : 5/12/2023


#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

class StringSet
{
private:
    unordered_set<string> strings;
    vector<string> stringV;

public:
    //Default constructor
    StringSet() {}
    //constructor to load strings from a file
    StringSet(string filename)
    {
        loadFromFile(filename);
    }
    //constructor to load strings from either a file or a string
    StringSet(string input, bool fromString = true)
    {
        if (fromString)
        {
            loadFromString(input);
        }
        else
        {
            loadFromFile(input);
        }
    }
    //load  From file
    void loadFromFile(string filename)
    {
        ifstream file(filename);
        string word;
        while (file >> word)
        {
            processWord(word);
        }
    }
    //load  From string
    void loadFromString(string input)
    {
        istringstream iss(input);
        string word;
        while (iss >> word)
        {
            processWord(word);
        }
    }

    void addString(string str)
    {
        processWord(str);
    }

    void removeString(string str)
    {
        strings.erase(str);
        stringV.erase(remove(stringV.begin(), stringV.end(), str), stringV.end());
    }
    //clear all strings from the set
    void clearSet()
    {
        strings.clear();
        stringV.clear();
    }

    int size()
    {
        return strings.size();
    }

    void outputStrings()
    {
        for (const auto& str : stringV)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    //overload "+" operator for set union
    StringSet operator+(StringSet other) const
    {
        StringSet result = *this;
        result.strings.insert(other.strings.begin(), other.strings.end());
        result.updatestringV();
        return result;
    }
    //overload "*" operator for set intersection
    StringSet operator*(StringSet other) const
    {
        StringSet result;
        for (const auto& str : stringV)
        {
            if (other.strings.count(str) > 0)
            {
                result.strings.insert(str);
                result.stringV.push_back(str);
            }
        }
        return result;
    }

    //Compute Simliarity  by use the equation -->  The size of set of common words / (sqrt size of D * sqrt size of Q)
    double computeSimilarity(StringSet other)
    {
        StringSet QintersectD = *this * other;
        double intersectionSize = (double)(QintersectD.size());
        double denominator = sqrt((double)(size()) * (double)(other.size()));
        return intersectionSize / denominator;
    }

private:
    //Process  the word by converting to lowercase and adding to the set if not already present
    void processWord(string& word)
    {
        string processedWord;

        for (char& c : word)
        {
            if (isalpha(c))
            {
                processedWord += tolower(c);
            }
        }

        if (!processedWord.empty() && strings.insert(processedWord).second)
        {
            stringV.push_back(processedWord);
        }
    }

    // Update the vector representation of the set to reflect the current set elements
    void updatestringV()
    {
        stringV.clear();
        for (const auto& str : strings)
        {
            stringV.push_back(str);
        }
    }
};


