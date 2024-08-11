#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long int mid, long long int t, long long int *timeTaken, long long int n){
    long long int productsMade = 0;

    for(int i=0; i<n; i++){
        productsMade+=(mid)/timeTaken[i];
    }

    return productsMade>=t;
}


long long int minimumTime(long long int n, long long int t, long long int *timeTaken){
    long long int low = 0;
    long long int high = t*(*min_element(timeTaken, timeTaken + n));

    long long int ans = 0;

    while(low<=high){
        long long int mid = (low+high) >> 1;

        if(isPossible(mid, t, timeTaken, n)){
            ans = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }

    return ans;
}

int main(){
    long long int n, t;
    cin >> n >> t;

    long long int timeTaken[n];

    for(long long int i=0; i<n; i++){
        cin >> timeTaken[i];
    }

    cout << minimumTime(n, t, timeTaken);

    return 0;
}