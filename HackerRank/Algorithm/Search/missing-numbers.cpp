#include <bits/stdc++.h>

using namespace std;

vector <int> missingNumbers(vector <int> arr, vector <int> brr) {
    // Complete this function
    vector <int> m_num;
/* Method 1 : Using Maps */
/*    map <int, int> sec_list;
    map <int, int> fst_list;
    for( auto &b: brr)
    {
        if(sec_list.find(b)==sec_list.end())
            sec_list[b] = 1;
        else
            sec_list[b] += 1;
    }

    for( auto &a: arr)
    {
        if(fst_list.find(a)==fst_list.end())
            fst_list[a] = 1;
        else
            fst_list[a] += 1;
    }
    
    for (auto x: sec_list)
    {
        if(fst_list.find(x.first)==sec_list.end())
            m_num.push_back(x.first);
        else if(fst_list[x.first]!=x.second)
            m_num.push_back(x.first);
    }
*/
    /* Method 1 : Using array */
    
    int freq[200] = {0};
    
    int pivot = brr.at(0);
    for( auto &b: brr)
        freq[100 +(b-pivot)]--;
    
    for( auto &a: arr)
        freq[100 +(a-pivot)]++;
    
    for( int i = -100; i<100; i++)
        if(freq[100 +i]!=0)
            m_num.push_back((pivot +i));
    
    return m_num;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for(int brr_i = 0; brr_i < m; brr_i++){
       cin >> brr[brr_i];
    }
    vector <int> result = missingNumbers(arr, brr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
