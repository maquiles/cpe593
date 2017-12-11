/**
 * Matthew Aquiles
 * CPE 593
 * HashMapLinearProbing
 * 
 * hashing function used is modified from a stackoverflow answer at link below:
 * https://stackoverflow.com/questions/9577182/convert-each-character-in-string-to-ascii
**/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

class HashMap {
private:
    class LinearChain {
    private:
        vector<string> chain;
        int chainSize;

    public:
        LinearChain() { chainSize = 0;}
        ~LinearChain(){}

        void incChainSize(){ chainSize++; }
        void addToChain(string str){ chain.push_back(str); }
        int getChainSize(){ return chainSize; }

        bool foundInChain(string str){
            for (int i = 0; i < chainSize; i++){
                if(str == chain[i]){
                    return true;
                }
            }
            return false;
        }
    };

    LinearChain **map;
    unsigned long int mapSize;

public:
    HashMap(unsigned long int s){
        mapSize = s;
        map = new LinearChain*[mapSize];
        for (unsigned long int i = 0; i < mapSize; i++)
            map[i] = new LinearChain();
    }
    ~HashMap(){
        for (int i = 0; i < mapSize; i++)
            if (map[i] != nullptr)
                delete map[i];
         delete[] map;
    }

    int hash(string str){
        int sum = 0;
        for (unsigned int i = 0; i < str.size(); i++){
            sum += str[i];
        }
        int hash = sum % mapSize;
        return hash;
    }

    void put(string str){
        int h = hash(str);
        map[h]->addToChain(str);
        map[h]->incChainSize();
    }

    string get(string str){
        int h = hash(str);
        if(map[h]->foundInChain(str) == true){
            return str;
        }
        else{
            return "not found";
        }
    }

    bool found(string str){
        int h = hash(str);
        return map[h]->foundInChain(str);
    }

    void displayHistogram(){
        cout<< "\ninsert\tcount\n";
        for (unsigned long int i = 0; i < mapSize; i++){
            cout<< i<< "\t";
            cout<< map[i]->getChainSize()<< "\n";
        }
    }
};

int main(){
    HashMap *m = new HashMap(3407);//2621 is highest ascii sum for all words * 1.3 (+30%) = 3407

    string line;
    ifstream infile("dict.txt");
    while(getline(infile, line)){
        stringstream iss(line);
        string word;
        iss >> word;
        m->put(word);
    }

    m->displayHistogram();
    cout<< "\n";

    ifstream infile2("hw8.dat");
    while(getline(infile2, line)){
        stringstream iss(line);
        string word;
        iss >> word;
        cout<< word<< ":\t";
        if(m->found(word)){ cout<< "true\n";}
        else{ cout<< "false\n";}
    }
    return 0;
}