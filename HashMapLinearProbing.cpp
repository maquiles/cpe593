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
#include<vector>

using namespace std;
 
class HashMap { 
private:

    class HashEntry {
    private:
        int key;
        int collisions;
    public:
        HashEntry(int k, int c) : key(k), collisions(c) {}
        int getCollisions() { return collisions; }
        int getKey() { return key; }
    };

    HashEntry **table;
    int tableSize;
public:
    HashMap(int ts) {
        tableSize = ts*2;
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
        int c = 1;
        while (table[hash] != nullptr && table[hash]->getKey() != key){
            hash = (hash + 1) % tableSize;
            c++;
        }
        table[hash] = new HashEntry(key, c);
    }

    void displayHistogram(){
        int* histogram = new int[51];
        
        for (int i = 1; i < tableSize; i++){
            if(table[i] != nullptr){
                int x = table[i]->getCollisions();

                if( x > 50){
                    histogram[50]++;
                }
                else{
                    histogram[x]++;
                }
            }
            else{
                histogram[0]++;
            }
        }

        for (int j = 0; j < 51; j++){
            cout<< j<< "\t"<< histogram[j]<< "\n";
        }
        cout<< ">50\t"<< histogram[50]<< "\n";
        delete[] histogram;
    }
};

int main(){
    int n;
    cout<< "input an integer\n";
    cin >> n;
    HashMap *m = new HashMap(n);
    for (int i = 1; i <= n; i++){
        m->put(i);
    }
    m->displayHistogram();
    return 0;
}