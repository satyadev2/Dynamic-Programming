class Solution
{
public:
    int dp[1002][1002];
    int solve(string text1, string text2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        if (text1[n - 1] == text2[m - 1])
        {
            return dp[m][n] = 1 + solve(text1, text2, n - 1, m - 1);
        }
        else
        {
            return dp[m][n] = max(solve(text1, text2, n - 1, m), solve(text1, text2, n, m - 1));
        }
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, n, m);
    }
};
