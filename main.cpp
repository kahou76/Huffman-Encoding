#include <iostream>
#include "Student.h"
#include "Encoder.h"
#include <vector>
#include <memory>
using namespace std;

// template <class T> class shared_ptr;
int main() {
    cout << "Hello World!\n";
  
    vector<int> freq = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
     shared_ptr<vector<int>> freqptr = make_shared<vector<int>>(freq);
     Encoder encode(freqptr);
    // Encoder encode(v);
    // shared_ptr<vector<char>> en = encode.Encode("AABCDDD");
    // for(int i=0; i<*en.size(); i++){
    //     cout << "Encode: " << *en[i] << " ";
    // }

    // string de = encode.Decode(en);
    // cout << "Decode: " << de << endl;

    
    


} 