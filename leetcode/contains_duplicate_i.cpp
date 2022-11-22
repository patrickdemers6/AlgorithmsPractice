/**
 * Contains Duplicate
 * 
 * Given an integer array nums, return true if
 * any value appears at least twice in the array,
 * and return false if every element is distinct.
 * 
 * https://leetcode.com/problems/contains-duplicate
 */
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (!s.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};