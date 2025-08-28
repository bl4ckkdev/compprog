    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        long long n, k; cin >> n >> k;
     
        vector<long long> judge(n), rem(k);
     
        for (long long i = 0; i < n; i++) cin >> judge[i];
        for (long long i = 0; i < k; i++) cin >> rem[i];
     
     
        map<long long, long long> occ;

        long long sum = 0;

        for (long long i = 0; i < k; i++) {
            for (long long j = 0; j < n; j++) {
                sum += judge[j];

                occ[rem[i]-sum]++;
            }
        }
     
        long long cnt = 0;
     
        for (auto& i : occ) {
            if (i.second >= k) cnt++;
        }
     
        cout << cnt;
    }