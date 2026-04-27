// Question Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Subset Sum Problem

// Memoization
// T.C = O(sum*n)
// S.C = O(sum*n)

const int N = 10003;
class Solution {
  public:
  
    int dp[204][N];
    bool rec(int i, int s, vector<int>& arr, int sum){
        if(s == sum) return 1;
        if(i == arr.size()) return 0;
        
        if(dp[i][s] != -1) return dp[i][s];
        
        bool ans = 0;
        if(s + arr[i] <= sum) ans = rec(i + 1, s + arr[i], arr, sum);
        ans |= rec(i + 1, s, arr, sum);
        
        return dp[i][s] = ans;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, arr, sum);
    }
};

// Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        bool dp[n + 1][sum + 1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i <= n; i++) dp[i][sum] = 1;
        
        for(int i = n - 1; i >= 0; i--){
            for(int s = sum; s >= 0; s--){
                int ans = 0;
                
                if(s + arr[i] <= sum) ans |= dp[i + 1][s + arr[i]];
                ans |= dp[i + 1][s];
                
                dp[i][s] = ans;
            }
        }
        
        return dp[0][0];
    }
};