#include <bits/stdc++.h>

using namespace std;

long int stockmax(vector <int> prices) {
    // Complete this function
    long int profit =0;
    int max_till_now =prices.at(prices.size()-1); 
    for (int i =(prices.size()-1); i>= 0; i--)
    {
        if(max_till_now> prices.at(i))
            profit+= (max_till_now - prices.at(i));
        else
            max_till_now= prices.at(i);   
    }
    return profit;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> prices(n);
        for(int prices_i = 0; prices_i < n; prices_i++){
           cin >> prices[prices_i];
        }
        long int result = stockmax(prices);
        cout << result << endl;
    }
    return 0;
}
