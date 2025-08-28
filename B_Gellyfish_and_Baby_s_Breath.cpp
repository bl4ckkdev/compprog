#include <bits/stdc++.h>

using namespace std;

int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        vector<int> q(n);

        vector<int> largestp(n);
        vector<int> pindex(n);

        int largep = -1;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;

            if (num > largep) {
                largep = num;
                pindex[i] = i;
            } 
            else if (i>0) pindex[i] = pindex[i-1];

            largestp[i] = largep;
            p[i] = num;
        }


        vector<int> largestq(n);
        vector<int> qindex(n);

        int largeq = -1;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;

            if (num > largeq) {
                largeq = num;
                qindex[i] = i;
            } else if (i>0) qindex[i] = qindex[i-1];

            largestq[i] = largeq;
            q[i] = num;
        }

        vector<int> r(n);
        
        for (int i = 0; i < n; i++) {
            cout << max((long long)(power(2LL, largestp[i], 998244353) + power(2, q[i-pindex[i]], 998244353LL)), 
                        (long long)(power(2LL, largestq[i], 998244353) + power(2, p[i-qindex[i]], 998244353LL))) << " ";
            //if (largestp[i] + q[i-pindex[i]] > largestq[i] + p[i-qindex[i]]) {
                //cout << pindex[i] << "|";
                //cout <<  << " ";
            //} else {
                //cout << qindex[i] << "||";
                //cout << () << " ";
            //}
        }

        cout << endl;
    }
}