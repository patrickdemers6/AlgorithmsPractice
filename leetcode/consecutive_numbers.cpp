// https://leetcode.com/problems/consecutive-numbers-sum/
#include <cmath>
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 1, i;
        for (i = 2; i < sqrt(2 * n); i++) {
            if ((n - (i * (i - 1) / 2)) % i == 0)
                count++;
        }
        return count;
    }
};