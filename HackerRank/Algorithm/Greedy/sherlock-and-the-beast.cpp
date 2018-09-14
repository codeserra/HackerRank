// https://www.hackerrank.com/challenges/sherlock-and-the-beast/submissions/code/84630734

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
string decentNumber(int n) {
    // solve Diophantine equation: n = 5x - 3y
    string num="";
    int numfives = n - (n%3); 
    int numthrees = n - numfives;
    
    while (numthrees%5)
        numthrees+=3;
    
    numfives = n - numthrees;
    
    if(numfives<0 || numthrees<0)
        return "-1";
    
    num="";
    for (int i =0; i<numfives; i++)
        num+="5";
    
    for (int j=0; j<numthrees; j++)
        num+="3";
    
    return num;
    
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        cout<< decentNumber(n)<<endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
