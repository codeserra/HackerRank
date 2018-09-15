#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    string str="";
    for (auto &chr: s)
    {
        char c = static_cast <char>(chr);
        if(isalpha(c))
        {
            char a = isupper(c)?'A':'a';
            c =  a+ (c + k - a)%26;
            str = str+c;
        }
        else
            str = str +chr;
        
    }
    return str;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
