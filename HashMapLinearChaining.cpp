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

using namespace std;

class HashMap {
private:
    class LinearChain {
    public:
        vector<string> chain;
        int chainSize;
    private:
        LinearChain(string str) {
            chainSize = 1;
            chain.push_back(str);
        }
        ~LinearChain(){
            for (int i = 0; i < chainSize; i++){
                delete chain[i];
            }
            delete[] chain;
            delete chainSize;
        }

        getChainSize(){ return chainSize; }

        getFromChain(string str){
            for (int i = 0; i < chainSize; i++){
                if(str == chain[i]){
                    return chain[i];
                }
            }
        }
    }

    LinearChain **map;
    int mapSize;

public:
    HashMap(int s){
        mapSize = s;
        chain = new LinearChain*[mapSize];
        for (int i = 0; i < mapSize; i++)
            chain[i] = nullptr;
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

    void put(){

    }

    void get(){

    }

    void displayHistogram(){

    }
}

int main(){

    return 0;
}