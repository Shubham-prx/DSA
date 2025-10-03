#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int secondLargest(vector<int>&vec, int n) {

    if(n < 2) return INT_MIN;                             //EDGE case

    int largest = vec[0];
    int sLargest = INT_MIN;
    for(auto it: vec){
        if(it > largest) {sLargest = largest; largest = it;}
        else if(it < largest) {if(it > sLargest) sLargest = it;}
        else continue;
    }
    return sLargest;
}

int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i<n; i++) {
        cin>>vec[i];
    }
    int sLargest = secondLargest(vec, n);

    if(sLargest == INT_MIN) cout <<"No second largest element exists";
    else
    cout<<sLargest;
    
}














//<----------------BRUTE------------------>
// int secondLargest(vector<int>&vec, int n) {
//     sort(vec.begin(), vec.end());
//     int sLargest = INT_MIN;
//     for(int i= n-2; i>=0; i--){
//         if(vec[i] < vec[n-1]){
//             sLargest = vec[i];
//             break;
//         }
//     }
//     return sLargest;
// }


//<----------------BETTER------------------>
// int secondLargest(vector<int>&vec, int n) {
//     int largest = vec[0];
//     for(auto it: vec){
//         if(largest < it)
//         largest = it;
//     }
//     int sLargest = INT_MIN;
//     for(auto it: vec){
//         if(it > sLargest && it < largest){
//             sLargest = it;
//         }
//     }
//     return sLargest;
// }


//<----------------OPTIMAL------------------>
// int secondLargest(vector<int>&vec, int n) {
//     int largest = vec[0];
//     int sLargest = INT_MIN;
//     for(auto it: vec){
//         if(it > largest) {sLargest = largest; largest = it;}
//         else if(it < largest) {if(it > sLargest) sLargest = it;}
//         else continue;
//     }
//     return sLargest;
// }