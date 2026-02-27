#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n; cin >> n;

        vector<long long> nums(n);
        vector<long long> perms(n+1);

        vector<bool> found(n+1);
        map<int, int> count;
        

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];

            count[nums[i]]++;
        }

        sort(begin(nums), end(nums));

        for (long long i = 0; i < n; i++) {
            perms[nums[i]] = 1;
            found[nums[i]] = 1;
        }

        for (long long i = 0; i < n; i++) {
            long long x = nums[i];

            if (x == 1 || count[x]<2) continue;

            //cout << x << " " << count[x] << " ";
            while (x<=n) {
                x*=x;

                if (x>n) break;

                found[x] = true;

                if (perms[x / nums[i]]+1) perms[x] = min(perms[x / nums[i]]+1, perms[x]);
            }
        }

        
        for (long long i = 0; i < n; i++) {
            long long x = nums[i];

            for (long long j = 2; j <= n/x; j++) {
                if (x*j > n) break;
                if (x == j && count[j]<2) continue;

                if (found[j]) {
                    if (perms[x*j] == 0) perms[x*j] = 1e9;

                    //cout << x << " " << j << " ";
                    perms[x*j] = min(perms[x*j], perms[nums[i]]+perms[j]);

                    found[x*j] = true;
                } 
            }
        }

        for (long long i = 1; i <= n; i++) {
            cout << (perms[i] == 0 ? -1 : perms[i]) << " ";
        }

        cout << endl;
    }
}