/* Matthew Aquiles
** CPE 593 hw2a quicksort
*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, const int left, const int right){
    const int mid = left + (right - left)/2;
    const int pivot = arr[mid];
    swap(arr[mid], arr[left]);
    int i = left + 1;
    int j = right;

    while(i <= j){
        while(i<= j && arr[i] <= pivot){
            i++;
        }
        while(i <= j && arr[j] > pivot){
            j--;
        }

        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i-1],arr[left]);
    return i-1;
}

void quicksort(vector<int> &arr, const int left, const int right){
    if(left >= right){
        return;
    }

    int part = partition(arr, left, right);
    quicksort(arr, left, part-1);
    quicksort(arr, part+1, right);
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
            quicksort(vec, 0, vec.size()-1);
            print_vec(vec);
        }
    }
    return 0;
}