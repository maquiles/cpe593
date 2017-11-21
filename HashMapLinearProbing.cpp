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
        HashEntry(int k) : key(k) {}

        int getKey() { return key; }
    };

    HashEntry **table;
    int tableSize;
public:
    HashMap(int ts) : tableSize(ts) {
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
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % tableSize;
        if (table[hash] != nullptr)
            delete table[hash];
        table[hash] = new HashEntry(key);
    }
};

int main(){
    int n;

    cin >> n;
    HashMap *m = new HashMap(n);
    for (int i = 0; i < n; i++)
        m->put(i);
    //m.displayHistogram()
    return 0;
}