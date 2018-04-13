#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the miniMaxSum function below.
 */
void miniMaxSum(vector<long long int> arr) {
    /*
     * Write your code here.
     */
    //sort(arr.begin(), arr.end());
    //long long int i_min = std::accumulate(arr.begin(), arr.end() - 1, 0);
    //long long int i_max = std::accumulate(arr.begin()+1, arr.end() , 0);
    long long int i_min = 100000000000;
    long long int i_max = 0;
    long long int i_sum = 0;
    for(vector<long long int>::iterator it = arr.begin(); it!=arr.end(); it++)
    {
        if(i_min>(*it))
            i_min = (*it);
        
        if(i_max<(*it))
            i_max = (*it);
        
        i_sum+=(*it);
    }
    
    cout<< i_sum - i_max << " " << i_sum - i_min;
        
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long long int> arr(5);

    for (int arr_itr = 0; arr_itr < 5; arr_itr++) {
        long long int arr_item = stoll(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    miniMaxSum(arr);

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
