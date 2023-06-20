#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void findSubsequences(const std::vector<int> &nums, int index, int target, std::vector<int> &current, std::vector<std::vector<int>> &result)
{
    if (target == 0)
    {
        // Found a subsequence with the target sum
        result.push_back(current);
        return;
    }

    if (index == nums.size())
    {
        // Reached the end of the array
        return;
    }

    // Skip the current element and move to the next index
    findSubsequences(nums, index + 1, target, current, result);

    // Take the current element if it is less than or equal to the target
    if (nums[index] <= target)
    {
        current.push_back(nums[index]);
        findSubsequences(nums, index, target - nums[index], current, result);
        current.pop_back();
    }
}

std::vector<std::vector<int>> getSubsequences(const std::vector<int> &nums, int target)
{
    cout << "jiwhg";
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    findSubsequences(nums, 0, target, current, result);
    return result;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;

    std::vector<std::vector<int>> subsequences = getSubsequences(nums, target);

    std::cout << "Subsequences with sum " << target << ":" << std::endl;
    for (const auto &subsequence : subsequences)
    {
        for (int num : subsequence)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
