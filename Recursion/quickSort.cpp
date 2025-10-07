#include <bits/stdc++.h>
using namespace std;

int pIndex(vector<int>&arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i <= high-1) {
            i++;
        }

        while(arr[j] > pivot && j >= low+1) {
            j--;
        }
        
        if(i<j) 
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    
    return j;
}

void quickSort(vector<int>&arr, int low, int high) {
    if(low < high){
        int pivot = pIndex(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    vector<int>arr = {4, 3, 2, 5, 6, 1, 7, 8, 9};
    quickSort(arr, 0, arr.size()-1);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}