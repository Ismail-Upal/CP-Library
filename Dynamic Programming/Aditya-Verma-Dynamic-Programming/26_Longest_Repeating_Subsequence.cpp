// Question Link :- https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Longest Repeating Subsequence

// Notes:- https://www.geeksforgeeks.org/longest-repeating-subsequence/

// T.C = O(n^2)
// S.C = O(n^2)

// Approach - 1 (LCS Memoization)
class Solution {
  public:
    int dp[1003][1003];
    int rec(int i, int j, string &s1, string &s2){
        if(i == s1.size() or j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s1[i] == s2[j] and i != j){
            ans = rec(i + 1, j + 1, s1, s2) + 1;
        }
        else ans = max(rec(i + 1, j, s1, s2), rec(i, j + 1, s1, s2));
        
        return dp[i][j] = ans;
    }
    
    int LongestRepeatingSubsequence(string &s) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, s, s);
    }
};
