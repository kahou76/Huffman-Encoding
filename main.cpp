#include <iostream>
#include "Student.h"
#include "Encoder.h"
#include <vector>
#include <cctype>
#include <memory>
#include <climits>
using namespace std;


int main() {
    cout << "Hello World!\n";
  
     vector<int> freq = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
     vector<int> freq2 = {3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1};
     vector<int> freq4{3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1, 4, 2, 3, 2, 9};
     vector<int> happy = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
     vector<int> ah = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     vector<int> meow = {3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1, 4, 2, 3, 2, 9, INT_MAX};
     vector<int> basic = {1, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,INT_MAX};
     vector<int> abc = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, INT_MAX};
     vector<int> abcd = {2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, INT_MAX};
     vector<int> abcdefgh = {2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, INT_MAX};
     vector<int> abcdefghi = {2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1};
     vector<int> qiqi = {2,  2,  2,  2,  2,  4,  7,  8,  9,  10, 11, 12, 13, 14,15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
     vector<int> a = {1,1,1,1};
     vector<int> mar = {3, 2, 1, 1, 2, 3, 2, 2, 4, 7, 9, 2, 4, 4, 4, 1, 1, 1, 4, 3, 1, 4, 2, 3, 2, 9};



     shared_ptr<vector<int>> freqptr = make_shared<vector<int>>(mar);
     Encoder encode(freqptr);

     shared_ptr<vector<char>> en = encode.Encode("happy");
     vector<char> correct = {'1','0','1','0'};
     vector<char> LastOneIsNotCorrect = {'0','1','0','1','0','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','0','1','0','0'};
     vector<char> wrong = {'1','@'};

     shared_ptr<vector<char>> ptr = make_shared<vector<char>>(LastOneIsNotCorrect);
     string de = encode.Decode(en);
    


} 


