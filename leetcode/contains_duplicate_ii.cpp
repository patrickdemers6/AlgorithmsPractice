/**
 * Contains Duplicate II
 * 
 * Given an integer array nums and an integer k, return true
 * if there are two distinct indices i and j in the array such
 * that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 * https://leetcode.com/problems/contains-duplicate-ii
*/
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cost;
        for (int i = 0; i < nums.size(); ++i) {
            if (cost.find(nums[i]) == cost.end()) {
                cost[nums[i]] = i;
            } else {
                if (i - cost[nums[i]] <= k) return true;
                cost[nums[i]] = i;
            }
        }
        return false;
    }
};