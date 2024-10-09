#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
        unordered_map<char, trienode*> children;
};

class trie{

    public:

        trienode *root;

        trie(){
            root = new trienode();
        }

        void insert(string s){

            trienode *temp = root;

            for(auto c : s){
                if(temp -> children.find(c) == temp -> children.end()){
                    trienode *node = new trienode();
                    (temp -> children[c]) = node;
                }
                temp = temp -> children[c];

            }

        }

        bool find(string s){

            trienode *temp = root;

            for(auto c : s){
                if(temp -> children.find(c) == temp -> children.end()){
                    return false;
                }
                temp = temp -> children[c];
            }
            return true;

        }

};

int main(){

    trie a;

    a.insert("abcd");
    a.insert("abfg");

    cout << a.find("abcd") << endl;

    return 0;

}
