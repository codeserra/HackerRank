#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the diagonalDifference function below.
 */
int diagonalDifference(vector<vector<int>> a) {
    /*
     * Write your code here.
     */
    int total_sum = 0; 
    int n = a.size();
    for (int i = 0; i < ((n - 1) / 2) + 1; i++)
    {
          total_sum += a[i][i] - a[i][n-1-i] + ((i!=(n-1-i))?(a[n-1-i][n-1-i] - a[n-1-i][i]):0);
    }
    return ((total_sum<1)?(-1*total_sum):total_sum) ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
