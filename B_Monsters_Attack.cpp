#include <bits/stdc++.h>

using namespace std;

struct Enemy {
    long long health, pos;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;
        vector<Enemy> en(n);

        for (long long i = 0; i < n; i++) {
            cin >> en[i].health;
        }

        for (long long i = 0; i < n; i++) {
            cin >> en[i].pos;

            en[i].pos = abs(en[i].pos);
        }

        sort(en.begin(), en.end(), [](const Enemy& a, const Enemy& b){
            return a.pos < b.pos;
        });

        long long leftover = 0;
        long long offset = 0;

        long long shot = 0;

        bool cooked = false;

        for (int i = 0; i < n; ++i) {
            leftover += k - en[i].health;

            if (leftover < 0) {
                cooked = true;
                break;   
            }
        }

        cout << (!cooked ? "YES" : "NO") << endl;
    }
}