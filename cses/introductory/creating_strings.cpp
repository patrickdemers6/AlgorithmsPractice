/**
 * https://cses.fi/problemset/task/1622
 * Creating Strings
*/
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

set<string> output_strings;

unordered_map<char, int> get_char_occurrences(string s) {
    unordered_map<char, int> result;
    for (char& c : s) {
        ++result[c];
    }
    return result;
}

void rec(unordered_map<char, int>& char_occurrences, string s, size_t str_len) {
    if (s.size() == str_len) {
        output_strings.insert(s);
        return;
    }

    for (auto& c : char_occurrences) {
        if (c.second) {
            --(char_occurrences[c.first]);
            rec(char_occurrences, s + c.first, str_len);
            ++(char_occurrences[c.first]);
        }
    }
}

void print_output() {
    cout << output_strings.size() << endl;
    for (auto& s : output_strings) {
        cout << s << endl;
    }
}

int main() {
    string input;
    cin >> input;
    unordered_map<char, int> char_occurrences = get_char_occurrences(input);

    rec(char_occurrences, "", input.size());

    print_output();

    return 0;
}