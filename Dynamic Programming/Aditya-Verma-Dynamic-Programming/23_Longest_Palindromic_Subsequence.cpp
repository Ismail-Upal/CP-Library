// Question Link :- https://leetcode.com/problems/longest-palindromic-subsequence/
// Longest Palindromic Subsequence

// Brute Force
// find all subsequences and then check whether they are palindrome then output the longest
// palindrome subsequence.


// Better Solution
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int dp[1000][1000];
    int rec(int i, int j, string &s){
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == s[j]){
            ans = rec(i + 1, j - 1, s) + 2;
        }
        else{
            ans = max(rec(i + 1, j, s), rec(i, j - 1, s));
        }

        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, s.size() - 1, s);

        return ans;
    }
};