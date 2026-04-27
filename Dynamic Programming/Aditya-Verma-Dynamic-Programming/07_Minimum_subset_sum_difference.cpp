// Question Link :- https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Minimum sum partition

// Note :- 0 < arr[i] <= 10^5


// Tabulation
// T.C = O(n*sum)
// S.C = O(n*sum)
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int dp[n + 5][sum + 5];
        memset(dp, -1, sizeof dp);
        
        for(int l = 0; l <= sum; l++){
            int r = sum - l;
            dp[n][l] = abs(l - r); 
        }
        
        for(int i = n - 1; i >=0; i--){
            for(int left = sum; left >= 0; left--){
                dp[i][left] = min(dp[i + 1][left], dp[i + 1][left + arr[i]]);
            }
        }
        return dp[0][0];
    }
};




// Memoization
// T.C = O(n*sum)
// S.C = O(n*sum)
const int N = 1e5 + 5;
class Solution {
  public:
    vector<vector<int>> dp;
    int rec(int i, int left, int sum, vector<int> &arr){
        if(i == arr.size()){
            int right = sum - left;
            return abs(left - right);
        }  
        if(dp[i][left] != -1) return dp[i][left];
        
        int ans = min(rec(i + 1, left, sum, arr), rec(i + 1, left + arr[i], sum, arr));
        return dp[i][left] = ans;
    }
    
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        dp.assign(n, vector<int>(sum + 1, -1));
        return rec(0, 0, sum, arr);
    }
};
