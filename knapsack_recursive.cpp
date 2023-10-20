#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> wt, vector<int> val, int n, int bag)
{
    if (n == 0 || bag == 0)
    {
        return 0;
    }
    if (bag >= wt[n - 1])
    {
        return max(val[n - 1] + solve(wt, val, n - 1, bag - wt[n - 1]), solve(wt, val, n - 1, bag));
    }
    else
    {
        return solve(wt, val, n - 1, bag);
    }
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
