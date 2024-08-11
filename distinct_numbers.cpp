#include<bits/stdc++.h>
using namespace std;

int numberOfDistinctValues(int *arr, int n){
    if(n==1) return 1;

    sort(arr,arr+n);
    int cnt = 1;
    int element = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i]==element) continue;

        else{
            element = arr[i];
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << numberOfDistinctValues(arr, n);

    return 0;
}