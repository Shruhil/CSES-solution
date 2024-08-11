#include<bits/stdc++.h>
using namespace std;


int main(){
    int x, n;
    cin >> x >> n;

    vector<int> lights(n);
    for(auto &l:lights) cin >> l;

    set<int> street_pos{0, x};
    for(auto l:lights){
        street_pos.insert(l);
    }

    vector<int> gaps(n);
    int prev = 0, max_gap = 0;

    for(int p:street_pos){
        max_gap = max(max_gap, p - prev);
        prev = p;
    }

    gaps.back() = max_gap;

    for(int i=n-1; i>0; i--){
        street_pos.erase(lights[i]);
        auto high_it = street_pos.upper_bound(lights[i]);

        int high = *high_it;
        int low = *(--high_it);

        max_gap = max(max_gap, high - low);
        gaps[i-1] = max_gap;
    }

    for(auto gap:gaps) cout << gap << " ";

    return 0;

}