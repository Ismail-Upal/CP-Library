const int N = 1005;
class Solution {
  public:
    int dp[N][N];
    int rec(int i, int w, int n, int W, vector<int> &val, vector<int> &wt){
        if(i == n) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        
        int ans = 0;
        if(w + wt[i] <= W){
            ans = rec(i + 1, w + wt[i], n, W, val, wt) + val[i];
        }
        ans = max(ans, rec(i + 1, w, n, W, val, wt));
        
        return dp[i][w] = ans;
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        memset(dp, -1, sizeof dp);
        return rec(0, 0, n, W, val, wt);
    }
};