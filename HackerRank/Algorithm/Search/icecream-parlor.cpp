#include <bits/stdc++.h>

using namespace std;
// REVISIT this again
// note maps uses O(nlogn)
// use unordered map which uses O(n)
void icecreamParlor(int m, vector <int> arr) {
    map<int,int> maps;
    int n = arr.size();
    for (int i = 0; i<n; i++)
    {
        if( maps.find(arr[i])!=maps.end())
        {
            cout<<maps[arr[i]]+1<<" "<<i+1;
            break;
        }
        else
        {
            maps[m - arr[i]] = i;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int m;
        cin >> m;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        icecreamParlor(m, arr);
        cout << endl;


    }
    return 0;
}
