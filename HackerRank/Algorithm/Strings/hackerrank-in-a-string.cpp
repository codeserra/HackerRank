#include <bits/stdc++.h>

using namespace std;

string hackerrankInString(string s) {
    string h ="hackerrank";
    int j = 0; 
    for (auto &i:s)
    {
       // cout <<" i="<<i<<" h="<<h.at(j)<<" j="<<j<<endl;
        if(j<(h.length()-1))
            if(i==h.at(j))
                j++;
    }
    return (j==(h.length()-1))?"YES":"NO";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = hackerrankInString(s);
        cout << result << endl;
    }
    return 0;
}
