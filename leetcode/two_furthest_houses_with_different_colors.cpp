// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
#include <vector>
using namespace std;

class Solution {
   public:
    int maxDistance(vector<int>& colors) {
        int left(-1), right(colors.size()), size(colors.size() - 1);
        while (colors[0] == colors[--right])
            ;
        while (colors[++left] == colors[size])
            ;
        return max(size - left, right);
    }
};