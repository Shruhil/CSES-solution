#include<bits/stdc++.h>
using namespace std;

void findThreePos(int n, int x, pair<int,int> *arr){
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        int low = i+1, high = n-1;

        while(low < high){
            int sum = arr[i].first + arr[low].first + arr[high].first;

            if(sum==x){
                cout << arr[i].second + 1 << " " << arr[low].second  + 1 << " " << arr[high].second + 1;
                return;
            }

            else if(sum < x){
                low++;
            }

            else{
                high--;
            }
        }
    }

    cout << "IMPOSSIBLE";
}


int main(){
    int n , x, element;
    cin >> n >> x;

    pair<int,int> arr[n];
    for(int i=0; i<n; i++){
        cin >> element;
        arr[i] = {element, i};
    }

    findThreePos(n, x, arr);
    return 0;
}