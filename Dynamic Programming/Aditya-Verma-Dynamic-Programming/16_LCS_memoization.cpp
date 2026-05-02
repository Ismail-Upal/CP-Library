class Solution {
public:
    int dp[1001][1001];
    int rec(int i, int j, string &s, string &t){
        if(i == s.size() or j == t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]){
            ans = 1 + rec(i + 1, j + 1, s, t);
        }
        else{
            ans = max({ans, rec(i + 1, j, s, t), rec(i, j + 1, s, t)});
        }

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, text1, text2) ;
    }
};