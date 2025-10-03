#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void leftRotateByOnePlace(vector<int>&vec){
    if(vec.size()<=1) return;
    int first = vec[0];
    for(int i=1; i<vec.size(); i++) {
        vec[i-1] = vec[i];
    }
    vec[vec.size() - 1] = first;
}


int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    
    leftRotateByOnePlace(vec);
    for(auto it: vec){
        cout<<it<<" ";
    }
}
