#include<bits/stdc++.h>
using namespace std;


int num_applicants(int n, int m, int k, int *apartments, int *avl_apartments){
    int i = 0, j = 0;
    int ans = 0;

    sort(apartments, apartments+n);
    sort(avl_apartments, avl_apartments+m);

    while(i<n && j<m){
        if(abs(apartments[i] - avl_apartments[j]) <= k){
            i++;
            j++;
            ans++;
        }
        else{
            if(apartments[i] - avl_apartments[j] > k){
                j++;
            }

            else{
                i++;
            }
        }
    }

    return ans;
}

int main(){
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    int apartments[n];
    int avl_apartments[m];

    for(int i=0; i<n; i++) cin >> apartments[i];
    for(int i=0; i<m; i++) cin >> avl_apartments[i];

    cout << num_applicants(n, m, k, apartments, avl_apartments);
    
    return 0;
}