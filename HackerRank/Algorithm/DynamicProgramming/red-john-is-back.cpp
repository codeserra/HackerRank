#include <bits/stdc++.h>

using namespace std;

vector<int> numways;
vector<bool> primes;
int countways (int n, int m)
{
    int istrt = numways.size();
  
    if(numways.size()<(n+1))
    {
        numways.resize(n+1);
        numways.at(0) =0;
        
        if(istrt ==0)
            istrt++;
        
        for (int i=istrt; i<n+1; i++)
        {
            if (i>m)
                numways[i] = numways[i-1] + numways[i-m];
            else if(i<m)
                numways[i] =1;
            else //i==4
                numways[i] =2;
        }
    }
    /*
    cout<<"  numways: "<< endl;
    for(int p=0; p<=n; p++)
        cout<<numways[p]<<" ";
    cout<< endl;
    cout<< endl;
    */
    
    return numways.at(n);
}

int SievePrimes (int n)
{
    int istrt = primes.size();
  
    if(primes.size()<(n+1))
    {
        primes.resize(n+1, true);
        if(n>=0)
            primes.at(0) = false;
        if(n>=1)
            primes.at(1) = false;
               
        for(int p =2; p*p<n; p++)
        {
            if(primes.at(p)== true)
            {
                for (int i=p*2; i<=n; i+=p)
                    primes.at(i) = false;
            }
        }
    }
    /*
    cout<<"  primes: "<< endl;
    for(int p=0; p<=n; p++)
        cout<<primes[p]<<" ";
    cout<< endl;
    cout<< endl;
    */
    return (count(primes.begin(), primes.begin()+n+1, true));
}

// Complete the redJohn function below.
int redJohn(int n) {

    int nways = countways(n, 4);
    cout<<" nways= "<<nways<<endl;
    return SievePrimes(nways);
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

        int result = redJohn(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
