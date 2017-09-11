//c++ program that uses the quicksort algorithm to sort numbers within an array in ascending order

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *arr, const int left, const int right){
    const int mid = left + (right - left)/2;
    const int pivot = arr[mid];
    std::swap(arr[mid], arr[left]);
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

void quicksort(int *arr, const int left, const int right){
    if(left >= right){
        return;
    }

    int part = partition(arr, left, right);
    quicksort(arr, left, part-1);
    quicksort(arr, part+1, right);
}

int main(){
    int nums[10] = {1,4,5,8,9,10,7,6,3,2};
    int size = sizeof(nums)/sizeof(nums[0]);

    cout<<size<<endl;

    for (int i = 0; i< size; i++){
        cout<< nums[i]<< " ";
    }
    cout<<"\n";

    quicksort(nums, 0, size-1);

    for (int j = 0; j < size; j++){
        cout<< nums[j]<< " ";
    }
    cout<<"\n";
    return 0;
}