#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long a, b, ca, cb, f; cin >> a >> b >> ca >> cb >> f;

        a += b/cb*ca;
        b %= cb;

        if (a>=f) {
            cout << "0\n";
        }
        else if (ca>=cb) {
            cout << f-a+max(cb-b-1, 0LL) << endl;
        } else {
            long long dss=0;

            bool aa = false;
            if ((f-a)%(ca) == 0) {
                aa = true;
            }
                

            dss += (f-a)/ca*cb;
            a += (f-a)/ca*ca;
            if (aa) {
                dss-=cb;
                a-=ca;
            }
            //cout << dss << " " << a << " ";
            dss -= b;

            dss += max(f-a+cb-1, (f-a)/ca*cb);

            cout << dss << endl;
        }

    }
}