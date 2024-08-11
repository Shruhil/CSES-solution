#include<bits/stdc++.h>
using namespace std;
#define ll long long int

long long int minReadingTime(long long int n, long long int *readingTime){
    sort(readingTime, readingTime + n);
    
    long long int sumOfSmaller = accumulate(readingTime, readingTime + n, 0ll) - readingTime[n-1];
    
    if(sumOfSmaller < readingTime[n-1]){
        return 2*readingTime[n-1];
    }

    else{
        return readingTime[n-1] + sumOfSmaller;
    }
}

int main(){
    long long int n;
    cin >> n;
    
    long long int readingTime[n];

    for(long long int i=0; i<n; i++){
        cin >> readingTime[i];
    }

    cout << minReadingTime(n, readingTime);

    return 0;
}