/**
 * Matthew Aquiles
 * CPE 593 HW4a GrowArray
 * due 10-17-2017
**/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class GrowArray {
private:
    int capacity;
    int *data;

public:
    GrowArray(){
        data = nullptr;
        capacity = 0;
    }

    ~GrowArray(){
        delete[] data;
    }

    GrowArray(const GrowArray& orig){
        capacity = orig.capacity;
        data = new int[capacity];
        for (int i = 0; i < capacity; i++){
            data[i] = orig.data[i];
        }
    }

    GrowArray& operator=(const GrowArray& orig){
        if(this != &orig){
            delete[] data;
            capacity = orig.capacity;
            data = new int[capacity];
            for (int i = 0; i < capacity; i++){
                data[i] = orig.data[i];
            }
        }
        return *this;
    }

    //add a number to the front of the GrowArray
    void addFirst(int a){
        int* temp = new int[capacity+1];
        temp[0] = a;
        for (int i = 0; i < capacity; i++){
            temp[i+1] = data[i];
        }
        capacity++;
        delete[] data;
        data = temp;
    }

    //ADD_FRONT
    //means add start, start+step, start=2*step,... until end at the front of the array
    void addFront(int start, int step, int end){
        addFirst(start);
        int i = 1;
        while (start + (step*i) < end){
            addFirst(start + (step*i));
            i++;
        }
    } 

    //add a number to the end of the GrowArray
    void addLast(int b){
        int* temp = new int[capacity+1];
        for (int i = 0; i < capacity; i++){
            temp[i] = data[i];
        }
        temp[capacity] = b;
        capacity++;
        delete[] data;
        data = temp;
    }

    //ADD_BACK
    //means add start, start+step, start=2*step,... until end at the back of the array
    void addFront(int start, int step, int end){
        addLast(start);
        int i = 0;
        while (start + (step*i) < end){
            addLast(start + (step*i));
            i++;
        }
    }

    //REMOVE_FRONT
    //means remove the first n numbers from the list
    void removeFront(int n){
        if (capacity == 0){
            return;
        }
        for (int i = 0; i < capacity-n; i++){
            data[i] = data[i+n];
        }
        capacity -= n;
    }

    //REMOVE_BACK
    //means remove the last m numbers from the list
    void removeBack(int m){
        if (capacity == 0){
            return;
        }
        while(m != 0){
            capacity--;
            m--;
        }
    }

    //OUTPUT
    void output(){
        for (int i = 0; i < capacity; i++){
            cout<< data[i]<< ",";
        }
        cout<< "\n";
    }

    void clear(){
        delete[] data;
        data = nullptr;
        capacity = 0;
    }

    int get(int i){
        return data[i];
    }

    void set(int i, int val) {
        data[i] = val;
    }

    int operator[] (int i) const {
        return data[i];
    }

    int& operator[] (int i) {
        return data[i];
    }

    friend ostream& operator << (ostream& s, const GrowArray& list){
        s << '[';
        for (int i = 0; i < list.capacity; i++){
            s << list.data[i] << ' ';
        }
        return s << ']';
    }

    int size(){
        return capacity;
    }
};


int main(){


    return 0;
}