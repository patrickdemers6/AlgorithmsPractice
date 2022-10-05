// https://cses.fi/problemset/task/1069/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int i;
    string input;
    cin >> input;
    int c(1), mc(-1);
    char curr = input[0];
    for (i = 1; i < input.size(); ++i) {
        if (input[i] != curr) {
            curr = input[i];
            mc = max(mc, c);
            c = 1;
        } else
            ++c;
    }
    mc = max(mc, c);
    cout << mc << endl;
    return 0;
}