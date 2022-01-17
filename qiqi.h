#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// create TreeNode which need to be added into priority queue
class TreeNode {
public:
  char letter;
  int frequency;
  shared_ptr<TreeNode> left;
  shared_ptr<TreeNode> right;

  TreeNode(char letter, int freq)
      : letter(letter), frequency(freq), left(nullptr), right(nullptr) {}
};

// create compare class which can compare two node in priority queue
class Compare {
public:
  bool operator()(shared_ptr<TreeNode> left, shared_ptr<TreeNode> right) {
    return left->frequency > right->frequency;
  }
};

// interface class
class Encoder {
private:
  // vector should have size 26 and no depulicates.
  shared_ptr<vector<int>> frequencies;
  shared_ptr<TreeNode> root;
  string letter = "abcdefghijklmnopqrstuvwxyz";
  int length;                             // a length of frequencies;
  unordered_map<char, string> huffmanMap; // create a huffman map that contains
                                          // each character and its coresponding

public:
  // public constructor passing array of letter frequencies.
  Encoder(shared_ptr<vector<int>> frequencies);

  // destructor
  ~Encoder();

  // Encode std::string into a sequence of bytes.
  // example about string content: "111101101", return something like
  // [a,b,c,s,e,d,d]
  shared_ptr<vector<char>> Encode(string code);

  // Decode an array of bytes into a std::string.
  string Decode(shared_ptr<vector<char>> character);

  // additional functions below

  // check input string
  bool validString(string code);

  // traverse the Huffman tree and store the coresponding code
  void decodeHelper(shared_ptr<TreeNode> node, string code);

  // gnerate HuffmanTree by using priority queue
  // mapping character and encoded code
  void generateHuffmanTree();
};

#endif