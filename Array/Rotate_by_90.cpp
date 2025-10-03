#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>rotate90(vector<vector<int>>&arr){
    int n = arr.size();
    //transpose
    for(int i=0; i<n-1; i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    //reverse
    for(int i=0; i<n; i++){
            reverse(arr[i].begin(), arr[i].end());
    }
    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>vec(n, vector<int>(n));
    for(auto &row : vec){
        for(auto &x : row){
            cin>>x;
        }
    }
    rotate90(vec);
    for(auto &row : vec){
        for(auto &x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}