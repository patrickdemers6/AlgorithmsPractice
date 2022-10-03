#include <iostream>
#include <vector>
using namespace std;

class Trie {
   public:
    Trie* nodes[26];
    bool end;
    Trie() {
        this->end = false;
        for (int i = 0; i < 26; ++i) {
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