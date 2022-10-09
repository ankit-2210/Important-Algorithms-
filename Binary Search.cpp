
#include <bits/stdc++.h>

using namespace std;
int BinarySearch(int x,vector<int>&arr){
    int l=0,h=arr.size(),m;
    while(l<=h){
        m=(h-l)/2;
        if(arr[m]==x) return m;
        if(arr[m]<x) {
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return -1;
}

int main()
{
    // taking input as sorted array
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    // taking no whose index we have to find
    int x;
    cin>>x;
    int t=BinarySearch(x,arr);
    if(t== -1){
        cout<<"the number doesn't exist in the array\n";
    }
    else{
        cout<<"index of "<<x<<" in the following array is :"<<t<<endl;
    }
    
    return 0;
}
