#include<bits/stdc++.h>
using namespace std;

long long int findMaxSum(int n, int *arr){
    long long int maxSum = INT_MIN;
    long long int sum = 0;

    for(int i=0; i<n; i++){
        sum+=arr[i];

        maxSum = max(maxSum, sum);

        if(sum < 0) sum = 0;
    }

    return maxSum;
}


int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << findMaxSum(n, arr);

    return 0;
}
