# include "Encoder.h"

Encoder::Encoder(shared_ptr<vector<int>> fq){
        letter = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        if(fq->size() != 26){
            throw invalid_argument("Constructor Error: Must have 26 Letter frequenices");
        }
        this->frequency = fq;
        BuildUpBsTree();

    }

shared_ptr<vector<char>> Encoder::Encode(string str){
        shared_ptr<vector<char>> result;
        vector<char> save;

        //if string is not Alphabet
        if(!isAlphabet(str)){
            throw invalid_argument("Encode Error: the string input is not Alphabet");
        }

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
            string tmp = SavingCode[str[i]];
                for(int j =0 ;j <tmp.size(); j++){
                    char c = tmp[j];
                    save.push_back(c);
                    
                }
            
            

        }
        cout << "Enode Output: {";
        for(int y = 0; y<save.size(); y++){
            cout << "'" << save[y] << "'" << ",";
        }
        cout << "}";
        cout << endl;
        result = make_shared<vector<char>>(save);
        //cout << "Str: " << str << endl;
        return result;
    }

string Encoder::Decode(shared_ptr<vector<char>> code){
        string result;
        string store = "";

        //if the vector is empty
        if(code->size() < 1){
            throw invalid_argument("Decode Error: It is empty");
        }

        for(char c : *code){
            if(!isNumber(c)){
                throw invalid_argument("Decode Error: the input character is not either 1 or 0");
            }
            
            unordered_map<string,char>::const_iterator got = SavingChar.find(store);
            if(got == SavingChar.end()){
                //didn't find
                store += c;
                cout << "Store: " << store << endl;
            }else{
                //found
                result += SavingChar[store];
                cout << "Letter: " << SavingChar[store] << ", Code: " << store << endl;
                store.clear();
                store += c;
            }
        }
        unordered_map<string,char>::const_iterator got = SavingChar.find(store);
        
        if(got == SavingChar.end()){
                //If cannot find the direct Letter, throw exception
                throw invalid_argument("Decode Error: Cannot find the Letter with your input character vector");
            }else{
                //found
                result += SavingChar[store];
                cout << "Letter: " << SavingChar[store] << ", Code: " << store << endl;
                store.clear();
                //store += c;
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
            SavingCode[curr->getLetter()] = str;
            SavingChar[str] = curr->getLetter();
            cout << "Letter: " << curr->getLetter() << ": " << SavingCode[curr->getLetter()] << endl;
            
        }

        SaveCodes(curr->getLeft(), str + "1");
        SaveCodes(curr->getRight(), str + "0");

        
    }

void Encoder::BuildUpBsTree(){
        
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