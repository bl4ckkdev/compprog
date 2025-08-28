#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    long long n; cin >> n;

    vector<pair<long long, long long>> p(n);
    vector<long long> maxx(n, 0), maxy(n, 0);

    for (long long i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (i == j) continue;

            if (p[i].first == p[j].first) {
                
                for (long long k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    if (p[k].second == p[i].second) {
                        long long x = abs(p[i].second - p[j].second);
                        long long y = abs(p[i].first - p[k].first);

                        if (x*y > maxx[i]*maxy[i]) {
                            maxx[i] = x;
                            maxy[i] = y;
                        }
                       //cout << maxx[i] << " " << maxy[i] << "  ";
                        //cout << p[i].first << " " << p[i].second << " " << p[j].first << " " << p[j].second << " " << p[k].first << " " << p[k].second << endl;
                    }
                    
                    if (p[k].second == p[j].second) {
                        long long x = abs(p[i].second - p[j].second);
                        long long y = abs(p[j].first - p[k].first);

                        if (x*y > maxx[i]*maxy[i]) {
                            maxx[i] = x;
                            maxy[i] = y;
                        }
                    }
                }
            }
        }
    }

    long long mxsf = 0;

    for (long long i = 0; i < n; i++) {
        if (maxx[i]*maxy[i] > mxsf) {
            mxsf = maxx[i]*maxy[i];
        } 
    }

    cout << mxsf << endl;
}