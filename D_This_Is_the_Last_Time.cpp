#include <bits/stdc++.h>

using namespace std;

struct Casino {
    long long l, r, real, index;
    bool reachable;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<Casino> casinos(n);

        for (long long i = 0; i < n; i++) {
            Casino c;
            cin >> c.l;
            cin >> c.r;
            cin >> c.real;

            c.index = i;

            c.reachable = false;
            casinos[i] = c;
        }

        sort(casinos.begin(), casinos.end(), [](Casino& a, Casino& b) {
            return a.l < b.l;
        });

        long long mx = k;

        for (int i = 0; i < n; i++) {
            if (casinos[i].l <= mx && casinos[i].r >= mx) {
                mx = max(mx, casinos[i].real);
            }
        }

        cout << mx << endl;


        /*priority_queue<int> H;

        int j = 0, coins = k, best = 0;

       //cout << casinos[0].l << endl << endl;
        while (j<n && casinos[j].l <= coins) {
            //cout << "hi";
            if (coins <= casinos[j].r) {
                H.push(casinos[j].real);
            }

            if (H.empty()) {
                break;
            } else {
                best = H.top();
                H.pop();

                if (best <= coins) cout<< "";
                else coins = best;
            }
            j++;
        }*/

        /*cout << coins << endl;

        

        queue<Casino> q;
        vector<bool> visited(n);

        for (long long i = 0; i < n; i++) {
            if (casinos[i].l <= k && casinos[i].r >= k) {
                casinos[i].reachable = true;
                q.push(casinos[i]);
            }
        }

        while (!q.empty()) {
            Casino c = q.front();
            q.pop();

            if (visited[c.index]) continue;
            visited[c.index] = true;

            for (long long i = 0; i < n; i++) {
                if (c.real >= casinos[i].l && c.real <= casinos[i].r) {
                    q.push(casinos[i]);
                    casinos[i].reachable = true;
                }
            }
        }



        //for (auto& i : casinos) {
        //    cout << i.real << i.reachable << endl;
        //}

        //cout << endl;
        long long mx = k;

        for (long long i = 0; i < n; i++) {
            if (casinos[i].reachable) {
                mx = max(casinos[i].real, mx);
                break;
            } 
        }

        cout << mx << endl;*/
    }
}