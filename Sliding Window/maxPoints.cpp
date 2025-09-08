#include<iostream>
#include<vector>
using namespace std;

int maxCards(vector<int>&nums, int k){
    int lsum=0,rsum=0,sum;
    for(int i=0;i<k;i++){
        lsum+=nums[i];
    }
    sum=lsum;
    int ridx=nums.size()-1;
    for(int i=k-1;i>=0;i--){
        lsum-=nums[i];
        rsum+=nums[ridx];
        ridx--;
        sum=max(sum, lsum+rsum);
    }
    return sum;
}

int main(){
    vector<int>nums;
    int x,n,k;
    cout<<"Number of cards: ";
    cin>>n;
    cout<<"Enter number of cards to pick (k): ";
    cin>>k;
    if(n<k){
        cout<<"Invalid case.";
        return -1;
    }
    cout<<"Enter cards value: ";
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    
    cout<<maxCards(nums,k);
}