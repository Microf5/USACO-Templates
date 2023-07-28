#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1001][1001];
int dfs(string& s, string& t, int i, int j) {
    if (i == 0 || j == 0)return 0;
    if (dp[i][j] != -1)return dp[i][j];

    if (s[i - 1] == t[j - 1])return dp[i][j] = dfs(s, t, i - 1, j - 1) + 1;
    else return dp[i][j] = max(dfs(s, t, i - 1, j), dfs(s, t, i, j - 1));

}
void solve(string s, string t) {
    memset(dp, -1, sizeof(dp));
    cout << dfs(s, t, s.size(), t.size()) << endl;
}
int main()
{
    string s, t;
    while (getline(cin, s) && getline(cin, t)) {

        solve(s, t);
    }

}
