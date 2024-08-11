#include<bits/stdc++.h>
using namespace std;


int subArrayCount(int n, int k, int *arr){
    if(k==1) return n;

    
}


int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << subArrayCount(n, k, arr);
    return 0;
}