// https://leetcode.com/problems/sliding-puzzle/
#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

#define feo(a) for (int i = 0; i < a.size(); ++i)
#define fei(b) for (int j = 0; j < b.size(); ++j)
#define fe(a) feo(a) fei(a[0])

#define LOGGING 1
string goal = "123450";
vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

class Solution {
   public:
    string boardToString(vector<vector<int>> &board) {
        string s = "";
        fe(board) {
            s += to_string(board[i][j]);
        }
        return s;
    }

    int slidingPuzzle(vector<vector<int>> &board) {
        string original = boardToString(board);

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.emplace(original, 0);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            string b = curr.first;
            int count = curr.second;
            int z = b.find("0");

            if (b == goal)
                return count;

            for (int to : dirs[z]) {
                string next = b;
                swap(next[z], next[to]);

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.emplace(next, count + 1);
                }
            }
        }

        return -1;
    }
};
