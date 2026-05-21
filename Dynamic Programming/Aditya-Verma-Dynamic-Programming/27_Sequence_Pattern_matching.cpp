// Question Link :- https://leetcode.com/problems/is-subsequence/
// Is Subsequence (follow up - Leetcode 792)

// Approach - 1 (proper solution for this ques)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(j < t.size()){
            if(i < s.size() and s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};



// Approach - 2 (Aditya Verma) [not necessary]
class Solution {
public:
    int dp[1001][10001];
    int rec(int i, int j, string& s, string& t) {
        if (i == s.size() or j == t.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (s[i] == t[j]) {
            ans = 1 + rec(i + 1, j + 1, s, t);
        } else {
            ans = max({ans, rec(i + 1, j, s, t), rec(i, j + 1, s, t)});
        }

        return dp[i][j] = ans;
    }
    bool isSubsequence(string s, string t) {
        memset(dp, -1, sizeof dp);
        int len = rec(0, 0, s, t);
        return len >= s.size();
    }
};



// X Y Z -> String 1
// A X B Y C Z E T -> String 2

// True
