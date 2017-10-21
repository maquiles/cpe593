/**
 * Matthew Aquiles
 * CPE 593 HW4a GrowArray
 * due 10-17-2017
**/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class GrowArray {
private:
    int capacity;
    int used;
    int *data;

public:
    GrowArray(){
        data = nullptr;
        capacity = 0;
        used = 0;
    }

    ~GrowArray(){
        delete[] data;
    }

    GrowArray(const GrowArray& orig){
        capacity = orig.capacity;
        used = orig.used;
        data = new int[capacity];
        for (int i = 0; i < capacity; i++){
            data[i] = orig.data[i];
        }
    }

    GrowArray& operator=(const GrowArray& orig){
        if(this != &orig){
            delete[] data;
            capacity = orig.capacity;
            used = orig.used;
            data = new int[capacity];
            for (int i = 0; i < capacity; i++){
                data[i] = orig.data[i];
            }
        }
        return *this;
    }

    //add a number to the front of the GrowArray
    void addFirst(int a){
        if(used == capacity){
            if(capacity == 0){
                capacity = 1;
            }
            else{
                capacity *= 2;
            }
        }

        int* temp = new int[capacity];
        temp[0] = a;
        for (int i = 0; i < used; i++){
            temp[i+1] = data[i];
        }
        used++;
        delete[] data;
        data = temp;
    }

    //ADD_FRONT
    //means add start, start+step, start=2*step,... until end at the front of the array
    void addFront(int start, int step, int end){
        if(step == 0){
            return;
        }
        
        int i = 0;
        while (start + (step*i) <= end){
            addFirst(start + (step*i));
            i++;
        }
    } 

    //add a number to the end of the GrowArray
    void addLast(int b){
        if(used == capacity){
            if(capacity == 0){
                capacity = 1;
            }
            else{
                capacity *= 2;
            }
        }

        int* temp = new int[capacity];
        for (int i = 0; i < used; i++){
            temp[i] = data[i];
        }
        temp[used] = b;
        used++;
        delete[] data;
        data = temp;
    }

    //ADD_BACK
    //means add start, start+step, start=2*step,... until end at the back of the array
    void addBack(int start, int step, int end){
        if(step == 0){
            return;
        }

        int i = 0;
        while (start + (step*i) <= end){
            addLast(start + (step*i));
            i++;
        }
    }

    //REMOVE_FRONT
    //means remove the first n numbers from the list
    void removeFront(int n){
        if (capacity == 0 || used == 0){
            return;
        }

        int* temp = new int[capacity];

        for (int i = 0; i < used-n; i++){
            temp[i] = data[i+n];
        }
        delete[] data;
        data = temp;
        used -= n;
    }

    //REMOVE_BACK
    //means remove the last m numbers from the list
    void removeBack(int m){
        if (capacity == 0 || used == 0){
            return;
        }

        int* temp = new int[capacity];
        for (int i = 0; i < used-m; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        used -= m;
    }

    //OUTPUT
    void output(){
        for (int i = 0; i < used; i++){
            cout<< data[i]<< ",";
        }
        cout<< "\n";
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
    GrowArray ga;
    ifstream infile("HW4a.txt");
    string line;

    while(getline(infile, line)){
        stringstream iss(line);
        string instruction, numbers;
        iss >> instruction >> numbers;

        if (instruction == "OUTPUT"){
            ga.output();
        }
        else if (instruction == "ADD_FRONT"){
            istringstream ss(numbers);
            vector<int> vec;
            string str;
            while (getline(ss, str, ':')){
                vec.push_back( stoi(str.c_str()) );
            }

            ga.addFront(vec[0], vec[1], vec[2]);
        }
        else if (instruction == "ADD_BACK"){
            istringstream ss(numbers);
            vector<int> vec;
            string str;
            while (getline(ss, str, ':')){
                vec.push_back( stoi(str.c_str()) );
            }

            ga.addBack(vec[0], vec[1], vec[2]);
        }
        else if (instruction == "REMOVE_FRONT"){
            int n = stoi(numbers);
            ga.removeFront(n);
        }
        else if (instruction == "REMOVE_BACK"){
            int m = stoi(numbers);
            ga.removeBack(m);
        }
        else{
            cout<< "instruction was not understood"<< "\n";
        }
    }

    return 0;
}