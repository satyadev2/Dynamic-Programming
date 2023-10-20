// A recursive solution for Rod cutting problem
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

// UNBOUNDED KNAPSACK
int dp[1005];
int solve(vector<int> &prices, int total_length)
{
    if (dp[total_length] != -1)
    {
        return dp[total_length];
    }
    if (total_length == 0)
        return dp[total_length] = 0;
    int ans = 0;
    for (int cur_length = 1; cur_length <= prices.size(); cur_length++)
    {
        if (total_length - cur_length >= 0)
            ans = max(ans, solve(prices, total_length - cur_length) + prices[cur_length - 1]);
    }
    return dp[total_length] = ans;
}
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> prices(arr, arr + size);
    cout << solve(prices, size);
}

// This code is contributed by Sanskar
