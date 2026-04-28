// Question Link :- https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Knapsack with Duplicate Items (Unbounded Knapsack)

// T.C = O(n*W)
// S.C = O(W)
class Solution {
  public:
    vector<vector<int>> dp;
    int rec(int i, int w, vector<int>& val, vector<int>& wt, int capacity){
        if(i == val.size()) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        
        int ans = 0;
        if(w + wt[i] <= capacity) ans = rec(i, w + wt[i], val, wt, capacity) + val[i];
        ans = max(ans, rec(i + 1, w, val, wt, capacity));
        
        return dp[i][w] = ans;
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        dp.assign(val.size() + 1, vector<int>(capacity + 1, -1));
        return rec(0, 0, val, wt, capacity);
    }
};