#include <bits/stdc++.h>

using namespace std;


struct IsUpper {
    bool operator()(int value) 
    {
        return ::isupper((unsigned char)value); 
    }
};


// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool isnum =0; 
    bool islow =0;
    bool isupp =0;
    int isspe =0;

    isnum = (std::string::npos==password.find_first_of("0123456789"));
    isupp = std::string::npos==password.find_first_of ("abcdefghijklmnopqrstuvwxyz");
    islow = std::string::npos==password.find_first_of ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    isspe = std::string::npos==password.find_first_of ("!@#$%^&*()-+");
 
    int sol = (isnum) + (islow) + (isupp) +(isspe);
    return max(6-n,sol);     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
