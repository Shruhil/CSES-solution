#include<bits/stdc++.h>
using namespace std;

void findNearestSmaller(int n, pair<int,int> *arr, vector<int> &ans){
    stack<pair<int,int>> st;
    st.push({arr[0].first, arr[0].second});
    ans[0] = 0;

    for(int i=1; i<n; i++){
        int curr = arr[i].first;

        while(!st.empty() && curr <= st.top().first){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top().second + 1;
        }
        else{
            ans[i] = 0;
        }

        st.push({curr, i});
    }
}


int main(){
    int n, element;
    cin >> n;

    pair<int,int> arr[n];
    
    for(int i=0; i<n; i++){
        cin >> element;
        arr[i] = {element, i};
    }
    
    vector<int> ans(n);

    findNearestSmaller(n, arr, ans);

    for(auto pos:ans){
        cout << pos << " ";
    }

    return 0;
}