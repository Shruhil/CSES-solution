#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    bool flag = false;

    while(q.size() > 1){
        int topChild  = q.front();
        q.pop();

        flag = !flag;

        if(flag){
            cout << q.front() << " ";
            q.pop();

            q.push(topChild);
            flag = !flag;
        }

    }

    cout << q.front();
    return 0;

}