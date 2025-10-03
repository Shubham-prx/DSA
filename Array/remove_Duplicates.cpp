#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void removeDuplicates(vector<int>&vec) {
    if(vec.empty()) return;                               //edge

    //if unsorted then sort it
    //sort(vec.begin(), vec.end()) 

    int i = 0;
    for(int j=0; j<vec.size(); j++) {
        if(vec[i] != vec[j]) {
            vec[i+1] = vec[j];                             //i says take the position ahead of me. remember first element is not duplicate
            i++;
        }
    }
    vec.resize(i+1);
}


int main() {
    int n;
    cout<<"Enter the size>0: ";
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    
    removeDuplicates(vec);
    for(auto it: vec){
        cout<<it<<" ";
    }
}












// void removeDuplicates(vector<int>&vec) {
//     set<int>set;
//     for(auto it: vec){
//         set.insert(it);
//     }
//     int index = 0;
//     for(auto it: set){
//         vec[index] = it;
//         index++;
//     }
//     vec.resize(index);
// }
