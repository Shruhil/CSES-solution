#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll subarrayCount(ll n, ll *arr){
    map<ll, ll> mp;
    ll sum = 0;
    ll cnt = 0;
    mp[0] = 1;
    
    for(int i=0; i<n; i++){
        sum=((sum+arr[i])%n + n)%n;
        cnt+=(mp[sum]);
        mp[sum]+=1;
    }

    return cnt;
}


int main(){
    ll n;
    cin >> n;

    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << subarrayCount(n, arr);
    
    return 0;
}