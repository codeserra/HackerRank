#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sherlockAndMinimax function below.
int sherlockAndMinimax(vector<int> arr, int p, int q) {
    sort (arr.begin(), arr.end());
    int ans = - 1;
    int min_val  = -1;
    int n = arr.size();

    if (arr[0]>q)
        return p; 
    
    if (arr[n-1]<p)
    return q;

    int mid =0;

    if (arr[0]> p)
    {
        if (ans < (arr[0] - p))
        {
            ans = arr[0] - p;
            min_val = p;
        }
    } 

    if (arr[n-1] < q)
        if (ans < q - arr[n-1])
        {
            ans = q - arr[n-1];
            min_val = q; 
        }

    for(int i =0; i<n-1; i++)
    {
        mid =  (arr[i] + arr[i+1])/2;
        if (mid <=q && mid >= p && (mid - arr[i])>ans)
        {
            ans = mid - arr[i];
            min_val = mid;
        }
        else if( mid > q)
        {
            if((q-arr[i])> ans)
            {
                ans = q - arr[i];
                min_val = q;
            }
        }
        else if( mid < p)
        {
            if ((arr[i+1] - p)> ans )
            {
                ans = arr[i+1] - p;
                min_val = p;
            }
        }
    }

    

    return min_val; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    string pq_temp;
    getline(cin, pq_temp);

    vector<string> pq = split_string(pq_temp);

    int p = stoi(pq[0]);

    int q = stoi(pq[1]);

    int result = sherlockAndMinimax(arr, p, q);

    fout << result << "\n";

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
