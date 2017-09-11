// c++ program that used the heapsort algorithm to sort numbers withing an array in ascending order
#include <iostream>

using namespace std;
 
//n is the size of the heap
void heapify(int arr[], int size, int i){
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
 
void heapsort(int arr[], int size){
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

int main(){
    int nums[10] = {1,4,5,8,9,10,7,6,3,2};
    int size = sizeof(nums)/sizeof(nums[0]);
    
        cout<<size<<endl;
    
        for (int i = 0; i< size; i++){
            cout<< nums[i]<< " ";
        }
        cout<<"\n";
    
        heapsort(nums, size);
    
        for (int j = 0; j < size; j++){
            cout<< nums[j]<< " ";
        }
        cout<<"\n";
        return 0;
}