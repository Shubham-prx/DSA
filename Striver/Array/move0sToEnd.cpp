#include <iostream>
#include <vector>
using namespace std;

void move0sToEnd(vector<int>&vec) {
    int n = vec.size();
    if(n<=1) return;
    int i=0;
    while(i<n && vec[i] != 0) i++;
    if(i==n) return;
    // for(i=0; i<n; i++) if(vec[i] == 0) if(i==n-1) return; else break;
    for(int j=i+1; j<n; j++) {
        if(vec[j] != 0) {
            swap(vec[j], vec[i]);
            i++;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    
    move0sToEnd(vec);
    for(auto it: vec){
        cout<<it<<" ";
    }
}





// void move0sToEnd(vector<int>&vec) {
//     int n = vec.size();
//     if(n<=1) return;
//     vector<int>temp;
//     for(auto it: vec){
//         if(it != 0)
//         temp.push_back(it);
//     }
//     int n0s = n - temp.size();
//     for(int i = 0; i<n0s; i++) temp.push_back(0);
//     vec = temp;
// }

//myS
// void move0sToEnd(vector<int>&vec) {
//     int n = vec.size();
//     if(n<=1) return;
//     for(int i=0; i<n; i++){
//         if(vec[i] == 0){
//             for(int j=i+1; j<n; j++){
//                 if(vec[j] != 0) {
//                     swap(vec[i], vec[j]);
//                     break;
//                 }
//             }
//         }
//     }
// }