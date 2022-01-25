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
    shared_ptr<LetterNode> left;
    shared_ptr<LetterNode> right;
    

public:

    LetterNode(char l, int f);

    ~LetterNode(){}

    void setLetter(char l);

    void setFreq(int f);

    void setLeft(shared_ptr<LetterNode> l);

    void setRight(shared_ptr<LetterNode> r);

    char getLetter();

    int getFreq();

    shared_ptr<LetterNode> getLeft();

    shared_ptr<LetterNode> getRight();



};