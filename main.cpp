#include <iostream>
#include "Student.h"
#include "Encoder.h"
//#include "qiqi.h"
#include <vector>
#include <cctype>
#include <memory>
using namespace std;


int main() {
    cout << "Hello World!\n";
  
     vector<int> freq = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
     vector<int> freq2 = {3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1};
     vector<int> freq4{3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1, 4, 2, 3, 2, 9};
     vector<int> happy = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
     vector<int> ah = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     vector<int> meow = {3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1, 4, 2, 3, 2, 9};

     shared_ptr<vector<int>> freqptr = make_shared<vector<int>>(freq);
     Encoder encode(freqptr);

     shared_ptr<vector<char>> en = encode.Encode("abc");
     vector<char> correct = {'1','0','1','0'};
     vector<char> LastOneIsNotCorrect = {'0','1','0','1','0','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','0','1','0','0'};
     vector<char> wrong = {'1','@'};

     shared_ptr<vector<char>> ptr = make_shared<vector<char>>(LastOneIsNotCorrect);
     string de = encode.Decode(en);
    

    
    // char v = 0; //initialize v to 000000000
    // v << 1; // changes v to 00000001
    // cout << "V: " << v << endl;

    // cout << "Testing: " << endl;
    // char a = '10001';
    // int res = isalpha(a);
    // cout << res << endl;
    // cout << a << endl;

    char a = 'a';
    char p = 'p';
    char h = 'h';
    int a1 = a - '0';
    int p1 = p - '0';
    int h1 = h - '0';  
    int ah1 = a1 + h1;
    cout << "p: " << p1 << endl;
    cout << "ah: " << ah1 << endl;
    //cout << h1 << endl;
} 