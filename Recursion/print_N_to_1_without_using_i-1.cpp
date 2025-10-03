#include <iostream>
using namespace std;

void function(int i, int n){
    if(i>n)
        return;
    function(i+1, n);
    cout<<i<<" ";
}

int  main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    function(1, n);
}