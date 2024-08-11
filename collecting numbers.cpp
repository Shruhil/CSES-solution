#include <bits/stdc++.h>
using namespace std;

int minRounds  (int n, int *arr){
    vector<int> indices(n+1, -1);
    int rounds = 1;

    for(int i=0; i<n; i++){
        indices[arr[i]] = i;
    }

    for(int i=1; i<n; i++){
        if(indices[i+1] < indices[i]){
            rounds++;
        }

        else continue;
    }


    return rounds;
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << minRounds(n, arr);

    return 0;
}