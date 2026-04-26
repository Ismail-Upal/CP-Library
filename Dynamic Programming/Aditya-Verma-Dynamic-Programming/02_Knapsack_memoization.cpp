#include <bits/stdc++.h>
using namespace std;

const int N = 1000; 
int dp[N][N]; 

int Knapsack(int wt[], int val[], int W, int n) {
	if(n == 0 || W == 0) return 0;
	
	if(dp[n][W] != -1) return dp[n][W];
	
	if(wt[n - 1] <= W){
		dp[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),Knapsack(wt, val, W, n - 1));
	} 
	else if (wt[n - 1] > W){
		dp[n][W] = Knapsack(wt, val, W, n - 1);
	}
	return dp[n][W];
}

int main() {
	int n; cin >> n;   
	int val[n], wt[n]; 
	for(int i = 0; i < n; i++) cin >> wt[i];
	for(int i = 0; i < n; i++) cin >> val[i];
	int W; cin >> W; 

	memset(dp, -1, sizeof dp);
	cout << Knapsack(wt, val, W, n) << endl;
	
	return 0;
}
