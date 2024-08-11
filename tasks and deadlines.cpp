#include<bits/stdc++.h>
using namespace std;

long long int maxReward(long long int n, vector<pair<long long int,long long int>> &tasks){
    sort(tasks.begin(), tasks.end());
    long long int reward = 0;
    long long int timer = 0;

    for(int i=0; i<n; i++){
        timer+=(tasks[i].first);
        reward+=(tasks[i].second - timer);
    }

    return reward;
}


int main(){
    long long int n;
    cin >> n;

    vector<pair<long long int,long long int>> tasks(n);

    for(int i=-0; i<n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }

    
    cout << maxReward(n, tasks);

    return 0;
}