#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> &satya, vector<vector<int>> &satyaa)
{
    if (nums.empty())
    {
        satyaa.push_back(satya);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int k = nums[i];
        nums.erase(nums.begin() + i);
        satya.push_back(k);

        solve(nums, satya, satyaa);

        // backtrack----we dont want to decrease size of output

        nums.insert(nums.begin() + i, k);
        satya.pop_back();
    }
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

    vector<vector<int>> satyaa;
    vector<int> satya;

    solve(nums, satya, satyaa);

    for (auto i : satyaa)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
