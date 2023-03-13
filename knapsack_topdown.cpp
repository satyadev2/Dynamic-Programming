#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> wt, vector<int> val, int n, int bag)
{
    int satyaa[n + 1][bag + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bag; j++)
        {
            if (i == 0 || j == 0)
            {
                satyaa[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                satyaa[i][j] = max(val[i - 1] + satyaa[i - 1][j - wt[i - 1]], satyaa[i - 1][j]);
            }
            else
            {
                satyaa[i][j] = satyaa[i - 1][j];
            }
        }
    }
    return satyaa[n][bag];
}

int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int bag;
    cin >> bag;
    int k = solve(wt, val, n, bag);
    for (auto i : wt)
    {
        cout << i << " ";
    }
    for (auto i : val)
    {
        cout << i << " ";
    }
    cout << k << endl;
    return 0;
}
