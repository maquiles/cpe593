#include<iostream>
#include<cstdint>
using namespace std;

class BadGrowArray {
private:
    uint32_t capacity;
    int* data;

public:
    BadGrowArray(){
        data = nullptr;
        capacity = 0;
    }

    ~BadGrowArray(){
        delete [] data;
    }

    BadGrowArray(const BadGrowArray& orig) : //O(n)
        data(new int[orig.capacity]), capacity(orig.capacity) {
        for (int i = 0; i < capacity; i++){
            data[i] = orig.data[i];
        }
    }

    BadGrowArray& operator =(const BadGrowArray& orig){//could be by value if you want (no &) but it would be 3 times slower
        BadGrowArray copy(orig);
        swap(data, copy.data);
        capacity = copy.capacity;
    }

    void addEnd(int v){ //O(n)
        int* temp = data;
        data = new int[capacity+1];
        for (int i = 0; i < capacity; i++){
            data[i] = temp[i];
        }
        data[capacity] = v;
        delete [] temp;
        capacity++;
    }

    void addStart(int v){
        int* temp = data;
        data = new int[capacity+1];
        data[0] = v;
        for (int i = 0; i<capacity; i++){
            data[i+1] = temp[i];
        }
        delete [] temp;
        capacity++;
    }

    void insert(int i, int v){//O(n)
        int* temp = data;
        data = new int[capacity+1];
        for (int j = i; j<capacity; j++){
            data[j+1] = temp[j];
        }
        delete [] temp;
        capacity++;
    }

    void removeEnd(){//O(1)
        capacity--;
    }

    void removeStart(){
        int* temp = data;
        capacity--;
        data = new int[capacity];
        for (int i = 0; i<capacity-1; i++){
            data[i] = temp[i];
        }
        delete [] temp;
    }

    friend ostream& operator << (ostream& s, const BadGrowArray a){
        for (int i = 0; i < a.capacity; i++){
            s << a.data[i] << ' ';
        }
        return s;
    }
};

void f(BadGrowArray a){
    //do something
}

int main(){
    BadGrowArray L1;
    L1.addEnd(5);
    L1.addStart(3);
    BadGrowArray L2 = L1; //make a copy
    BadGrowArray L3;
    L2 = L3;
    f(L1);
    const int n = 10;
    for (int i = 0; i < n; i++){
        L1.addEnd(i);
    }
    L1.insert(2, 19); //delete the 0
    L1.removeEnd(); //9
    L1.removeStart(); //3
    cout<< L1<< "\n";
}