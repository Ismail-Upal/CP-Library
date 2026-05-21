// min deletion to make string palindrome = min insertion to make string palindrome
// Same as question 24

// Question Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
// Minimum number of deletions to make string Palindrome

// Question Link :- https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Minimum Insertion Steps to Make a String Palindrome


// Brute Force
// T.C = O(2^n)
// S.C = O(n)


// Better Solution (Tabulation)
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int dp[505][505];
    int rec(int i, int j, string &s){
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans;
        if(s[i] == s[j]) ans = rec(i + 1, j - 1, s) + 2;
        else ans = max(rec(i + 1, j, s), rec(i, j - 1, s));

        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof dp);
        return s.size() - rec(0, s.size() - 1, s);
    }
};