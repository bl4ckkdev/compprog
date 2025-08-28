#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n; cin >> n;

        if (n == 1) cout << "-1" << endl;
        else {
            int64_t sum = 0;

            for (int64_t i = 1; i <= n; i++) {
                sum+= i;
            }

            if (sum == int64_t(sqrt(sum))*sqrt(sum)) {
                cout << "-1" << endl;
                continue;
            }

            sum = 0;
            for (int64_t i = 1; i <= n; i++) {
                if (int64_t(sqrt(sum+i))*sqrt(sum+i) != sum+i) {
                    cout << i << " ";
                    sum += i;
                } else {
                    sum += i+1;
                    cout << i+1 << " " << i << " ";
                    sum += i;
                    i++;
                }
            }

            cout << endl;
        }
    }
}