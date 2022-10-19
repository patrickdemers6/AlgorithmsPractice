// https://cses.fi/problemset/task/1755/
#include<iostream>
#include<map>
#define ODD(a) (a & 1)
using namespace std;

int main() {
    string s, result;
    int i;
    cin >> s;

    map<char, int> m;
    for (const char& c : s) {
        ++m[c];
    }

    char odd_char = '\0';
    for (const auto& letter : m) {
        if (ODD(letter.second)) {
            if (odd_char) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd_char = letter.first;
        }
        for (i = ((letter.second >> 1) << 1); i; i -= 2) {
            result += letter.first;
        }
    }

    i = result.size() - 1;
    if (odd_char)
        result += odd_char;

    // add the back half of palindrome in reverse order of front
    for (; i >= 0; --i) {
        result += result[i];
    }

    cout << result << endl;

    return 0;
}