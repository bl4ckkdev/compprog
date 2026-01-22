#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, m, k; cin >> n >> m >> k;

        long long l = k, r = k;

        long long days = 0;
        long long forts = 1;

        

        long long left;
        long long right; 
        long long soldiers;

        if (k-1<n-k) {
            for (long long i = 1; i < n; i++) {
                if (i+i-1 <= m && i <= n-k) {
                    right = i;

                    days = right+right-1;
                    soldiers = i;
                } else break;
            }    


            m -= days;

            //cout << right << " ";

            for (long long i = 1; i < n; i++) {
                if (i+i-1 <= m+1) {
                    soldiers = i;
                } else break;
            }    

            soldiers = min(soldiers, m);
            soldiers = min(soldiers, k-1);
            
            left = soldiers;

            //cout << left << " ";
            
            days += soldiers + soldiers-1;
        } else {
            //left = min((long long)ceil(m/(double)2), k-1);
            //days += left + left-1;
            //soldiers = left;

            for (long long i = 1; i < n; i++) {
                if (i+i-1 <= m && i <= k-1) {
                    left = i;

                    days = left+left-1;
                    soldiers = i;
                } else break;
            }    

            m -= days;

            for (long long i = 1; i < n; i++) {
                if (i+i-1 <= m+1) {
                    soldiers = i;
                } else break;
            }    

            //cout << soldiers << " ";
            soldiers = min(soldiers, m);

            soldiers = min(soldiers, n-k);

            right = soldiers;

            days += soldiers + soldiers-1;
        }
        
        cout << left+right+1 << endl;
    }
}