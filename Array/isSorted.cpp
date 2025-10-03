#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>&vec) {
    if(vec.size() <= 1) return true;
    for(int i=1; i<vec.size(); i++){
        if(vec[i] < vec[i-1])
        return false;
    }
    return true;
}


int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    
    if(isSorted(vec)) cout<<"Sorted";
    else cout<<"Not sorted properly";
}
