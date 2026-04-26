// Question Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// 0 - 1 Knapsack Problem

// Notes - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// T.C = O(N*W), where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight 
// element we traverse through all weight capacities 1<=w<=W.
// S.C = O(N*W) (2-D array of size ‘N*W’)


class Solution {
    public:
    int knapSack(int W, int wt[], int val[], int n) {
        int dp[n + 1][W + 1];
        memset(dp, 0, sizeof dp);

    	for(int i = 1; i<n+1; i++) {
    		for(int j = 1; j<W+1; j++) {
    			if(wt[i - 1] <= j){ 
    				dp[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
    			}
    			else if (wt[i - 1] > j) {  
    				t[i][j] = t[i - 1][j]; // move to next
    			}
		}
    	}
    	return t[n][W];
    }
};
