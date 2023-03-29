class Solution
{
public:
    int dp[502][502];
    int solve(string x, string y, int m, int n)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int minInsertions(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int m = s.size();
        int n = t.size();
        int k = solve(s, t, m, n);
        return m - k;
    }
};