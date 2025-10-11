//Given a list of N integers, print sums of all subsets in it. Output should be printed in increasing order pf sums.




#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>&arr, int index, int sum, vector<int>&result) {
    if(index == arr.size()) {
        result.push_back(sum);
        return;
    }

    sum += arr[index];                                  //pick
    subsetSum(arr, index+1, sum, result);
    sum -= arr[index];                                  //not pick
    subsetSum(arr, index+1, sum, result);
}

int main() {
    vector<int>arr = {3,1,2};
    vector<int>result;
    subsetSum(arr, 0, 0, result);
    sort(result.begin(), result.end());
    for(auto it: result)
        cout<<it<<" ";
}