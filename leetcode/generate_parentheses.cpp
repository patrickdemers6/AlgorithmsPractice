/**
 * Generate Parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * https://leetcode.com/problems/generate-parentheses
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    unordered_map<int, vector<string>> m;
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int i;

        // dp
        if (m.find(n) != m.end()) {
            return m[n];
        }

        if (n == 0) {
            result.push_back("");
        } else {
            for (i = 0; i < n; i++) {
                for (string left : generateParenthesis(i)) {
                    for (string right : generateParenthesis(n - 1 - i)) {
                        result.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        m[n] = result;
        return result;
    }
};