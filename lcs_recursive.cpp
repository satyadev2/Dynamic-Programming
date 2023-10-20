#include <bits/stdc++.h>
using namespace std;

int solve(string text1, string text2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    else if (text1[n - 1] == text2[m - 1])
    {
        return 1 + solve(text1, text2, n - 1, m - 1);
    }
    else
    {
        return max(solve(text1, text2, n - 1, m), solve(text1, text2, n, m - 1));
    }
}
int main()
{
    string x;
    string y;
    cin >> x;
    cin >> y;
    int n = x.size();
    int m = y.size();
    cout << solve(x, y, n, m);
}
