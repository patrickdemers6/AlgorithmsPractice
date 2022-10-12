// https://cses.fi/problemset/task/2205/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    v.emplace_back("0");
    v.emplace_back("1");

    int n;
    cin >> n;
    for (int i = 2; i < (1 << n); i *= 2) {
        for (long j = v.size() - 1; j >= 0; j--)
            v.push_back(v[j]);

        for (int j = 0; j < i; j++)
            v[j] = "0" + v[j];

        for (int j = i; j < i * 2; j++)
            v[j] = "1" + v[j];
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}