#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, m, h; cin >> n >> m >> h;

        vector<pair<long long, long long>> nums(n);
        vector<long long> original(n);

        for (long long i = 0; i < n; i++) {
            cin >> nums[i].first;
            nums[i].second = 0;

            original[i] = nums[i].first;
        } 

        vector<pair<long long, long long>> op(m);
        for (long long i = 0; i < m; i++) {
            cin >> op[i].first >> op[i].second;

            op[i].first--;

        }

        long long glc = 0;

        for (long long i = 0; i < m; i++) {
            if (nums[op[i].first].second<glc) {
                nums[op[i].first].first = original[op[i].first];
                nums[op[i].first].second = glc;
            }

            nums[op[i].first].first += op[i].second;


            if (nums[op[i].first].first>h) {
                nums[op[i].first].first = original[op[i].first];
                
                glc++;
                nums[op[i].first].second = glc;
            }
        }

        for (long long i = 0; i < m; i++) {
            if (nums[op[i].first].second<glc) {
                nums[op[i].first].first = original[op[i].first];
                nums[op[i].first].second = glc;
            }
        }

        for (auto& i : nums) cout << i.first << " ";
        cout << endl;
    }
}