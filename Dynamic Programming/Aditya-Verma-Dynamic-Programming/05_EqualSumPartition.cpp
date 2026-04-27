// Question Link :- https://leetcode.com/problems/partition-equal-subset-sum/
// Partition Equal Subset Sum


// Tabulation
// T.C = O(sum*n)
// S.C = O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return 0;
        int dp[n + 4][sum + 5];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i <= n; i++){
            dp[i][sum / 2] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int left = sum; left >= 0; left--){
                int ans = 0;
                if(left + nums[i] <= sum / 2){
                    ans = dp[i + 1][left + nums[i]];
                }
                ans |= dp[i + 1][left];
                dp[i][left] = ans;
            }
        }
        return dp[0][0];
    }
};



// Memoization
// T.C = O(sum*n)
// S.C = O(sum*n)
class Solution {
public:
    int dp[205][20005];
    bool rec(int i, int left, int sum, vector<int> &nums){
        if(left == sum / 2) return 1;
        if(i == nums.size()) return 0;
        if(dp[i][left] != -1) return dp[i][left];

        int ans = 0;
        if(left + nums[i] <= sum / 2){
            ans = rec(i + 1, left + nums[i], sum, nums);
        }
        ans |= rec(i + 1, left, sum, nums);

        return dp[i][left] = ans;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return 0;
        memset(dp, -1, sizeof dp);
        return rec(0, 0, sum, nums);
    }
};