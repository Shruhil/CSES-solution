#include<bits/stdc++.h>
using namespace std;

long long longestSeq(long long n, long long *arr){
    map<long long, long long> mp;
    long long start = 0;
    long long len = 0;

    
    for(long long end = 0; end < n; end++){
        if(mp.find(arr[end]) == mp.end()){
            mp[arr[end]] = end;
        }

        else{
            if(mp[arr[end]] >= start){
                start = mp[arr[end]] + 1;
            }

            mp[arr[end]] = end;
        }

        len = max(len, end-start+1);
    }

    return len;
}

int main(){
    long long n;
    cin >> n;

    long long arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << longestSeq(n, arr);
    return 0;
}