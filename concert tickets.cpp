#include<bits/stdc++.h>
using namespace std;


vector<int> pricePaidByCustomer(int n, int m, multiset<int> &ticketPrices, int *maxPrice){
    vector<int> pricePaid(m, -1);

    for(int i=0; i<m; i++){
        int readyToPay = maxPrice[i];
        auto it = ticketPrices.upper_bound(readyToPay);

        if(it==ticketPrices.begin()) continue;
        
        else{
            pricePaid[i] = *(--it);
            ticketPrices.erase(it);
        }
    }

    return pricePaid;
}

int main(){
    int n, m, h;
    
    cin >> n >> m;

    multiset<int> ticketPrices;
    int maxPrice[m];

    for(int i=0; i<n; i++){
        cin >> h;
        ticketPrices.insert(h);
    }

    for(int i=0; i<m; i++){
        cin >> maxPrice[i];
    }

    vector<int> paid = pricePaidByCustomer(n, m, ticketPrices, maxPrice);

    for(auto price : paid){
        cout << price << endl;
    }

    return 0;
}