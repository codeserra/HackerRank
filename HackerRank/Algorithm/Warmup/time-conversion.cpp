#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */


string timeConversion(string str) 
{
    // get string hour time
    std::size_t h_pos = str.find_first_of(":"); 
    int hh = stoi(str.substr(0, h_pos)); 
    
    string ampm = str.substr(str.size() - 2);
    char t2[3];
    //if(pos != std::string::npos && hh!=12)
    if(ampm == "PM" && hh!=12)  
    {
        hh= (hh+12);
    }
    else if (ampm == "AM" && hh==12)
    {
        hh = 0;
    }

    sprintf(t2, "%02d",hh );
    string new_time;
    new_time= string(t2) + str.substr(h_pos, str.size()-h_pos -2);
    return new_time;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
