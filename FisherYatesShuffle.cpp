#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

using namespace std;

void badShuffle(int arr[], int n){
    srand(time(NULL));
    for (int i=n-1; i>0;i--){
        int rnd = rand() % i;
        swap(arr[rnd], arr[i]);
    }
}

int main(){
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(nums)/sizeof(nums[0]);
    
        cout<<size<<endl;
    
        for (int i = 0; i< size; i++){
            cout<< nums[i]<< " ";
        }
        cout<<"\n";
    
        badShuffle(nums, size);
    
        for (int j = 0; j < size; j++){
            cout<< nums[j]<< " ";
        }
        cout<<"\n";
        return 0;
}