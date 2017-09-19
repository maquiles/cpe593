#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int x){
    int i = 0;
    int j = n-1;
    
    while(i<j){
        int guess = (i+j)/2;
        if(arr[guess]<x){
            j = guess-1;
        }
        else if(arr[guess]>x){
            i = guess+1;
        }
        else{
            return arr[guess];
        }
    }
    return -1;
}

int main(){
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(nums)/sizeof(nums[0]);
    
        cout<<size<<"\n";
    
        for (int i = 0; i< size; i++){
            cout<< nums[i]<< " ";
        }
        cout<<"\n";
    
        cout<< binarySearch(nums, size, 5)<<"\n";
        return 0;
}