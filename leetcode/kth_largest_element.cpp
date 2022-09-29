// https://leetcode.com/problems/kth-largest-element-in-an-array
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (int n : nums) {
        pq.emplace(n);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
