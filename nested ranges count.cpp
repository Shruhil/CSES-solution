#include<bits/stdc++.h>
using namespace std;


struct ranges{
    int l, r, ind;

    bool operator<(const ranges &other) const{
        if(l == other.l){
            return r > other.r;
        }

        return l < other.l;
    }
};


vector<vector<int>> findBoth(int n, vector<pair<int,int>> &arr){
    vector<ranges> range;
    vector<int> numContains(n);
    vector<int> numContained(n);
    unordered_map<int, int> mp;


    for(int i=0; i<n; i++){
        range[i].l = arr[i].first;
        range[i].r = arr[i].second;
        range[i].ind = i;
    }


    int minEnd = INT_MAX;
    for(int i=n-1; i>=0; i--){
        if(range[i].r>=minEnd){
            
        }

        minEnd = min(minEnd, range[i].r);
    }    
}



int main(){
    int n, a, b;
    cin >> n;

    vector<pair<int,int>> arr(n);

    for(int i=0; i<n; i++){
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }

    sort(arr.begin(), arr.end(), cmp());

    vector<vector<int>> ans = findBoth(n, arr);

    for()

    return 0;
}