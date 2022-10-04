// https://cses.fi/problemset/task/1083
#include <iostream>
using namespace std;

int main() {
    int n, v, i;
    cin >> n;
    int xorer = 0;
    for (i = 1; i < n; ++i) {
        cin >> v;
        xorer = xorer ^ v ^ i;
    }
    cout << (xorer ^ n) << endl;
    return 0;
}