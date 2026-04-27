// Question Link :- https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Partitions with Given Difference


// Tabulation
// T.C = O(n*sum(arr))
// S.C = O(sum(arr))
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof dp);
        for(int s = 0; s <= sum; s++){
            if(2 * s == sum + diff) dp[n][s] = 1;
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int left = sum - 1; left >= 0; left--){
                dp[i][left] = dp[i + 1][left] + dp[i + 1][left + arr[i]];
            }
        }
        return dp[0][0];
    }
};




// Memoization
// T.C = O(n*sum(arr))
// S.C = O(n*sum(arr))
class Solution {
  public:
    vector<vector<int>> dp;
    int rec(int i, int left, int sum, vector<int> &arr, int diff){
        if(i == arr.size()){
            if(2 * (left) == sum + diff) return 1;
            else return 0;
        }
        if(dp[i][left] != -1) return dp[i][left];
        
        int ans = 0;
        ans += rec(i + 1, left + arr[i], sum, arr, diff);
        ans += rec(i + 1, left, sum, arr, diff);
        
        return dp[i][left] = ans;
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if((sum + diff) % 2) return 0;
        
        dp.assign(n + 1, vector<int>(sum + 1, -1));
        return rec(0, 0, sum, arr, diff);
    }
};