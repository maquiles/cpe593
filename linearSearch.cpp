#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int x){
    for(int i = 0; i<n; i++){
        if(arr[i] == x){
            return arr[i];
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
    
        cout<< linearSearch(nums, size, 5)<<"\n";
        return 0;
}