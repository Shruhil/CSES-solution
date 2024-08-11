#include<bits/stdc++.h>
using namespace std;

int maxNumberCustomers(int n, int *a, int *b){
    int maxNum = 0;
    int cnt = 0;

    sort(a, a+n);
    sort(b, b+n);

    int i=0, j=0;
    while(i<n && j<n){
        if(a[i] < b[j]){
            cnt++;
            i++;
            maxNum = max(maxNum, cnt);
        }

        else{
            cnt--;
            j++;
        }
    }

    return maxNum;
}

int main(){
    int n, a, b;
    cin >> n;

    int arrival_time[n];
    int leaving_time[n];

    for(int i=0; i<n; i++){
        cin >> a >> b;
        arrival_time[i] = a;
        leaving_time[i] = b;
    }

    cout << maxNumberCustomers(n, arrival_time, leaving_time);

    return 0;
}