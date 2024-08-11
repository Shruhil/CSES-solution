#include<bits/stdc++.h>
using namespace std;

int min_gondola(int n, int max_wt, int *child_wt){
    sort(child_wt, child_wt+n);
    int gondola = 0;
    int i = 0, j = n-1;

    vector<bool> have_gondola(n, false);

    while(i < j){
        if(child_wt[i] + child_wt[j] > max_wt){
            --j;
        }


        else{
            gondola++;
            have_gondola[i] = true;
            have_gondola[j] = true;

            ++i, --j;
        }
    }

    for(int i=0; i<n; ++i){
        gondola+= (have_gondola[i]==false ? 1 : 0);
    }

    return gondola;
}



int main(){
    int n, max_wt;

    cin >> n;
    cin >> max_wt;

    int child_wt[n];

    for(int i=0; i<n; i++){
        cin >> child_wt[i];
    }

    cout << min_gondola(n, max_wt, child_wt);

    return 0;
}