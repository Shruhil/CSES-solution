#include<bits/stdc++.h>
using namespace std;

class ranges{
    public:
    int l, r, ind;

    bool operator(const ranges &other) const{
        if(l==other.l){
            return r > other.r;
        }
        
        return l < other.l;
    }
};


void findSolution(int n, vector<vector<int>> &arr){
    vector<ranges> range;
    vector<int> contains(n, 0), contained(n, 0);

    for(int i=0; i<n; i++){
        range[i].l = arr[i][0];
        range[i].r = arr[i][1];
        range[i].ind = i;
    }

    int minEnd = INT_MAX;
    for(int i=n-1; i>=0; i--){
        if(range[i].r>=minEnd){
            contains[range[i].ind] = 1;
        }

        minEnd = min(minEnd, range[i].r);
    }

    int maxEnd = INT_MIN;
    for(int i=0; i<n; i++){
        if(range[i].r>=maxEnd){
            contained[range[i].ind] = 1;
        }

        maxEnd = max(maxEnd, range[i].r);
    }

    for(auto it : contains){
        cout << it << " ";
    }cout << endl;

    
    for(auto it: contained){
        cout << it << " "; 
    }
}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    for(int i=0; i<n; i++){
        cin >> a >> b;
        arr[i] = {a, b};
    }

    findSolution(n, arr);

    return 0;
}