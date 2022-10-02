// https://leetcode.com/problems/count-artifacts-that-can-be-extracted
#include <iostream>
#include <unordered_set>
#include <vector>

// number's max is 1000; therefore a * 2^10 + b is always unique (for use in set)
#define HASH(a, b) (a << 10) + b

using namespace std;
class Solution {
   public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> s;
        int excavated(0);
        for (auto& d : dig) {
            s.insert(HASH(d[0], d[1]));
        }
        bool exit;
        for (auto& artifact : artifacts) {
            exit = false;
            for (int y = artifact[1]; y <= artifact[3] && !exit; ++y) {
                for (int x = artifact[0]; x <= artifact[2]; ++x)
                    if (!s.count(HASH(x, y))) {
                        exit = true;
                        break;
                    }
            }
            if (!exit) ++excavated;
        }
        return excavated;
    }
};
