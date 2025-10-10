#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>&arr, int index, int target, vector<int>&temp, vector<vector<int>>&result) {
    if(index == arr.size()){
        if(target == 0){
            result.push_back(temp);
        }
        return;
    }

    if(arr[index] !=0 && arr[index] <= target){
        target -= arr[index];
        temp.push_back(arr[index]);
        combinationSum(arr, index, target, temp, result);

        target += arr[index];
        temp.pop_back();
    }
    combinationSum(arr, index + 1, target, temp, result);


}

int main(){
    vector<int>arr = {3, 2, 1, 4, 0, 5};
    int target = 6;
    vector<int>temp;
    vector<vector<int>>result;
    combinationSum(arr, 0, target, temp, result);
    for(auto &row : result){
        cout<<"{";
        for(auto &x : row){
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }

}