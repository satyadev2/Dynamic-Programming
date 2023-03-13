#include <bits/stdc++.h>
using namespace std;

int solve(int satyaa[], int target, int n)
{
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= satyaa[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - satyaa[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][target];
}
int main()
{
    int n;
    cin >> n;
    int satyaa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> satyaa[i];
    }
    int diff;
    cin >> diff;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += satyaa[i];
    }
    int target = (sum + diff) / 2;
    cout << solve(satyaa, target, n);
}