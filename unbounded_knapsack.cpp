#include <bits/stdc++.h>
using namespace std;

int solve(int wt[], int val[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= wt[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n;
    cin >> n;
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int capacity;
    cin >> capacity;
    cout << solve(wt, val, n, capacity);
}