#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll countSubArrays(ll n, ll *arr, ll target){
    ll cnt = 0;
    
    map<ll,ll> preSum;
    ll sum = 0;
    preSum[0] = 1;

    for(ll i = 0; i<n; i++){
        sum+=arr[i];
        cnt+=(preSum[sum - target]);
        preSum[sum]+=1;
    }

    return cnt;
}


int main(){
    ll n , x;
    cin >> n >> x;

    ll arr[n];

    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << countSubArrays(n, arr, x);
    return 0;
}