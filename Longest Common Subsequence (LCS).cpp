int dp[1001][1001];
int topDownLCS(string& s, string& t, int i, int j) {
    if (i == 0 || j == 0)return 0;
    if (dp[i][j] != -1)return dp[i][j];

    if (s[i - 1] == t[j - 1])return dp[i][j] = dfs(s, t, i - 1, j - 1) + 1;
    else return dp[i][j] = max(dfs(s, t, i - 1, j), dfs(s, t, i, j - 1));
}

int LCS(string s, string t) {
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    int m = t.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];

}
