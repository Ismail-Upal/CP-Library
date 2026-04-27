// Question Link :- https://leetcode.com/problems/target-sum/
// Target Sum

// T.C = O(n*sum(arr))
// S.C = O(sum(arr))
class Solution {
public:
    vector<vector<int>> dp;
    int offset;

    int rec(int i, int sum, vector<int> &nums, int target){
        if(i == nums.size()) return sum == target;

        if(dp[i][sum + offset] != -1) 
            return dp[i][sum + offset];

        int add = rec(i + 1, sum + nums[i], nums, target);
        int sub = rec(i + 1, sum - nums[i], nums, target);

        return dp[i][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        offset = total; // shift range [-total, total] → [0, 2*total]

        dp.assign(nums.size(), vector<int>(2 * total + 1, -1));

        return rec(0, 0, nums, target);
    }
};