#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the staircase function below.
 */
void staircase(int n) {
    /*
     * Write your code here.
     */
    int i_count = 1; 
    std::string s_str(n, ' '); 
    for(int i = 0; i<n; i++)
    {
        s_str.begin()[n-i-i_count]='#';
        cout<<s_str<<endl;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
