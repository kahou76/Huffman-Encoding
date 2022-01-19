#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <unordered_map>
#include <stdio.h>
#include <ctype.h>
#include <iterator>
#include "LetterNode.h"
using namespace std;

// template <class T> class shared_ptr;
// template <class T>
class Encoder{
private:
    shared_ptr<vector<int>> frequency;
    vector<char> letter;
    unordered_map<char,string> SavingCode;
    unordered_map<string,char> SavingChar;


public:

    //constructor
    Encoder(shared_ptr<vector<int>> fq);

    //Encode
    //Reading ABBDDDADS, return {01010101, 10101010, 100011}
    //Package them up into 8 bits
    shared_ptr<vector<char>> Encode(string str);

    //Decode
    //Reading {10100111, 10101011, 10011}, return ABBDBAD
    //1,0,1,...
    string Decode(shared_ptr<vector<char>> code);

    //print the huffman codes from the root of huffman tree
    void SaveCodes(shared_ptr<LetterNode> curr, string str);

    //Comparsion of two Nodes
    struct greater{
        bool operator()(shared_ptr<LetterNode> l, shared_ptr<LetterNode> r){
            if(l->getFreq() == r->getFreq()){
                return l->getLetter() > r->getLetter();
            }else{
                return l->getFreq() > r->getFreq();
            }
            
        }
    };

    //Build Up the BStree
    void BuildUpBsTree();

    // check if all digit
    bool isNumber(const char &c);

    // check if all Alphabet
    bool isAlphabet(const string &str);
        

};