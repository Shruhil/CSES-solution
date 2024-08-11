#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// void solveRec(int n, int a, int b, int i, int j, int sum, int &maxSum, int *arr){
//     if(i > j) return;

//     if(j-i+1>=a && j-i+1<=b) maxSum  = max(maxSum, sum);

//     solveRec(n, a, b, i+1, j, sum-arr[i], maxSum, arr);
//     solveRec(n, a, b, i, j-1, sum-arr[j], maxSum, arr);
// }

// void solveMem(int n, int a, int b, int i, int j, int sum, int &maxSum, int *arr, vector<vector<vector<int>>> &dp){
//     if(i > j) return;

//     if(j-i+1>=a && j-i+1<=b) maxSum  = max(maxSum, sum);

//     if(dp[i][j][sum]!=-1) return;

//     solveMem(n, a, b, i+1, j, sum-arr[i], maxSum, arr, dp);
//     solveMem(n, a, b, i, j-1, sum-arr[j], maxSum, arr, dp);

//     dp[i][j][sum] = maxSum;
// }

// void solveTab(int n, int a, int b, ll &maxSum, int *arr){
//     unordered_map<int,int> preSum;
//     vector<ll> dp(n, INT_MIN);

//     for(int i=0; i<n; i++){
//         preSum[i+1] = preSum[i] + arr[i];
//     }


//     for(int i=0; i<n; i++){
//         for(int len=a; len<=b; len++){
//             if(i-len+1>=0){
//                 int currSum = preSum[i+1] - preSum[i-len+1];
//                 dp[i] = max(dp[i], currSum);
//             }
//         }

//         maxSum = max(maxSum, dp[i]);
//     }
// }


// ll maxSubArrSum(int n, int a, int b, int *arr){
//     // int sum = accumulate(arr, arr+n, 0);
//     ll maxSum = INT_MIN;

//     // solveRec(n, a, b, 0, n-1, sum, maxSum, arr);
    
//     // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(sum+1, -1)));
//     solveTab(n, a, b, maxSum, arr);
//     return maxSum;
// }


int N, A, B;
const ll LINF = 1e18;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;  // reading in variables

	vector<long long> pfx(N + 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		pfx[i] = a + pfx[i - 1];  // construction of our prefix sum
	}

	ll ret = -LINF;
	multiset<ll> ms;

	// we can keep a sliding window of size B - A + 1,
	// then find the lowest pfx[j] using multiset
	for (int i = A; i <= N; ++i) {
		if (i > B)
			ms.erase(ms.find(pfx[i - B - 1]));  // erase the element if size > B
		ms.insert(pfx[i - A]);
		ret = max(
		    ret,
		    pfx[i] - *ms.begin());  // we want to minimize ms.begin() aka pfx[j]
	}

	cout << ret << "\n";
}