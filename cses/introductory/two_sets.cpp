// https://cses.fi/problemset/task/1092/
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, i, a_sum(0), b_sum(0);
    cin >> n;

    if (n < 3) {
        cout << "NO";
        return 0;
    }

    vector<int> a, b;
    for (i = n; i; --i) {
        if ((n-i) % 4 == 0 || (n-i) % 4 == 3) {
            a.push_back(i);
            a_sum += i;
        }
        else {
            b.push_back(i);
            b_sum += i;
        }
    }

    if (a_sum != b_sum) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (auto& v : {a, b}) {
        cout << v.size() << endl;
        for (const int &o: v) {
            cout << o << " ";
        }
        cout << endl;
    }
}
