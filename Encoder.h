#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <unordered_map>
#include "LetterNode.h"
using namespace std;

// template <class T> class shared_ptr;
// template <class T>
class Encoder{
private:
    shared_ptr<vector<int>> frequency;
    vector<char> letter;
    unordered_map<char,string> SavingCode;


public:

    //constructor
    Encoder(shared_ptr<vector<int>> fq){
        this->frequency = fq;
        BuildUpBsTree();

    }

    //Encode
    //Reading 1001111, return {'A','B','D'...}
    shared_ptr<vector<char>> Encode(string str){

        return nullptr;
    }

    //Decode
    //Reading {'A','B','D'...}, return 1001111
    // string Decode(shared_ptr<vector<char>> num){
    //     string hi;
    // }

    //print the huffman codes from the root of huffman tree
    void PrintCodes(shared_ptr<LetterNode> curr, string str){
        if(curr == nullptr){
            return;
        }

        if(curr->getLetter() != '$'){
            cout << curr->getLetter() << ": " << str << endl;
            // SavingCode = {curr->getLetter(),str};
            // cout << "TEST: " << SavingCode[curr->getLetter()] << endl;
        }

        PrintCodes(curr->getLeft(), str + "1");
        PrintCodes(curr->getRight(), str + "0");

        
    }

    //Comparsion of two Nodes
    struct greater{
        bool operator()(shared_ptr<LetterNode> l, shared_ptr<LetterNode> r){
            return (l->getFreq() > r->getFreq());
        }
    };

    //Build Up the BStree
    void BuildUpBsTree(){
        letter = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        
        shared_ptr<LetterNode> left, right, top;

        priority_queue<shared_ptr<LetterNode>, vector<shared_ptr<LetterNode>>, greater> pg;

        int i = 0;
        for(int fq : *frequency){

            //pg.push( new LetterNode(letter[i], freq[i]) );
            shared_ptr<LetterNode> node = make_shared<LetterNode>(letter[i],fq);
            pg.push(node);
            i++;
        }

        while(pg.size() != 1){
            left = pg.top();
            pg.pop();
            right = pg.top();
            pg.pop();

            // top = new LetterNode('$', left->getFreq() + right->getFreq());
            top = make_shared<LetterNode>('$',left->getFreq() + right->getFreq());

            top->setLeft(left);
            top->setRight(right);

            pg.push(top);

        }

        PrintCodes(pg.top(), "");



    }
};