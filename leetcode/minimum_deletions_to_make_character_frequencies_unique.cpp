// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

#define feo(a) for (int i = 0; i < a.size(); ++i)
#define fei(b) for (int j = 0; j < b.size(); ++j)
#define fe(a) feo(a) fei(a[0])

class Solution {
   public:
    int minDeletions(string s) {
        // count all characters
        unordered_map<char, int> m;
        feo(s) {
            ++m[s[i]];
        }

        // store counts of characters that occur
        vector<int> v;
        for (auto a : m) {
            if (a.second)
                v.emplace_back(a.second);
        }

        // sort greatest to least
        sort(v.rbegin(), v.rend());

        // go forward from each val, decrementing while num occurences
        int count(0);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[j] && v[i] == v[j]) {
                    --v[j];
                    ++count;
                } else
                    break;
            }
        }
        return count;
    }
};
