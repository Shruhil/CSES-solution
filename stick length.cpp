#include<bits/stdc++.h>
using namespace std;

long long int minimumCost(int n, int *arr){
    sort(arr, arr+n);
    long long int optLen = arr[n/2];
    long long int cost = 0;

    for(int i=0; i<n; i++){
        cost+=abs(arr[i] - optLen);
    }

    return cost;
}

int main(){
    int n;
    cin >> n;
    
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << minimumCost(n, arr);

    return 0;
}
