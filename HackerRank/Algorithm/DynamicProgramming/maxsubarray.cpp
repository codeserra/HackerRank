//---------------------------------------------------------------------------------------------------
//        https://www.hackerrank.com/challenges/maxsubarray/problem
//---------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int maxSumSubArray (vector <int> arr)
{
    int cur_max = arr.at(0);
    int tot_max = arr.at(0);
    int isz = arr.size();
    
    for (int i =1;i<isz; i++)
    {
        cur_max = std::max(arr.at(i), (arr.at(i)+cur_max) );
        tot_max = std::max(cur_max, tot_max);
    }
    
    return tot_max;
}

int maxSumSubSequence(vector<int> arr)
{
    int imax = 0;
    vector<int> msis;
    msis = arr;
    std::sort(msis.begin(), msis.end());
    int isz = arr.size();
    
    imax = msis[isz-1];
            
    //cout<<"---- "<<endl;
    
    for (int j = isz-2; j>=0; j--)
        if ((imax + msis[j]) > imax)
        {
            //cout<<"push arr["<<j<<"] = "<<msis[j]<<endl;
            imax +=msis[j];
        }
    return imax;
}
// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {

    vector<int> result;
    result.push_back(maxSumSubArray(arr));
    result.push_back(maxSumSubSequence(arr));
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
