// https://leetcode.com/problems/add-minimum-number-of-rungs/
#include <vector>
using namespace std;
class Solution {
   public:
    int addRungs(vector<int>& rungs, int dist) {
        int N = rungs.size();
        int rungs_missing = (rungs[0] - 1) / dist, i = 0;
        for (; i < N - 1; ++i) {
            rungs_missing += (rungs[i + 1] - rungs[i] - 1) / dist;
        }
        return rungs_missing;
    }
};
