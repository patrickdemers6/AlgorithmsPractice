/**
 * Two Sum
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * https://leetcode.com/problems/two-sum
 */

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N(nums.size()), left(0), right(N - 1), complement, i;
        unordered_map<int, int> seen;
        for (i = 0; i < N; ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                return {i, seen[nums[i]]};
            }
            complement = target - nums[i];
            seen[complement] = i;
        }
        return {};
    }
};