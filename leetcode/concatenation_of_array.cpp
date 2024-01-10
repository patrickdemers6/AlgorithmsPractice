// https://leetcode.com/problems/concatenation-of-array/
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N << 1);
        for (int i = 0; i < N; ++i) {
            ans[i] = ans[i + N] = nums[i];
        }
        return ans;
    }
};
