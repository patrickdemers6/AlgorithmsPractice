// https://leetcode.com/problems/longest-palindrome/
#include <algorithm>
#include <string>
using namespace std;
class Solution {
   public:
    int longestPalindrome(string s) {
        int N = s.size(), longest_len = 0, middle_char = N % 2;
        sort(s.begin(), s.end());
        for (int i = 0; i < N - 1;) {
            if (s[i] == s[i + 1]) {
                longest_len += 2;
                i += 2;
            } else {
                middle_char = 1;
                i += 1;
            }
        }
        return longest_len + middle_char;
    }
};
