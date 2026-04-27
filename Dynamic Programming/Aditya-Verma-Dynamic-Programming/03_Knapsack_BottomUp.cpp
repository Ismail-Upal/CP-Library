// Question Link :- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// 0 - 1 Knapsack Problem

// Notes - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// T.C = O(N*W), where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight 
// element we traverse through all weight capacities 1<=w<=W.
// S.C = O(N*W) (2-D array of size ‘N*W’)


class Solution {
  public:
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int dp[n + 1][W + 1];
        memset(dp, 0, sizeof dp);
        
        for(int i = n - 1; i >= 0; i--){
            for(int w = W; w >= 0; w--){
                
                int ans = 0;
                if(w + wt[i] <= W){
                    ans = dp[i + 1][w + wt[i]] + val[i];
                }
                ans = max(ans, dp[i + 1][w]);
                dp[i][w] = ans;
            }
        }
        return dp[0][0];
    }
};