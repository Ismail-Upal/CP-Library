// Question Link :- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Perfect Sum Problem


// Brute Force
// generating all the possible subsets and then checking whether the subset has the required sum.


// Tabulation (Bottom-Up)
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int dp[n + 5][1005];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i <= n; i++) dp[i][target] = 1;
        
        for(int i = n - 1; i >= 0; i--){
            for(int s = target; s >= 0; s--){
                int ans = 0;
                if(s + arr[i] <= target){
                    ans = dp[i + 1][s + arr[i]];
                }
                ans += dp[i + 1][s];
                dp[i][s] = ans;
            }
        }
        
        return dp[0][0];
    }
};




// Memoization
// T.C = O(sum*n)
// S.C = O(sum*n)
const int N = 1e3 + 4;
class Solution {
  public:
  
    int dp[N][N];
    int rec(int i, int sum, vector<int> &arr, int target){
        if(i == arr.size()) return sum == target;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = 0;
        if(sum + arr[i] <= target){
            ans = rec(i + 1, sum + arr[i], arr, target);
        }
        ans += rec(i + 1, sum, arr, target);
        
        return dp[i][sum] = ans;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, arr, target);
    }
};