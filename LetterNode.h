#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


class LetterNode{
private:
    char letter;
    int freq;
    string twochar;
    shared_ptr<LetterNode> left;
    shared_ptr<LetterNode> right;
    

public:


    // LetterNode(){
    //     left = right = nullptr;
    //     letter = '#';
    //     freq = -1;
    // }

    LetterNode(char l, int f, string tc){
        left = right = nullptr;
        letter = l;
        freq = f;
        twochar = tc;
    }

    ~LetterNode(){}

    void setLetter(char l){
        letter = l;
    }

    void setFreq(int f){
        freq = f;
    }

    void setTC(string tc){
        twochar = tc;
    }

    void setLeft(shared_ptr<LetterNode> l){
        left = l;
    }

    void setRight(shared_ptr<LetterNode> r){
        right = r;
    }

    char getLetter(){
        return letter;
    }

    int getFreq(){
        return freq;
    }

    string getTC(){
        return twochar;
    }

    shared_ptr<LetterNode> getLeft(){
        return left;
    }

    shared_ptr<LetterNode> getRight(){
        return right;
    }




};