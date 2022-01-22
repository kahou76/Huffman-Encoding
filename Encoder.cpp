# include "Encoder.h"

Encoder::Encoder(shared_ptr<vector<int>> fq){
        letter = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','|'};
        if(fq->size() != 27){
            throw invalid_argument("Constructor Error: Must have 26 Letter frequenices and one delimiter frequency at the 27th index");
        }
        this->frequency = fq;
        BuildUpBsTree();

    }

shared_ptr<vector<char>> Encoder::Encode(string str){
        shared_ptr<vector<char>> result;
        vector<char> save;
        vector<char> v;
        queue<int> store;
        
        

        //if string is not Alphabet
        if(!isAlphabet(str)){
            throw invalid_argument("Encode Error: the string input is not Alphabet");
        }
        str += '|';

        //if the string is empty
        if(str.size() == 0){
            throw invalid_argument("Encode Error: the string input is empty");
            // cerr << "Encode Error: the string input is empty" << endl;
            // return result;
        }

        for(int i=0; i<str.size(); i++){
            //if string has lowercase
            if(isupper(str[i])){
                //str[i]=tolower(str[i]);
                throw invalid_argument("Encode Error: the input string is uppercase");
            }
            // example: str[i] = a; tmp = 10011 
            string tmp = SavingCode[str[i]];
            // string myString = "01000101";
            // int z = atoi(myString.c_str());
            // cout << z << endl;
                for(int j =0 ;j <tmp.size(); j++){
                    char c = tmp[j];
                    int s = tmp[j] - '0';
                    //cout << "S: " << s << endl;
                    save.push_back(c);
                    store.push(s);
                    
                }

            //push the delimiter | at the end of vector
            // string end = SavingCode['|'];
            // for(int u=0; u<end.size(); u++){

            // }
        }
        cout << "Enode Output: {";
        for(int y = 0; y<save.size(); y++){
            cout << "'" << save[y] << "'" << ",";
        }
        cout << "}";
        cout << endl;

        
        
        // 10011010 10101101 01010111
        //while no empty
        //push 10011010 for eight times loop
        while(!store.empty()){
            
            vector<int> eightbit;
            for(int i=0; i<8; i++){
                
                
                    if(store.empty()){
                        break;
                    }else{
                        eightbit.push_back(store.front());
                        store.pop();
                    }
                    
                     
                
            }
            char res = packInt(eightbit);
            v.push_back(res);

         }
        

        result = make_shared<vector<char>>(v);
        //cout << "Str: " << str << endl;
        return result;
    }


string Encoder::Decode(shared_ptr<vector<char>> code){
        string result;
        string store = "";
        shared_ptr<vector<char>> unpack = unpackChar(code);

        //if the vector is empty
        if(code->size() < 1){
            throw invalid_argument("Decode Error: It is empty");
        }

        for(char c : *unpack){
            if(!isNumber(c)){
                throw invalid_argument("Decode Error: the input character is not either 1 or 0");
            }
            
            unordered_map<string,char>::const_iterator got = SavingChar.find(store);
            if(got == SavingChar.end()){
                //didn't find
                store += c;
                //cout << "Store: " << store << endl;
            }else{
                //found
                //If found the delimiter |, end the decode function and return the result
               
                if(SavingChar[store] == '|'){
                    //break
                    cout << "\nDecode Output: " << result << endl;
                    return result;
                    break;
                }else{
                    result += SavingChar[store];
                    //cout << "Letter: " << SavingChar[store] << ", Code: " << store << endl;
                    store.clear();
                    store += c;
                }
                
            }
        }
        unordered_map<string,char>::const_iterator got = SavingChar.find(store);
        
        if(got == SavingChar.end()){
                //If cannot find the direct Letter, throw exception
                throw invalid_argument("Decode Error: Cannot find the Letter with your input character vector");
            }else{
                //found
                //If found the delimiter |, end the decode function and return the result
               
                if(SavingChar[store] == '|'){
                    //break
                    cout << "\nDecode Output: " << result << endl;
                    return result;
                }else{
                    result += SavingChar[store];
                }
            }
        
        cout << "\nDecode Output: " << result << endl;
        return result;
    }

