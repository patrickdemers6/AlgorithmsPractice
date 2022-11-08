/**
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
 *
 * Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`,
 * or -1 if `needle` is not part of `haystack`.
 */
#include <string>
using namespace std;
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;

        int i, j;
        bool success;
        for (i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            success = true;
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    success = false;
                    break;
                }
            }
            if (success)
                return i;
        }
        return -1;
    }
};