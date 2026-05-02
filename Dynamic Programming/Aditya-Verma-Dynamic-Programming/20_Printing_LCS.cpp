// Notes:- https://www.geeksforgeeks.org/printing-longest-common-subsequence/

// tricky
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof dp);

	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			int ans = 0;
			if(s[i] == t[j]){
				ans = dp[i + 1][j + 1] + 1;
			}
			else ans = max(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = ans;
		}
	}

	string lcs = "";
	int len = dp[0][0];
	int i = 0, j = 0;
	while(i < n and j < m){
		if(s[i] == t[j]){
			lcs += s[i];
			i++, j++;
		}
		else if(dp[i + 1][j] > dp[i][j + 1]){
			i++;
		}
		else j++;
	}

	cout << lcs;
	
	return 0;
}
