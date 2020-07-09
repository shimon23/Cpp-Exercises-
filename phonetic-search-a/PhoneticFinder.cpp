#include "PhoneticFinder.hpp"
#include <string>
#include <algorithm>
#include <sstream> 
#include <stdexcept>
#include <iostream>


using namespace std;
namespace phonetic{


bool equals(char a, char b, const char x, const char y){
    return (a == x || a == y) && (b == x || b == y);
}

bool equals(char a, char b, const char x, const char y, const char z){


    return (a == x || a == y || a == z) && (b == x || b == y || b == z);
}

bool equals(char a, char b){   
    return (a == b) || 
        equals(a, b, 'v', 'w') || 
        equals(a, b, 'b', 'f', 'p') || 
        equals(a, b, 'g', 'j') || 
        equals(a, b, 'c', 'k', 'q') || 
        equals(a, b, 's', 'z') || 
        equals(a, b, 'd', 't') || 
        equals(a, b, 'u', 'o') || 
        equals(a, b, 'i', 'y');
}

    string find(string text, string word)
    {
         if(word == "" || word == " "){
            throw runtime_error("Can't search for an empty word");
         }
        string lowerWord = word;
        transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(),[](unsigned char c){ return tolower(c); });
        istringstream splitText(text); // intilizze stream of string like a split
        string token;
        int count = 0;
        

        while(splitText>>token)
        {
            count=0;
            string lowerToken=token;// because I want to keep the original token 
            if(lowerWord.length()==token.length()){
                transform(lowerToken.begin(), lowerToken.end(), lowerToken.begin(),[](unsigned char c){ return tolower(c); });
                for(int i=0;i<token.length();i++){
                    if(equals(lowerToken.at(i),lowerWord.at(i)))//use equal to check every char in the word
                    {
                        count++;
                    }
                }
                if(count==token.length()){ //if the counter is equal to the token length this means that all letters were checked and passed
                    return token;
                }

            }
        }
            
        throw runtime_error("Did not find the word "+word+" in the text"); 


        }

    }
