#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int> &satya, vector<vector<int>> &satyaa, vector<int> &nums)
{
    if (i >= nums.size())
    {
        satyaa.push_back(satya);
        return;
    }
    solve(i + 1, satya, satyaa, nums);
    satya.push_back(nums[i]);
    solve(i + 1, satya, satyaa, nums);
    satya.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> satya;
    vector<vector<int>> satyaa;
    solve(0, satya, satyaa, nums);
    for (auto i : satyaa)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
