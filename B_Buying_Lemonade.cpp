#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<long long> slots(n);
        for (long long i = 0; i < n; i++) {
            cin >> slots[i];
        }

        sort(slots.begin(), slots.end());

        long long lemonade = 0;

        long long i = 0;
        long long moves = k;


        long long kn = 0;

        long long prev = 0;
        for (long long i = 0; i < n; i++) {
            if (kn+((slots[i]-prev)*(n-i)) >= k) {
                moves += i;
                break;
            } else {
                kn += (slots[i]-prev)*(n-i);
                prev = slots[i];
            }
        }

        /*
        while (lemonade < k) {
            if (lemonade + slots[i] >= k) {
                moves += (k-lemonade);
            } else {
                moves += slots[i]+1;
            }

            lemonade += slots[i];
            i++;
        }*/

        cout << moves << endl;
    }
}