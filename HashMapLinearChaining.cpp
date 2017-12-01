/**
 * Matthew Aquiles
 * CPE 593
 * HashMapLinearProbing
 * 
 * hashing function sums up the ascii values for the characters in each word in the dictionary
 * and uses it to hash 
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

        string getFromChain(string str){
            for (int i = 0; i < chainSize; i++){
                if(str == chain[i]){
                    return chain[i];
                }
            }
            return "string not found";
        }
    };

    LinearChain **map;
    int mapSize;

public:
    HashMap(int s){
        mapSize = s;
        map = new LinearChain*[mapSize];
        for (int i = 0; i < mapSize; i++)
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
        return map[h]->getFromChain(str);
    }

    void displayHistogram(){
        cout<< "\ninsert\tcount\n";
        for (int i = 0; i < mapSize; i++){
            cout<< i<< "\t";
            cout<< map[i]->getChainSize()<< "\n";
        }
    }
};

int main(){
    HashMap *m = new HashMap(1024);

    ifstream infile("dict.txt");
    string line;

    while(getline(infile, line)){
        stringstream iss(line);
        string word;
        iss >> word;
        m->put(word);
    }

    cout<< m->get("aaa")<< "\n";;

    m->displayHistogram();
    return 0;
}