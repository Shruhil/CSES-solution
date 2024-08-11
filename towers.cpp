#include<bits/stdc++.h>
using namespace std;


long long int numberofTowers(int n){
    long long int ht;
    vector<long long int> util;

    for(int i=0; i<n; i++){
        cin >> ht;

        long long int low  = 0, high = util.size();
        while(low < high){
            long long int mid = (low+high) >> 1;
            if(util[mid] > ht){
                high = mid;
            }

            else low = mid+1; 
        }

        if(low==util.size()) util.push_back(ht);
        else util[low] = ht;
    }  

    return util.size();
}


int main(){
    int n;
    cin >> n;

    cout << numberofTowers(n);

    return 0;
}