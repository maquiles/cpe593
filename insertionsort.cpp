#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void insertionSort(int arr[], int n){
    int temp, j;
    for (int i = 1; i<n; i++){
        temp = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
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
    
        insertionSort(nums, size);
    
        for (int j = 0; j < size; j++){
            cout<< nums[j]<< " ";
        }
        cout<<"\n";
        return 0;
}