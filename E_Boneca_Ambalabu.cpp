#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n; cin >> n;

        vector<bitset<32>> nums(n);

        for (int64_t i = 0; i < n; i++) {
            int64_t num; cin >> num;

            nums[i] = bitset<32>(num);
        }

        vector<int64_t> freq(32);

        for (int64_t i = 0; i < n; i++) {
            for (int64_t j = 0; j < 32; j++) {
                if (nums[i][j] == 1) freq[j]++;
            }
        }

        //for (auto& i : freq) cout << i << " ";

        //cout << endl;

        int64_t maxsum = 0;
        for (int64_t i = 0; i < n; i++) {
            int64_t sum = 0;

            for (int64_t j = 0; j <= 31; j++) {
                if (nums[i][j] == 0) {
                    sum += freq[j] * pow(2, j);
                } else {
                    sum += (n-freq[j]) * pow(2, j);
                }
            }

            maxsum = max(sum, maxsum);
        }

        cout << maxsum << endl;
    }
}