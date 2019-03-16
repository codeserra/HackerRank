#include <bits/stdc++.h>
#define MOD107 1000000007
using namespace std;

typedef long long ll;

vector<string> split_string(string);

struct compare_item{
    bool operator() (pair<ll, ll> & a, pair<ll, ll> & b)
    {
        return (a.first<b.first);
    }
};

// Complete the boardCutting function below.
ll boardCutting(priority_queue<ll,vector<pair<ll,ll>>,compare_item> & Q) {
    ll xcut = 0;
    ll ycut = 0;
    ll cost =0;
    int count =0;
    while (!Q.empty())
    {
        pair<ll, ll> i = Q.top();
        Q.pop();
        if(i.second)
        {
            cost += (ycut+1)*i.first;
            xcut++;
            //cout<<" i.first="<<i.first<<endl;
        }
        else
        {
            cost += (xcut+1)*i.first;
            ycut++;
            //cout<<" i.first="<<i.first<<endl;
        }
        cost = cost%MOD107; 
        //cout<< "Debug count#"<<++count<<" cost ="<<cost<<endl;
    }
    return cost;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string mn_temp;
        getline(cin, mn_temp);

        vector<string> mn = split_string(mn_temp);

        int m = stoi(mn[0]);

        int n = stoi(mn[1]);

        string cost_y_temp_temp;
        getline(cin, cost_y_temp_temp);

        vector<string> cost_y_temp = split_string(cost_y_temp_temp);

        //vector<ll> cost_y(m-1);
        priority_queue<ll,vector<pair<ll,ll>>,compare_item> Q;

        for (int i = 0; i < m-1; i++) {
            ll cost_y_item = stoi(cost_y_temp[i]);
            //cost_y[i] = cost_y_item;
            Q.push(make_pair(cost_y_item, 0));
        }

        string cost_x_temp_temp;
        getline(cin, cost_x_temp_temp);

        vector<string> cost_x_temp = split_string(cost_x_temp_temp);

        //vector<ll> cost_x(n-1);

        for (int i = 0; i < n-1; i++) {
            ll cost_x_item = stoi(cost_x_temp[i]);
            //cost_x[i] = cost_x_item;
            Q.push(make_pair(cost_x_item, 1));
        }

        ll result = boardCutting(Q);

        fout << result << "\n";
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
