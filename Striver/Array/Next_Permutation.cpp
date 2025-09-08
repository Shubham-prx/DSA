#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

vector<int>next_permutation(vector<int>&arr){
	int idx=-1,n=arr.size();
	for(int i=n-2; i>=0; i--) {
		if(arr[i]<arr[i+1]) {
			idx=i;
			break;
		}
	}
	if(idx==-1) {
		reverse(arr.begin(),arr.end());
		return arr;
	}
	for(int i=n-1; i>=idx; i--) {
		if(arr[idx]<arr[i]) {
			swap(arr[idx],arr[i]);
			break;
		}
	}
	reverse(arr.begin() + idx + 1, arr.end());
	return arr;
}

int main() {
	vector<int>arr;
	string line;
	int input;

	getline(cin, line);

	stringstream ss(line);

	while(ss >> input){
		arr.push_back(input);
	}

	next_permutation(arr);

	for(auto it:arr) {
		cout<<it<<" ";
	}
}
