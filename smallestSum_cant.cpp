#include<bits/stdc++.h>
using namespace std;

long long int smallestSum(int n, int *arr){
    long long int sum = 0;
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        if(arr[i]<=sum+1){
            sum+=arr[i];
        }
        
        else return sum+1;
    }

    return sum+1;
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << smallestSum(n, arr);

    return 0;
}