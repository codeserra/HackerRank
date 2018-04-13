#include <bits/stdc++.h>
using namespace std;
//--------------------------- NOTE ------------------------------------
// To maximize A xor B, we want A and B to differ as much as possible at every bit index.
// We first find the most significant bit that we can force to differ by looking at L and R.
// For all of the lesser significant bits in A and B, we can always ensure that they differ and still have L <= A <= B <= R.
// Our final answer will be the number represented by all 1s starting from the most significant bit that differs between A and B
//   L = 10111   
//   R = 11100
//       _X___  <-- that's most significant differing bit
//       01111  <-- here's our final answer
//---------------------------------------------------------------------

int maximizingXor(int l, int r) {
    // Complete this function
    int value = l^r; 
    int result = 1; 
    while (value)
    { 
        value = value>>1;       
        result = result<<1;
    }
    return (result - 1);
}

int main() {
    int l;
    cin >> l;
    int r;
    cin >> r;
    int result = maximizingXor(l, r);
    cout << result << endl;
    return 0;
}
