/**
 * Apple Division
 *
 * There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
 *
 * Approach: recursively explore all possible combinations. For each number in the input, it can be placed in group 1 or group 2. Whenever at the end of the array, determine if the difference is less than the minimum.
 *
 * Link: https://cses.fi/problemset/task/1623/
 */
#include<iostream>
#include<vector>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define lli long long int
using namespace std;

lli best;

void rec(vector<lli>& numbers, int index, lli group_1, lli group_2) {
    if (index == numbers.size()) {
        lli diff = abs(group_1 - group_2);
        if (diff < best)
            best = diff;
        return;
    }
    rec(numbers, index + 1, group_1 + numbers[index], group_2);
    rec(numbers, index + 1, group_1, group_2 + numbers[index]);
}

int main() {
    int n, curr;
    best = INT32_MAX;
    cin >> n;
    vector<lli> v;
    FOR(i, 0, n, 1) {
        cin >> curr;
        v.push_back(curr);
    }
    rec(v, 0, 0, 0);
    cout << best << endl;
    return 0;
}