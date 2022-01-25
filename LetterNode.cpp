#include "LetterNode.h"

    LetterNode::LetterNode(char l, int f){
        left = right = nullptr;
        letter = l;
        freq = f;
    }


    void LetterNode::setLetter(char l){
        letter = l;
    }

    void LetterNode::setFreq(int f){
        freq = f;
    }

    void LetterNode::setLeft(shared_ptr<LetterNode> l){
        left = l;
    }

    void LetterNode::setRight(shared_ptr<LetterNode> r){
        right = r;
    }

    char LetterNode::getLetter(){
        return letter;
    }

    int LetterNode::getFreq(){
        return freq;
    }

    shared_ptr<LetterNode> LetterNode::getLeft(){
        return left;
    }

    shared_ptr<LetterNode> LetterNode::getRight(){
        return right;
    }