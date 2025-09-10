#include <iostream>
#include <vector>
using namespace std;

void reverseRange(vector<int>&vec, int start, int end) {
    while(start < end) {
        int temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;
        start++;
        end--;
    }
}

void rightRotationByDPlaces(vector<int>&vec, int d) {
    int n = vec.size();
    if(n == 0) return;
    d = d % n;
    if(d == 0) return;

    reverseRange(vec, 0, n-d-1);
    reverseRange(vec, n-d, n-1);
    reverseRange(vec, 0, n-1);
}

int main() {
    int n,d;
    cout<<"Enter the size and no. of places to rotate: ";
    cin>>n>>d;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    
    rightRotationByDPlaces(vec,d);
    for(auto it: vec){
        cout<<it<<" ";
    }
}