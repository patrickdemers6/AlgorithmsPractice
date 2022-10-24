// https://cses.fi/problemset/task/1068
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << n;
    while (n != 1) {
        if (!(n & 1))
            n = n >> 1;
        else
            n += (n << 1) + 1;
        cout << " " << n;
    }
}