void Encoder::SaveCodes(shared_ptr<LetterNode> curr, string str){
        if(curr == nullptr){
            return;
        }

        if(curr->getLetter() != '$'){
            //cout << curr->getLetter() << ": " << str << endl;
            // SavingCode = {curr->getLetter(),str};
            //cout << "TOTAL: "<<tf << endl;
            SavingCode[curr->getLetter()] = str;
            SavingChar[str] = curr->getLetter();
            cout << "Letter: " << curr->getLetter() << ": " << SavingCode[curr->getLetter()] << endl;
            
        }

        SaveCodes(curr->getLeft(), str + "0");
        SaveCodes(curr->getRight(), str + "1");

        
    }


void Encoder::BuildUpBsTree(){
        
        shared_ptr<LetterNode> left, right, top, left1, right1;

        priority_queue<shared_ptr<LetterNode>, vector<shared_ptr<LetterNode>>, greater> pg;

        int i = 0;
        for(int fq : *frequency){

            //pg.push( new LetterNode(letter[i], freq[i]) );
            //if the freq is 0, dont create node
            if(fq == 0){
                // stop create node
            }else{
                // create node
                
                shared_ptr<LetterNode> node = make_shared<LetterNode>(letter[i],fq);
                pg.push(node);
            }
            
            i++;
        }
        //Push the delimiter | node into pq
        // shared_ptr<LetterNode> node = make_shared<LetterNode>(letter[26],INT_MAX);
        // pg.push(node);
        

        while(pg.size() != 1){
            left = pg.top();
            pg.pop();
            right = pg.top();
            pg.pop();

            // top = new LetterNode('$', left->getFreq() + right->getFreq());

            top = make_shared<LetterNode>('$',left->getFreq() + right->getFreq());
            //cout << tc << endl;

            // If the letters have the same freq, go with alphabetic order
            // for example: a = 1, h = 1
            if(left->getFreq() == right->getFreq()){
                // go with alphabetic order
                left1 = left;
                right1 = right;
                while(left1->getLeft() != nullptr){
                    left1 = left1->getLeft();
                }
                while(right1->getLeft() != nullptr){
                    right1 = right1->getLeft();
                }
                char a = left1->getLetter();
                char b = right1->getLetter();
                int a1 = a -'0';
                int b1 = b -'0';

                cout << "A: " << a1 << "    B1: " << b1 << endl;

                if(a1 < b1){
                    // the smaller ascii value go left, larger go right
                    top->setLeft(left);
                    top->setRight(right);
                }else{
                    top->setLeft(right);
                    top->setRight(left);
                }
            }else{
                top->setLeft(right);
                top->setRight(left);
            }
            

            pg.push(top);

        }

        SaveCodes(pg.top(), "");



    }

bool Encoder::isNumber(const char &c){
        
            if(c != '1' && c != '0'){
                // the char c is not either 1 or 0
                return false;
            }
            return true;
        
    }

bool Encoder::isAlphabet(const string &str){
        int check;
        for(int i=0; i<str.size(); i++){
            check = isalpha(str[i]);
            if(!check){
                return false;
            }
        }
        return true;
    }

char Encoder::packInt(vector<int> v){
    char result = 0x00; //0000 0000
    string str = "";
    for(int i=0; i<v.size(); i++){
        //str *= 10;
        str += to_string(v[i]);
        result = result << 1; //shift left
        result = result | v[i]; // value is 0b0 or 0b1
    }
    int shift = 8 -v.size(); 
    cout << "Shift: " << shift << endl;
    result = result << shift;
    
    string binary = bitset<8>(result).to_string();
    
    cout << "decial output: " << str << endl;
    cout << "Binary output: " << binary << endl;

    return result;

}

shared_ptr<vector<char>> Encoder::unpackChar(shared_ptr<vector<char>> v){
    shared_ptr<vector<char>> result;
    vector<char> store;

    for(int i=0; i<v->size(); i++){
        char c = v->at(i);
        string binary = bitset<8>(c).to_string();
        for(int j=0; j<binary.size(); j++){
            store.push_back(binary[j]);
        }
    }
    
    result = make_shared<vector<char>>(store);
    return result;
}