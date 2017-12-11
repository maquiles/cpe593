/**
 * Matthew Aquiles
 * CPE 593
 * Trie Dictionary
 * 
 * help found at following stackoverflow question:
 * https://stackoverflow.com/questions/15892922/c-dictionary-trie-implementation
 * 
**/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

class Trie {
private:
    class Node {
    public:
        bool isWord;
        Node* next[26];
    };

    Node* root;

public:
    Trie() { initNode(root); }

    void initNode(Node*& n){
        n = new Node();
        n->isWord = false;
        for (int i = 0; i < 26; i++){
            n->next[i] = nullptr;
        }
    }

    Node* endOfString(string s, bool insert){
        Node* curr = root;
        Node* nxt = root;
        for (unsigned int i = 0; i < s.length(); i++){
            if(isalpha(s[i]) == true){
                int letter = (tolower(s[i]) - 'a');
                nxt = curr->next[letter];
                if(nxt == nullptr){
                    if(insert == false){
                        return nullptr;
                    }

                    initNode(nxt);
                    curr->next[letter] = nxt;
                }
                curr = curr->next[letter];
            }
        }
        return curr;
    }

    void insert(string s){
        Node* curr = endOfString(s, true);
        curr->isWord = true;
    }

    bool findWord(string s){
        Node* curr = endOfString(s, false);
        if(curr == nullptr){
            return false;
        }
        else{
            return curr->isWord;
        }
    }

    bool findPrefix(string s){
        Node* curr = endOfString(s, false);
        if(curr == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    Trie *t = new Trie();

    string line;
    ifstream infile("dict.txt");
    while(getline(infile, line)){
        stringstream iss(line);
        string word;
        iss >> word;
        t->insert(word);
    }

    ifstream infile2("hw5.txt");
    while(getline(infile2, line)){
        stringstream iss(line);
        string word;
        iss >> word;
        if(t->findPrefix(word)){ cout<< "true\n";}
        else{ cout<< "false\n";}
    }
    return 0;
}