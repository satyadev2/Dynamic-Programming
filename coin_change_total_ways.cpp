#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> wt, int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= wt[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - wt[i - 1]];
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
    vector<int> satyaa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> satyaa[i];
    }
    int amount;
    cin >> amount;
    cout << solve(satyaa, n, amount);
}
