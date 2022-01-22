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
#include <bitset>
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
    void SaveCodes(shared_ptr<LetterNode> curr, string str, int totalf);

    //Comparsion of two Nodes
    struct greater{
        bool operator()(shared_ptr<LetterNode> l, shared_ptr<LetterNode> r){
            if(l->getFreq() == r->getFreq()){
                cout << "Left Letter: " << l->getTC() << "  Left Freq: " << l->getFreq() <<"  Right Letter: " << r->getTC() << "  Right Freq: "<< r->getFreq() << endl;
                shared_ptr<LetterNode> l1, r1;
                l1 = l;
                r1 = r;
                while(l1->getLeft() != nullptr){
                    l1 = l1->getLeft();
                }
                while(r1->getLeft() != nullptr){
                    r1 = r1->getLeft();
                }
                return l1->getLetter() > r1->getLetter();
                
                // if(l->getTC() == "$$" && r->getTC() == "$$"){
                //     while(l->getLeft() != nullptr){
                //         l = l->getLeft();
                //     }
                //     cout << "Leaf Letter: "<<l->getTC() << endl;
                // }ss
                //return l->getTC() > r->getTC();
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
        
    //pack up 8 index of int into a char
    //asuming vector of 8 or less bits
    char packInt(vector<int> v){
        char result = 0x00; //0000 0000
        string str = "";
        for(int i=0; i<v.size(); i++){
            //str *= 10;
            str += to_string(v[i]);
            result = result << 1; //shift left
            result = result | v[i]; // value is 0b0 or 0b1
        }
        int shift = 8 -v.size(); // for example, 
        cout << "Shift: " << shift << endl;
        result = result << shift;
        
        string binary = bitset<8>(result).to_string();
        
        cout << "decial output: " << str << endl;
        cout << "Binary output: " << binary << endl;

        return result;

    }

    //Unpack the vector<char> into {1,0,1,0,0,1,1,....}
    shared_ptr<vector<char>> unpackChar(shared_ptr<vector<char>> v){
        shared_ptr<vector<char>> result;
        vector<char> store;

        for(int i=0; i<v->size(); i++){
            char c = v->at(i);
            string binary = bitset<8>(c).to_string();
            for(int j=0; j<binary.size(); j++){
                store.push_back(binary[j]);
            }
        }
        
        result = make_shared<vector<char>>(store);
        return result;
    }
    
    
};