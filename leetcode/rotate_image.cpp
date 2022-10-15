// https://leetcode.com/problems/rotate-image/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, S(matrix.size());
        for (i = 0; i < S; ++i) {
            for (j = i; j < S; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (i = 0; i < S; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};