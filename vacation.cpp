#include <bits/stdc++.h>

using namespace std;

int plan_vacation(int N, std::vector<int> L, std::vector<int> R, long long K) {
    long long k = K;

    if (k == 1e18) {
        int minint = 1e9;

        for (int i = 0; i < N; i++) {
            minint = min(minint, R[i]-L[i]+1);
        }

        return minint;
    }
    if (k == 0) {
        int rl = 0, lr = 1e9;

        for (int i = 0; i < N; i++) {
            rl = max(rl, L[i]);
        }

        for (int j = 0; j < N; j++) {
            lr = min(lr, R[j]);
        }

        return max(lr-rl+1, 0);
    }
    if (k == 1) {
        int rl = 0, lr = 1e9;

        for (int i = 0; i < N; i++) {
            rl = max(rl, L[i]);
        }

        int leftmost = 0;
        for (int i = 0; i < N; i++) {
            if (L[i] == rl) {
                leftmost++;
            }
        }

        for (int j = 0; j < N; j++) {
            lr = min(lr, R[j]);
        }

        int rightmost = 0;
        for (int j = 0; j < N; j++) {
            if (R[j] == lr) rightmost++;
        }

        bool didl = 0;
        if (leftmost == 1) {
            for (int i = 0; i < N; i++) {
                if (L[i] == rl && R[i] != lr && L[i] > 1) { // GOES LEFT
                    didl = 1;
                    L[i]--;
                    R[i]--;
                    
                    break;
                }
            }
        }
        if (rightmost == 1 && !didl) {
            
            for (int i = 0; i < N; i++) {
                
                if (L[i] != rl && R[i] == lr && R[i] < 1e9) {
                    L[i]++;
                    R[i]++;
                    break;
                }
            }
        }

        
        rl = 0;
        lr = 1e9;
        for (int i = 0; i < N; i++) {
            rl = max(rl, L[i]);
        }

        for (int j = 0; j < N; j++) {
            lr = min(lr, R[j]);
        }

        int mx = max(lr-rl+1, 0);


        return mx;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long k; cin >> n>>k;

    vector<int> l(n), r(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    cout << plan_vacation(n, l, r, k);
}