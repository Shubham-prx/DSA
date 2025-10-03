#include<iostream>
#include<vector>
using namespace std;

vector<int>spiral_traversal(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<int>ans;
    int left=0,right=m-1, top=0, bottom=n-1;

    while(left<=right && top<=bottom){
        //right
        for(int i=left; i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        //bottom
        for(int i=top; i<=bottom; i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        //left
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        //top
        if(left<=right){                                    //what if there's no top i.e., top is not less or equal to the bottom, but the matrix may still have some elements so to proceed you need to check is left <= right
            for(int i=bottom; i>=top; i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(n));
    for(auto &row : arr){
        for(auto &x : row){
            cin>>x;
        }
    }


vector<int>res = spiral_traversal(arr);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}