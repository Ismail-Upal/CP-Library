// Question Link :- https://leetcode.com/problems/longest-common-subsequence
// Longest Common Subsequence


// RECURSION (give TLE)
int longestCommonSubsequence(string a, string b, int n, int m) {

	// using recursion only
	if (n == 0 || m == 0) {
		return 0;
	}
	if (a[n - 1] == b[m - 1]) {
		return 1 + longestCommonSubsequence(a, b, n - 1, m - 1);
	}
	return max(longestCommonSubsequence(a, b, n - 1, m), longestCommonSubsequence(a, b, n, m - 1));

}




// MEMOIZATION (giving TLE to 1 last testcase)
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



// TABULATION :
// T.C = O(n*m)
// S.C = O(n*m)
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