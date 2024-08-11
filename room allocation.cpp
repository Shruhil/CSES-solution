#include<bits/stdc++.h>
using namespace std;


void findRoomsAndOrder(int n, vector<pair<int,pair<int,int>>> &customer){
    int roomCnt = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> room_alloted(n);

    for(int i=0; i<n; i++){
        int a_time = customer[i].first;
        int d_time = customer[i].second.first;
        int ind = customer[i].second.second;


        if(pq.empty() || pq.top().first >= a_time){
            roomCnt+=1;
            pq.push({d_time, roomCnt});
            room_alloted[ind] = roomCnt;
        }


        else{
            int vacantRoom = pq.top().second;
            pq.pop();
            pq.push({d_time, vacantRoom});
            room_alloted[ind] = vacantRoom;
        }
    }

    cout << roomCnt << endl;
    for(auto room:room_alloted){
        cout << room <<" ";
    }
}


int main(){
    int n, a_time, d_time;
    cin >> n;

    vector<pair<int,pair<int,int>>> customer(n);

    for(int i=0; i<n; i++){
        cin >> a_time >> d_time;
        customer[i].first = a_time;
        customer[i].second.first = d_time;
        customer[i].second.second = i;
    }

    sort(customer.begin(), customer.end());

    findRoomsAndOrder(n, customer);
    return 0;
}