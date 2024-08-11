#include<bits/stdc++.h>
using namespace std;

void Josh(int n, int k){
    vector<vector<int>> arr;
    int root = sqrt(n);

    vector<int> temp;
    int row = 0, col = 0, cnt = 0;

    for(int i=1; i<=n; i++){
        if(cnt > root){
            arr.push_back(temp);
            cnt = 0;
            temp.clear();
        }

        cnt++;
        temp.push_back(i);
    }

    
    if(!temp.empty()) arr.push_back(temp);

    for(int i=0; i<n; i++){
        int j = k%(n-i);

        while(j){
            if(col+j < arr[row].size()){
                col+=j;
                j=0;
            }

            else{
                j-=(arr[row].size() - col);
                col = 0;
                row++;
            }

            if(row>=arr.size()){
                row = 0;
            }
        }

        while(arr[row].size()<=col){
            col = 0;
            row++;

            if(row>=arr.size()) row = 0;
        }

        cout << arr[row][col] << " ";

        if(i!=n-1){
            arr[row].erase(arr[row].begin() + col);

            while(arr[row].size()<=col){
                col = 0;
                row++;

                if(row>=arr.size()){
                    row = 0;
                }
            }
        }
    }
}


int main(){
    int n, k;
    cin >> n >> k;

    Josh(n, k);

    return 0;
}