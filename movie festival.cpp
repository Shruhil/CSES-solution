#include<bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
};


int maxMoviesFinished(int n, vector<pair<int,int>> &movieTime){
    sort(movieTime.begin(), movieTime.end(), cmp());
    int num = 1;
    int lastEnd = movieTime[0].second;

    for(int i=1; i<n; i++){
        if(movieTime[i].first >= lastEnd){
            num++;
            lastEnd = movieTime[i].second;
        }
    }

    return num;
}

int main(){
    int n, startTime, endTime;
    cin >> n;

    vector<pair<int,int>> movieTime(n);

    for(int i=0; i<n; i++){
        cin >> startTime;
        cin >> endTime;

        movieTime[i] = {startTime, endTime};
    }

    cout << maxMoviesFinished(n, movieTime);

    return 0;
}