/* Matthew Aquiles
** CPE 593 hw2b heapsort
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
 
//n is the size of the heap
void heapify(vector<int> &arr, int size, int i){
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
 
    if (left < size && arr[left] > arr[root]){
        root = left;
    }
 
    if (right < size && arr[right] > arr[root]){
        root = right;
    }
 
    if (root != i){
        swap(arr[i], arr[root]);
        heapify(arr, size, root);
    }
}
 
void heapsort(vector<int> &arr, int size){
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }

    for (int i=size-1; i>=0; i--){
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void print_vec(vector<int> V){
    for(int i=0; i<V.size(); i++){
        cout<< " "<< V[i];
    }
    cout<< "\n";
}

int main(){
    ifstream infile("hw2a.dat");
    string line;

    while (getline(infile, line)){
        stringstream iss(line);
        int n;
        vector<int> vec;
        while(iss >> n){
            vec.push_back(n);
        }

        if(vec.size() == 1){
            //this is the size of the array in the next line;
            //do nothing
        }
        else{
            heapsort(vec, vec.size());
            print_vec(vec);
        }
    }
    return 0;
}