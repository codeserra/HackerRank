#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    return (1+ (int) count_if(s.begin(), s.end(), [](unsigned char ch) { return isupper(ch); }));
}

int main() {
    string s;
    cin >> s;
    int result = camelcase(s);
    cout << result << endl;
    return 0;
}
