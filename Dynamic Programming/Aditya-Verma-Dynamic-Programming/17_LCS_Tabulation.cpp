class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1003][1003];
        int n = text1.size(), m = text2.size();
        memset(dp, 0, sizeof dp);

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i + 1][j + 1];
                }
                else ans = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};