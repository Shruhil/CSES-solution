#include <bits/stdc++.h>
using namespace std;


vector<int> numRounds(int n, int *arr, int m){
    int pos1, pos2;
    vector<int> ans;

    for(int i=0; i<m; i++){
        cin >> pos1 >> pos2;
        int rounds = 1;

        vector<int> indices(n+1, -1);
        swap(arr[pos1-1], arr[pos2-1]);

        for(int i=0; i<n; i++){
            indices[arr[i]] = i;
        }

        for(int i=1; i<n; i++){
            if(indices[i+1] < indices[i]){
                rounds++;
            }
        }

        ans.push_back(rounds);
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> rounds = numRounds(n, arr, m);

    for(auto it:rounds){
        cout << it << endl;
    }

    return 0;
}