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
  
     vector<int> freq = {2, 2, 12, 2, 2, 1,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
     vector<int> freq2 = {3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1};
     vector<int> freq4{3, 0, 1, 1, 2, 3, 2, 2, 4, 0, 0, 2, 4, 4, 4, 1, 0, 1, 4, 3, 1, 4, 2, 3, 2, 9};

     shared_ptr<vector<int>> freqptr = make_shared<vector<int>>(freq4);
     Encoder encode(freqptr);

     shared_ptr<vector<char>> en = encode.Encode("happy");
     vector<char> correct = {'1','0','1','0'};
     vector<char> LastOneIsNotCorrect = {'0','1','0','1','0','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','0','1','0','0'};
     vector<char> wrong = {'1','@'};
     shared_ptr<vector<char>> ptr = make_shared<vector<char>>(LastOneIsNotCorrect);
     string de = encode.Decode(ptr);
    

    
    // char v = 0; //initialize v to 000000000
    // v << 1; // changes v to 00000001
    // cout << "V: " << v << endl;

    // cout << "Testing: " << endl;
    // char a = '10001';
    // int res = isalpha(a);
    // cout << res << endl;
    // cout << a << endl;
} 