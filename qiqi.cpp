// #include "qiqi.h"

// // public constructor passing array of letter frequencies.
// Encoder::Encoder(shared_ptr<vector<int>> frequencies) {
//   // shared_ptr<vector<int>> represents letter frequencues
//   // make sure the length of frequencies is valid (0, 26]
//   // if it is invalid, throw error
//   if (!frequencies) {
//     throw invalid_argument("Encoder error: input is nullptr");
//   }

//   this->length = frequencies->size();
//   if (length > 26 || length < 0) {
//     throw invalid_argument(
//         "Encoder error: the length should be in range of (0, 26]");
//   } else {
//     this->frequencies = frequencies;
//     generateHuffmanTree();
//   }
// }

// // destructor
// Encoder::~Encoder() {
//   frequencies.reset();
//   root.reset();
// }

// // Encode std::string into a sequence of bytes.
// shared_ptr<vector<char>> Encoder::Encode(string code) {
//   // check error cases
//   shared_ptr<vector<char>> res;
//   if (code.length() < 1) {
//     cerr << "Encode function error: empty string, please input a valid string"
//          << endl;
//     return res;
//   }

//   // check if the given string is valid
//   if (!validString(code)) {
//     cerr << "The given string contains invalid characters" << endl;
//     return res;
//   }

//   // since we have done the mapping in the constructor
//   // so we are able to convert code to char directly according to the map
//   shared_ptr<TreeNode> curr(root);
//   vector<char> character;
//   for (int i = 0; i < code.length(); i++) {
//     if (code[i] == '0') {
//       curr = curr->left;
//     } else {
//       curr = curr->right;
//     }

//     if (curr->left == nullptr && curr->right == nullptr) {
//       character.push_back(curr->letter);
//       curr = root;
//     }
//   }

//   res = make_shared<vector<char>>(character);
//   return res;
// }

// // Decode an array of bytes into a std::string.
// string Encoder::Decode(shared_ptr<vector<char>> character) {
//   // since we have done the mapping in the constructor
//   // so we are able to convert code to string directly according to the map
//   string res = "";
//   if (!character) {
//     cerr << "Decode function error: input is nullptr" << endl;
//     return res;
//   }

//   for (char data : *character) {
//     res += huffmanMap[data];
//   }

//   return res;
// };

// // additional functions below

// // check input string
// bool Encoder::validString(string code) {
//   for (int i = 0; i < code.length(); i++) {
//     if (code[i] != '0' && code[i] != '1') {
//       return false;
//     }
//   }

//   return true;
// };

// // traverse the Huffman tree and map the coresponding code
// void Encoder::decodeHelper(shared_ptr<TreeNode> node, string code) {
//   // check if node is nullptr if so return
//   if (!node) {
//     return;
//   }

//   // base case
//   if (!node->left && !node->right) {
//     this->huffmanMap[node->letter] = code;
//     cout << node->letter << ": " << code << endl;
//   }

//   // recursion
//   // go left + 0, right + 1
//   decodeHelper(node->left, code + "0");
//   decodeHelper(node->right, code + "1");
// }

// // gnerate HuffmanTree
// // put values to unordered_map<char, string> huffmanMap;
// void Encoder::generateHuffmanTree() {
//   // when vector frequencies is empty
//   if (length <= 0 || length > 26) {
//     return;
//   }

//   // priority queue is created to store nodes in Huffman tree
//   priority_queue<shared_ptr<TreeNode>, vector<shared_ptr<TreeNode>>, Compare>
//       pq;

//   // iterate map
//   int i = 0;
//   for (int freq : *frequencies) {
//     shared_ptr<TreeNode> node = make_shared<TreeNode>(letter[i], freq);
//     pq.push(node);
//     i++;
//   }

//   // while loop traverse priority_queue
//   // since we need to compare two nodes in the tree
//   // so while loop until only one node inside
//   while (pq.size() != 1) {
//     // pop out two min values in the pq
//     shared_ptr<TreeNode> left = pq.top();
//     pq.pop();
//     shared_ptr<TreeNode> right = pq.top();
//     pq.pop();

//     int combineFreq = left->frequency + right->frequency;

//     // once we combined them, create a newNdoe and push it back to pq
//     // when we put the new node into pq, the first parameter which is char will
//     // not be used so we could create any char except lowercase letter
//     shared_ptr<TreeNode> newNode = make_shared<TreeNode>('*', combineFreq);

//     newNode->left = left;
//     newNode->right = right;
//     pq.push(newNode);
//   }

//   // take the last one node out of pq and store it to root
//   root = pq.top();

//   decodeHelper(root, "");
// }