/**
 * Tower of Hanoi
 * https://cses.fi/problemset/task/2165
 */
#include <iostream>
using namespace std;

void rec(int from, int aux, int to, int n) {
    if (!n)
        return;
    rec(from, to, aux, n - 1);
    cout << from << ' ' << to << endl;
    rec(aux, from, to, n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    rec(1, 2, 3, n);
    return 0;
}