#include <string>
using namespace std;
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i(s.length() - 1), start;
        while (s[i] == ' ')
            --i;

        start = i;
        for (; i >= 0; --i) {
            if (s[i] == ' ')
                break;
        }
        return start - i;
    }
};
