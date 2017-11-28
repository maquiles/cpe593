/**
 * Matthew Aquiles
 * CPE 593
 * HW5a - HashMapLinearProbing
 * 
 * Hashing function is based off of code found on algolist.net
 * http://www.algolist.net/Data_structures/Hash_table/Simple_example
 * 
**/

#include<iostream>

using namespace std;
 
class HashMap { 
private:

    class HashEntry {
    private:
        int key;
    public:
        int collisions;
        HashEntry(int k, int c) : key(k), collisions(c) {}
        int getCollisions() { return collisions; }
        int getKey() { return key; }
    };

    HashEntry **table;
    int tableSize;
public:
    HashMap(int ts) : tableSize(ts*2) {
        table = new HashEntry*[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }
    ~HashMap() {
        for (int i = 0; i < tableSize; i++)
            if (table[i] != nullptr)
                delete table[i];
         delete[] table;
      }
 
    int get(int key) {
        int hash = (key % tableSize);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % tableSize;
        if (table[hash] == nullptr)
            return -1;
        else
            return table[hash]->getKey();
    }
 
    void put(int key) {
        int hash = (key % tableSize);
        int c = 0;
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % tableSize;
            c++;
        if (table[hash] != nullptr)
            delete table[hash];
        table[hash] = new HashEntry(key, c);
    }

    void displayHistogram(){
        int* histogram = new int[51];
        
        for (int i = 0; i < tableSize-1; i++){
            if(table[i]->collisions > 50){
                histogram[51]++;
            }
            else{
                if(table[i] != nullptr){
                    histogram[table[i]->collisions]++;
                }
            }
        }
        cout<< "testy mctesterson\n";
        for (int j = 0; j < 51; j++){
            cout<< j<< "\t"<< histogram[j]<< "\n";
        }
        cout<< "51\t"<< histogram[51]<< "\n";
        delete[] histogram;
    }
};

int main(){
    int n;
    cout<< "input an integer\n";
    cin >> n;
    HashMap *m = new HashMap(n);
    for (int i = 0; i < n; i++)
        m->put(i);
    m->displayHistogram();
    return 0;
}