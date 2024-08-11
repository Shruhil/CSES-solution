#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll countSubArrays(ll n, ll *arr, ll target){
    ll start = 0, end = -1;
    ll cnt = 0;
    ll sum = 0;

    while(end < n){
        while(end < n && sum < target){
            end+=1;
            sum+=arr[end];
        }

        if(sum==target){
            cnt+=1;
            sum-=arr[start];
            start+=1;
        }

        else if(sum > target){
            while(sum > target){
                sum-=arr[start];
                start+=1;
            }
        }
    }

    return cnt;
}


int main(){
    ll n, x;
    cin >> n >> x;

    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << countSubArrays(n, arr, x);

    return 0;
}