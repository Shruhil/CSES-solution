#include<bits/stdc++.h>
using namespace std;

vector<int> findIndices(int n, pair<int,int> *arr, int target){
    vector<int> ans;
    sort(arr, arr + n);

    int i=0, j=n-1;

    while(i<j){
        int sum = arr[i].first + arr[j].first;

        if(sum==target){
            ans.push_back(arr[i].second);
            ans.push_back(arr[j].second);
            break;
        } 

        else if(sum < target){
            i++;
        }

        else{
            j--;
        }
    }

    return ans;
}

int main(){
    int n, x;
    cin >> n >> x;
    
    pair<int,int> arr[n];
    int element;

    for(int i=0; i<n; i++){
        cin >> element;
        arr[i] = {element, i};
    }
    
    vector<int> indices = findIndices(n, arr, x);
    
    if(indices.empty()){
        cout << "IMPOSSIBLE";
    }

    else{
        cout << indices[0] + 1 << " " << indices[1] + 1;
    }

    return 0;
    
}