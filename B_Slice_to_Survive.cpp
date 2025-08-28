#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long m, n, a, b; cin >> m >> n >> b >> a;

        long long x = a, y = b;

        long long moves = 0;

        long long tries = 100;
        while ((n > 1 || m > 1)) {

            long long r, c;

            c = max(n-x, x-1)*m;
            r = max(m-y, y-1)*n;

            //cout << x << " " << y << " " << c << " " << r << " " << m << " " << n << endl;


            if (c > r) {
                if (n-x>x-1) {
                    n = x;
                } else {
                    n = n-x+1;
                    x = 1;
                }
            } else if (c <=r) {
                if (m-y>y-1) {
                    m = y;
                } else {
                    m = m-y+1;
                    y = 1;
                }
            }

            long long middlex = ceil((long double)n/2), middley = ceil((long double)m/2);
            
            x = middlex; y = middley;

            //cout << x << " " << y << " " << c << " " << r << " " << n << " " << m << endl << endl;


            moves++;
            //tries--;
        }

        cout << moves << endl;// << endl;
    }
}