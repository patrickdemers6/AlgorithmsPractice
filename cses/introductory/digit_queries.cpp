/**
 * Digit Queries
 *
 * To get the number of digits up to a certain point in the string, notice the following pattern:
 * 1-9 = 1 * 9
 * 10-99 = 2 * 90
 * 100-999 = 3 * 900
 *
 * To get to n digits into the string, you must add in the fashion shown above. Once the value being added is >= n, the proper length has been found.
 *
 * Based on the length, we know the base which is 10^(len-1) and the offset (calcualted by n / len).
 *
 * Then, n%len gives the proper offset into the number found above. This yields the number at the requested distance into the sequence.
 *
 * https://cses.fi/problemset/task/2431/
 */
#include<iostream>
using namespace std;

// the built in pow function does not handle long long, therefore custom implementation
long long int pow(long long int n) {
    long long int result = 1;
    for (long long int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

int solve(long long int n) {
    if (n < 9) return (int) n+1;
    long long int len = 1, v;
    // determine how many digits until further into the string than n
    while ((v = 9 * pow(len-1) * len) < n) {
        n -= v;
        len++;
    }
    // get the whole number that is at n (base + offset)
    string s = to_string(pow(len-1) + n/len);
    // n % len = digits into number
    return (int) (s[n%len] - '0');
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        long long int input;
        cin >> input;
        cout << solve(input - 1) << endl;
    }
}