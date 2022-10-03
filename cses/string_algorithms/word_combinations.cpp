// https://cses.fi/problemset/task/1731/
#include <iostream>
#include <vector>
#define range(a) for (int i = 0; i < a; ++i)
#define MOD 1000000007
using namespace std;

/**
 * Algorithm steps:
 * 1. Load a trie with words that can be used to form string
 * 2. For each character (i) from end -> beginning of string:
 *      Iterate from the character -> end (j)
 *      Whenever the end of a word is found d[i] += d[j+1]
 * d[j+1] is the number of times to create the word past the current end point (j)
 * By the end, d[0] contains the number of ways to create the string
 *
 */

class Trie {
   public:
    Trie* nodes[26];
    bool end;
    Trie() {
        this->end = false;
        range(26) {
            nodes[i] = nullptr;
        }
    }
    void insertString(string s) {
        Trie* t = this;
        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            if (!t->nodes[index]) t->nodes[index] = new Trie();
            t = t->nodes[index];
        }
        t->end = true;
    }
    bool searchString(string s) {
        Trie* t = this;
        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            if (!t->nodes[index]) return false;
            t = t->nodes[index];
        }
        return t->end;
    }

    vector<int> findEndOfWordsTraverseString(string s, int startingPosition) {
        vector<int> result;
        Trie* current = this;
        for (int i = startingPosition; i < s.length(); ++i) {
            int index = s[i] - 'a';
            if (!current->nodes[index]) break;
            current = current->nodes[index];
            if (current->end) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    string w;
    Trie* trie = new Trie();
    string s;
    int n;
    cin >> s >> n;
    range(n) {
        cin >> w;
        trie->insertString(w);
    }
    vector<int> dp(s.length() + 1, 0);
    dp[s.length()] = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        vector<int> word_ends = trie->findEndOfWordsTraverseString(s, i);
        for (int& word_end_index : word_ends) {
            dp[i] += dp[word_end_index + 1] % MOD;
            dp[i] %= MOD;
        }
    }
    cout << dp[0] << endl;

    return 0;
}