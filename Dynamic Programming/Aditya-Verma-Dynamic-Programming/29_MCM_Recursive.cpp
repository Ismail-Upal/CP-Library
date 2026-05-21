class Solution {
  public:
  
    int dp[103][103];
    int rec(int i, int j, vector<int> &arr){
        if(i + 1 >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++){
            int sum = rec(i, k, arr) + rec(k, j, arr) + (arr[i] * arr[k] * arr[j]);
            ans = min(ans, sum);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        return rec(0, n - 1, arr);
    }
};