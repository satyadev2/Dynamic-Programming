#include <bits/stdc++.h>
using namespace std;

void solve(int satyaa[], int n, int sum)
{
    cout << sum << endl;
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
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
                dp[i][j] = (dp[i - 1][j - satyaa[i - 1]]) || (dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> mv;
    for (int i = 0; i <= (sum / 2); i++)
    {
        if (dp[n][i] == 1)
            mv.push_back(i);
    }
    for (auto i : mv)
    {
        cout << i << " ";
    }
    cout << endl;
    int mini = INT_MAX;
    for (int i = 0; i < mv.size(); i++)
    {
        mini = min(mini, (sum - (2 * mv[i])));
    }
    cout << mini;
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int satyaa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> satyaa[i];
        sum += satyaa[i];
    }

    solve(satyaa, n, sum);
    return 0;
}
