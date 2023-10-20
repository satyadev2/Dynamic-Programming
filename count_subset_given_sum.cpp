#include <bits/stdc++.h>
using namespace std;

int solve(int array[], int n, int target)
{
    sort(array, array + n);
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
            else if (j >= array[i - 1])
            {
                dp[i][j] = (dp[i - 1][j]) + (dp[i - 1][j - array[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][target]; // gives
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
    int target;
    cin >> target;
    cout << solve(satyaa, n, target);
}
