// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
#include <iostream>
#include <vector>
using namespace std;

#define feo(a) for (int i = 0; i < a.size(); ++i)
#define fei(b) for (int j = 0; j < b.size(); ++j)
#define fe(a) feo(a) fei(a[0])

class Solution {
   public:
    int minimumDeletions(vector<int>& nums) {
        int low(0), high(0);
        feo(nums) {
            if (nums[i] < nums[low])
                low = i;
            else if (nums[i] > nums[high])
                high = i;
        }
        if (low > high) swap(low, high);
        // ->low high<-, ->high, low<-
        return min(min(low + ((int)nums.size() - 1 - high) + 2, high + 1), (int)nums.size() - low);
    }
};
