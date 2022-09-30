// https://leetcode.com/problems/design-a-stack-with-increment-operation/
// additionally added sum calculation
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class CustomStack {
   public:
    vector<int> s;
    vector<int> additions;
    int max_size;
    int pos;
    int sum;
    CustomStack(int maxSize) : max_size(maxSize), pos(0), sum(0) {
        additions = vector<int>(maxSize + 1);
        s = vector<int>(maxSize + 1);
    }

    void push(int x) {
        if (pos == max_size) return;
        sum += x;
        additions[pos] = 0;
        s[pos++] = x;
    }
    bool isEmpty() {
        return pos == 0;
    }

    int pop() {
        if (isEmpty())
            return -1;
        pos--;
        sum -= s[pos] + additions[pos];
        if (!isEmpty()) additions[pos - 1] += additions[pos];
        return s[pos] + additions[pos];
    }

    int getSum() {
        if (isEmpty()) return 0;
        return sum;
    }

    void increment(int k, int val) {
        if (isEmpty()) return;
        int index = min(k - 1, pos - 1);
        sum += (index + 1) * val;
        additions[index] += val;
    }
};