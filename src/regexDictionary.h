/*
*   A dictionary that stores associations between a regular expression pattern and an HTTP method with a function / handler
*       <regularExpression, HTTPmethod> -> function
*    eg.<"./[a-zA-Z0-9]+/users", "POST"> -> [](){ cout << "hello world" << endl;}
*/


#ifndef REGEXDICTIONARY
#define REGEXDICTIONARY

#include<regex>
#include<vector>
#include<regex>
#include<iostream>

using namespace std;

struct RegexPattern {
  string pattern;
  regex  reg;
};

// Key is a regex pattern of the URL and a HTTP method (e.g. <"./users/4/reservations", "POST">)
typedef pair<RegexPattern,string> RegexDictionaryKey;
// For each different key (request), we assign a different function handler.
typedef pair<RegexDictionaryKey, function<void()>> RegexDictionaryEntry;



class RegexDictionary
{
    vector<RegexDictionaryEntry> dictionary;

public:
    RegexDictionary() {};

    void Add(string pattern, string httpMethod , function<void()> handler)
    {
        RegexPattern regexPattern;
        regexPattern.pattern = pattern;
        regexPattern.reg = regex(pattern);
        dictionary.push_back(RegexDictionaryEntry( RegexDictionaryKey(move(regexPattern),httpMethod), handler ));
    }

    //bool Search(regex,T,S&);
    //void Get(regex,T&);
    //void Remove(regex,T&);

    void Print()
    {
        for(RegexDictionaryEntry entry : dictionary)
        {
            cout << "element: [" << entry.first.first.pattern << "][";
            cout << entry.first.second << "] => " << endl;
            //cout << entry.second << endl;
        }
    }

    //  Overloads operator ()
    function<void()>& operator() (string&& pattern, string&& httpMethod)
    {

        // if pattern matches with an existing entry then return the corresponding method
        for(vector<RegexDictionaryEntry>::iterator itr=dictionary.begin(); itr!=dictionary.end(); itr++)
        {
            string& entryRegexPattern = (*itr).first.first.pattern;
            string& entryHttpMethod = (*itr).first.second;
            //  TODO: replace this with regex match
            if( (entryRegexPattern.compare(pattern) == 0) && (entryHttpMethod.compare(httpMethod) == 0) )
            {
                return (*itr).second;
            }
        }

        // if we're here, there was no match so add new entry
        Add(pattern, httpMethod , [](){});
        return dictionary[dictionary.size()-1].second;
    }

};

#endif